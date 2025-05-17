#include "utf8_stream_reader.h"

#include <iostream>  // std::cerr, std::endl

char32_t Utf8StreamReader::advance()
{
    uint64_t pos = in_.tellg();

    char32_t result = in_.peek();
    if (result != static_cast<char32_t>(EOF))
    {
        if ((result & 0x80) == 0)
        {
            result = in_.get();
        }
        else if ((result & 0xE0) == 0xC0)
        {
            result = read_composed(0x1F, 1);
        }
        else if ((result & 0xF0) == 0xE0)
        {
            result = read_composed(0x0F, 2);
        }
        else if ((result & 0xF8) == 0xF0)
        {
            result = read_composed(0x07, 3);
        }
        else
        {
            in_.get();
            std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
            result = REPLACEMENT_CHAR;
        }

        if (result >= 0xD800 && result <= 0xDFFF)
        {
            // Codepoints 0xD800 to 0xDFFF are not assigned in Unicode. They are reserved to encode UTF-16.
            std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
            result = REPLACEMENT_CHAR;
        }
        else if (result > 0x0010FFFF)
        {
            // Codepoints beyond 0x0010FFFF are not assigned in Unicode.
            std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
            result = REPLACEMENT_CHAR;
        }
    }

    return result;
}

Utf8StreamReader::Utf8StreamReader(std::istream& in) noexcept : in_(in)
{
}

char32_t Utf8StreamReader::read_composed(uint8_t prefix, size_t consecutives)
{
    uint64_t pos = in_.tellg();
    int32_t b = in_.get();
    char32_t result = b & prefix;
    for (size_t i = 0; i < consecutives; ++i)
    {
        b = in_.get();
        if ((b & 0xC0) == 0x80)
        {
            result = (result << 6) | (b & 0x3F);
        }
        else
        {
            std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
            result = REPLACEMENT_CHAR;
            break;
        }
    }
    return result;
}
