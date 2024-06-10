#include "utf16be_stream_reader.h"

#include <stdexcept>

Utf16BeStreamReader::Utf16BeStreamReader(std::istream& in) : in_(in)
{
}

char32_t Utf16BeStreamReader::get()
{
    uint64_t pos = in_.tellg();

    if (in_.peek() == EOF)
    {
        return EOF;
    }

    int32_t high = 0;
    for (int32_t i = 0; i < 2; ++i)
    {
        if (in_.peek() == EOF)
        {
            throw std::ios::failure("Invalid byte sequence at position " + std::to_string(in_.tellg()));
        }
        high = (high << CHAR_BIT) | in_.get();
    }

    if (high >= 0xD800 && high < 0xDBFF)
    {
        int32_t low = 0;
        for (int32_t i = 0; i < 2; ++i)
        {
            if (in_.peek() == EOF)
            {
                throw std::ios::failure("Invalid byte sequence at position " + std::to_string(in_.tellg()));
            }
            low = (low << CHAR_BIT) | in_.get();
        }

        if (low < 0xDC00 || low >= 0xDFFF)
        {
            throw std::ios::failure("Invalid byte sequence at position " + std::to_string(in_.tellg()));
        }

        return 0x010000 + (high - 0xD800) * 0x0400 + (low - 0xDC00);
    }
    else if (high >= 0xDC00 && high < 0xDFFF)
    {
        throw std::ios::failure("Invalid byte sequence at position " + std::to_string(in_.tellg()));
    }
    else
    {
        return high;
    }
}
