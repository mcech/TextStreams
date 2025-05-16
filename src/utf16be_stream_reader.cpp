#include "utf16be_stream_reader.h"

#include <iostream>  // std::cerr, std::endl

char32_t Utf16BeStreamReader::advance()
{
    uint64_t pos = in_.tellg();

    if (in_.peek() == EOF)
    {
        return EOF;
    }

    char32_t result = in_.get() << CHAR_BIT;
    if (in_.peek() == EOF)
    {
        std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
        result = REPLACEMENT_CHAR;
        return result;
    }
    result |= in_.get();

    if (result >= 0xD800 && result <= 0xDBFF)
    {
        uint32_t high_surrogate = result;
        uint32_t low_surrogate  = 0;
        for (int i = 0; i < 2; ++i)
        {
            if (in_.peek() == EOF)
            {
                std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
                result = REPLACEMENT_CHAR;
                return result;
            }
            low_surrogate = (low_surrogate << CHAR_BIT) | in_.get();
        }
        if (low_surrogate < 0xDC00 || low_surrogate > 0xDFFF)
        {
            std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
            result = REPLACEMENT_CHAR;
        }
        else
        {
            high_surrogate &= 0x03FF;
            low_surrogate  &= 0x03FF;
            result = (high_surrogate << 10) + low_surrogate + 0x10000;
        }
    }
    return result;
}

Utf16BeStreamReader::Utf16BeStreamReader(std::istream& in) noexcept : in_(in)
{
}
