#pragma once
#include <string>
#include <vector>
#include <stdint.h>

namespace utils
{
    std::string strip_hex_prefix(const std::string& hex);
    std::string to_hex(const std::vector<uint8_t>&data, bool with_prefix = true);
    std::vector<uint8_t> from_hex(const std::string& hex);
    uint64_t hex_to_uint64(const std::string& hex);
    std::string hex_to_decimal(const std::string& hex);
    std::string wei_to_ether(const std::string& wei);
    std::string hex_to_ether(const std::string& hex);
}