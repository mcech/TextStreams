#include "utf32be_stream_reader.h"

#include <iostream>  // std::cerr, std::endl

char32_t Utf32BeStreamReader::advance()
{
    uint64_t pos = in_.tellg();

    if (in_.peek() == EOF)
    {
        return EOF;
    }

    char32_t result = 0;
    for (int i = 0; i < 4; ++i)
    {
        if (in_.peek() == EOF)
        {
            std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
            result = REPLACEMENT_CHAR;
            return result;
        }
        result = (result << CHAR_BIT) | in_.get();
    }
    if (result >= 0xD800 && result <= 0xDFFF)
    {
        // 0xD800 to 0xDFFF not assigned in Unicode. They are reserved to encode UTF-16.
        std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
        result = REPLACEMENT_CHAR;
    }
    else if (result > 0x0010FFFF)
    {
        std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
        result = REPLACEMENT_CHAR;
    }
    return result;
}

Utf32BeStreamReader::Utf32BeStreamReader(std::istream& in) noexcept : in_(in)
{
}
