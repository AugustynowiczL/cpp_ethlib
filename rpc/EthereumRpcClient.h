#pragma once

#include <string>
#include "nlohmann/json.hpp"
#include "../types/Transaction.h"

class EthereumRpcClient {

public:
    EthereumRpcClient(const std::string& url);

    nlohmann::json Call(const std::string& method, const nlohmann::json& params);
    uint64_t GetBlockNumber();
    std::string GetBalance(const char address[43]);
    types::Transaction GetTransactionByHash(const char address[43]);

private:
    std::string m_url;
    int m_id;
};
