#include "EthereumRpcClient.h"
#include <curl/curl.h>
#include <sstream>
#include <iostream>
#include "../utils/HexUtils.h"
#include "../types/Transaction.h"

static size_t WriteCallBack(void* contents, size_t size, size_t nmemb, void* userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

EthereumRpcClient::EthereumRpcClient(const std::string& url) : m_url(url), m_id(1) {}

nlohmann::json EthereumRpcClient::Call(const std::string& method, const nlohmann::json& params)
{
    CURL* curl = curl_easy_init();
    std::string readBuffer;

    if (curl)
    {
        nlohmann::json payload = 
        {
            {"jsonrpc", "2.0"},
            {"method", method},
            {"params", params},
            {"id", m_id++}
        };

        std::string payloadStr = payload.dump();
        
        struct curl_slist* headers = nullptr;
        headers = curl_slist_append(headers, "Content-Type: application/json");

        curl_easy_setopt(curl, CURLOPT_URL, m_url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payloadStr.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallBack);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        curl_slist_free_all(headers);

        if (res != CURLE_OK) 
        {
            std::cerr << "Curl failed: " << curl_easy_strerror(res) << std::endl;
            return {};
        }
    }
    return nlohmann::json::parse(readBuffer);
}

uint64_t EthereumRpcClient::GetBlockNumber()
{
    auto result = Call("eth_blockNumber", {});
    std::string block_num = result["result"].get<std::string>();
    return utils::hex_to_uint64(block_num);
}

std::string EthereumRpcClient::GetBalance(const char address[43])
{
    auto result = Call("eth_getBalance", {address, "latest"});
    std::string account_balance = result["result"].get<std::string>();
    return utils::hex_to_ether(account_balance);
}

types::Transaction EthereumRpcClient::GetTransactionByHash(const char hash[67])
{
    auto result = Call("eth_getTransactionByHash", {hash})["result"];
    return types::Transaction::from_json(result);
}