#include "utf8_stream_reader.h"

#include <bit>
#include <iostream>

Utf8StreamReader::Utf8StreamReader(std::istream& fs) : fs_(fs)
{
}

char32_t Utf8StreamReader::peek()
{
    if (next_ == EOF)
    {
        advance();
    }
    return next_;
}

char32_t Utf8StreamReader::read()
{
    char32_t c = peek();
    next_ = EOF;
    return c;
}

void Utf8StreamReader::advance()
{
    if (next_ == EOF)
    {
        uint64_t pos = fs_.tellg();

        int32_t b = fs_.get();
        if (b == EOF)
        {
            next_ = EOF;
            return;
        }

        int leading = std::countl_one<uint8_t>(b);
        if (leading == 0)
        {
            next_ = b;
        }
        else if (leading == 1 || leading > 4)
        {
            throw std::ios::failure("Invalid byte sequence at position " + std::to_string(fs_.tellg()));
        }
        else
        {
            int32_t c = static_cast<uint8_t>(b << leading) >> leading;
            for (int i = 1; i < leading; ++i)
            {
                b = fs_.get();
                if (b == EOF || (b & 0x80) == 0 || (b & 0x40) != 0)
                {
                    throw std::ios::failure("Invalid byte sequence at position " + std::to_string(fs_.tellg()));
                    next_ = REPLACEMENT_CHAR;
                    return;
                }
                c = (c << 6) | (b & 0x3F);
            }
            if (c >= 0xD800 && c < 0xDFFF)
            {
                // 0xD800 to 0xDFFF not assigned in Unicode. They are reserved to encode UTF-16
                throw std::ios::failure("Invalid byte sequence at position " + std::to_string(fs_.tellg()));
                next_ = REPLACEMENT_CHAR;
            }
            else
            {
                next_ = c;
            }
        }
    }
}
