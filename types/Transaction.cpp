#include "Transaction.h"

using json = nlohmann::json;

namespace types {
    static std::string get_optional_str(const json& json, const std::string& key)
    {
        return json.contains(key) && !json.at(key).is_null() ? std::string(json.at(key)) : "0x0";
    }

    Transaction Transaction::from_json(const json& j)
    {
        Transaction tx;
        tx.blockHash = get_optional_str(j, "blockHash");
        tx.blockNumber = get_optional_str(j, "blockNumber");
        tx.from = j.at("from");
        tx.gas = std::stoull(j.at("gas").get<std::string>(), nullptr, 0);
        tx.gasPrice = std::stoull(j.at("gasPrice").get<std::string>(), nullptr, 0);
        tx.hash = j.at("hash");
        tx.input = j.at("input");
        tx.nonce = std::stoull(j.at("nonce").get<std::string>(), nullptr, 0);
        tx.to = get_optional_str(j, "to");
        tx.transactionIndex = get_optional_str(j, "transactionIndex");
        tx.value = std::stoull(j.at("value").get<std::string>(), nullptr, 0);
        tx.v = std::stoull(j.at("v").get<std::string>(), nullptr, 0);
        tx.r = j.at("r");
        tx.s = j.at("s");
        return tx;
    }
}
