#pragma once

#include <string>
#include <optional>
#include <cstdint>
#include "nlohmann/json.hpp"

namespace types {
    class Transaction {
    public:
        // Hashes
        std::string blockHash;    
        std::string blockNumber;    

        std::string from;                        
        std::string gas;
        std::string gasPrice;
        std::string hash;                        
        std::string input;                      
        std::string nonce;
        std::string to;           
        std::string transactionIndex;

        std::string value;
        std::string v;
        std::string r;
        std::string s;

        Transaction() = default;

        static Transaction from_json(const nlohmann::json& json);
    };
}