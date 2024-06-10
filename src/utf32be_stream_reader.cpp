#include "utf32be_stream_reader.h"

#include <iostream>

Utf32BeStreamReader::Utf32BeStreamReader(std::istream& fs) : fs_(fs)
{
}

char32_t Utf32BeStreamReader::peek()
{
    if (next_ == EOF)
    {
        advance();
    }
    return next_;
}

char32_t Utf32BeStreamReader::read()
{
    char32_t c = peek();
    next_ = EOF;
    return c;
}

void Utf32BeStreamReader::advance()
{
    if (next_ == EOF)
    {
        uint64_t pos = fs_.tellg();

        if (fs_.peek() == EOF)
        {
            next_ = EOF;
            return;
        }

        next_ = 0;
        for (int i = 0; i < 4; ++i)
        {
            if (fs_.peek() == EOF)
            {
                throw std::ios::failure("Invalid byte sequence at position " + std::to_string(fs_.tellg()));
            }
            next_ = (next_ << CHAR_BIT) | fs_.get();
        }
        if (next_ > 0x1FFFFF)
        {
            throw std::ios::failure("Invalid byte sequence at position " + std::to_string(fs_.tellg()));
        }
        if (next_ >= 0xD800 && next_ < 0xDFFF)
        {
            // 0xD800 to 0xDFFF not assigned in Unicode. They are reserved to encode UTF-16
            throw std::ios::failure("Invalid byte sequence at position " + std::to_string(fs_.tellg()));
        }
    }
}
