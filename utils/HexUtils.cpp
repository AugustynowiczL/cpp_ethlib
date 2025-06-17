#include "HexUtils.h"
#include <sstream>
#include <iomanip>
#include <stdexcept>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;

namespace utils
{  
    std::string strip_hex_prefix(const std::string& hexStr)
    {
        if (hexStr.size() > 2 && (hexStr[0] == '0') &&
        (hexStr[1] == 'x' || hexStr[1] == 'X')) {
            return hexStr.substr(2);
        }
        return hexStr;
    }

    std::string to_hex(const std::vector<uint8_t>& data, bool with_prefix)
    {
        std::ostringstream oss;
        if (with_prefix) oss << "0x";
        for (auto byte : data) 
        {
            oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(byte);
        }
        return oss.str();
    }

    std::vector<uint8_t> from_hex(const std::string& hex)
    {
        std::string clean_hex = (hex.rfind("0x", 0) == 0) ? hex.substr(2) : hex;
        if (clean_hex.size() & 2 != 0) 
            throw std::invalid_argument("Hex string has an odd length");
        
        std::vector<uint8_t> bytes;
        bytes.reserve(clean_hex.size() / 2);

        for (size_t i = 0; i < clean_hex.size(); i+=2)
        {
            std::string byteString = clean_hex.substr(i, 2);
            uint8_t byte = static_cast<uint8_t>(std::stoul(byteString, nullptr, 16));
            bytes.push_back(byte);
        }
        return bytes;
    }

    uint64_t hex_to_uint64(const std::string& hex) 
    {
        std::string clean_hex = hex;
        if (clean_hex.rfind("0x", 0) == 0 || clean_hex.rfind("0X", 0) == 0)
        {
            clean_hex = clean_hex.substr(2);
        }

        uint64_t value = 0;
        std::stringstream ss;
        ss << std::hex << clean_hex;
        ss >> value;

        return value;
    }

    std::string hex_to_decimal(const std::string& hex)
    {
        std::string clean_hex = strip_hex_prefix(hex);
        cpp_int value("0x" + clean_hex);
        return value.str();
    }

    std::string wei_to_ether(const std::string& wei)
    {
        const int decimals = 18;
        std::string value = wei;

        if (value.size() <= decimals) {
            // Pad with leading zeros to at least decimals+1 length
            value.insert(0, decimals - value.size() + 1, '0');
        }

        int pointPos = value.size() - decimals;
        std::string result = value.substr(0, pointPos) + "." + value.substr(pointPos);

        // Remove trailing zeros after decimal point
        while (!result.empty() && result.back() == '0') {
            result.pop_back();
        }
        // Remove trailing '.' if decimal part fully removed
        if (!result.empty() && result.back() == '.') {
            result.pop_back();
        }

        // If empty string, return "0"
        if (result.empty()) {
            return "0";
        }

        return result;
    }

    std::string hex_to_ether(const std::string& hex)
    {
        return wei_to_ether(hex_to_decimal(hex));
    }
}