#pragma once

#include <array>
#include <cstdint>

namespace ByteOrderMark
{
    static constexpr std::array<uint8_t, 3> BOM_UTF8     = {0xEF, 0xBB, 0xBF};
    static constexpr std::array<uint8_t, 2> BOM_UTF16_LE = {0xFF, 0xFE};
    static constexpr std::array<uint8_t, 2> BOM_UTF16_BE = {0xFE, 0xFF};
    static constexpr std::array<uint8_t, 4> BOM_UTF32_LE = {0xFF, 0xFE, 0x00, 0x00};
    static constexpr std::array<uint8_t, 4> BOM_UTF32_BE = {0x00, 0x00, 0xFE, 0xFF};
};
