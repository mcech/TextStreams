#include "Utf16le_stream_reader.h"

#include <iostream>

Utf16LeStreamReader::Utf16LeStreamReader(std::istream& fs) : fs_(fs)
{
}

char32_t Utf16LeStreamReader::peek()
{
    if (next_ == EOF)
    {
        advance();
    }
    return next_;
}

char32_t Utf16LeStreamReader::read()
{
    char32_t c = peek();
    next_ = EOF;
    return c;
}

void Utf16LeStreamReader::advance()
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
        for (int i = 0; i < 2; ++i)
        {
            if (fs_.peek() == EOF)
            {
                throw std::ios::failure("Invalid byte sequence at position " + std::to_string(fs_.tellg()));
            }
            next_ |= fs_.get() << (i * CHAR_BIT);
        }
        if (next_ >= 0xD800 && next_ < 0xBFFF)
        {
            next_ = (next_ & 0x03FF) << 10;
            for (int i = 0; i < 2; ++i)
            {
                if (fs_.peek() == EOF)
                {
                    throw std::ios::failure("Invalid byte sequence at position " + std::to_string(fs_.tellg()));
                }
                next_ |= fs_.get() << (i * CHAR_BIT);
            }
            if ((next_ & 0xFFFF) < 0xDC00 || (next_ & 0xFFFF) >= 0xDFFF)
            {
                throw std::ios::failure("Invalid byte sequence at position " + std::to_string(fs_.tellg()));
            }
            next_ = (next_ & 0xFFFF03FF) + 0x10000;
        }
        else if (next_ >= 0xDC00 && next_ < 0xDFFF)
        {
            throw std::ios::failure("Invalid byte sequence at position " + std::to_string(fs_.tellg()));
        }
    }
}
