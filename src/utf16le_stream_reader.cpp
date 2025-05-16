#include "utf16le_stream_reader.h"

#include <iostream>  // std::cerr, std::endl

char32_t Utf16LeStreamReader::advance()
{
    uint64_t pos = in_.tellg();

    if (in_.peek() == EOF)
    {
        return EOF;
    }

    char32_t result = in_.get();
    if (in_.peek() == EOF)
    {
        std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
        result = REPLACEMENT_CHAR;
        return result;
    }
    result |= (in_.get() << CHAR_BIT);

    if (result >= 0xD800 && result < 0xDBFF)
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
            low_surrogate |= (in_.get() << (i * CHAR_BIT));
        }
        if ((low_surrogate & 0xFFFF) < 0xDC00 || (low_surrogate & 0xFFFF) >= 0xDFFF)
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

Utf16LeStreamReader::Utf16LeStreamReader(std::istream& in) noexcept : in_(in)
{
}
