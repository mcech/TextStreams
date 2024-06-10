#include "utf8_stream_reader.h"

#include <bit>
#include <stdexcept>

Utf8StreamReader::Utf8StreamReader(std::istream& in) : in_(in)
{
}

char32_t Utf8StreamReader::get()
{
    uint64_t pos = in_.tellg();

    if (in_.peek() == EOF)
    {
        return EOF;
    }

    int32_t c = in_.get();
    int32_t leading = std::countl_one<uint8_t>(c);
    if (leading == 0)
    {
        return c;
    }
    else if (leading == 1 || leading > 4)
    {
        throw std::ios::failure("Invalid byte sequence at position " + std::to_string(in_.tellg()));
    }

    c = static_cast<uint8_t>(c << leading) >> leading;
    for (int32_t i = 1; i < leading; ++i)
    {
        int32_t b = in_.get();
        if (b == EOF || (b & 0x80) == 0 || (b & 0x40) != 0)
        {
            throw std::ios::failure("Invalid byte sequence at position " + std::to_string(in_.tellg()));
        }
        c = (c << 6) | (b & 0x3F);
    }

    if (c >= 0xD800 && c < 0xDFFF)
    {
        // 0xD800 to 0xDFFF not assigned in Unicode. They are reserved to encode UTF-16
        throw std::ios::failure("Invalid byte sequence at position " + std::to_string(in_.tellg()));
    }
    else if (c > 0x10FFFF)
    {
        // Unicode ends at 0x10FFFF as larger values cannot be encoded in UTF-16.
        throw std::ios::failure("Invalid byte sequence at position " + std::to_string(in_.tellg()));
    }

    return c;
}
