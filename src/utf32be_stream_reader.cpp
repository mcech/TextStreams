#include "utf32be_stream_reader.h"

#include <iostream>

Utf32BeStreamReader::Utf32BeStreamReader(std::istream& fs) : fs_(fs)
{
}

char32_t Utf32BeStreamReader::peek()
{
    std::streampos pos = fs_.tellg();
    char32_t c = read();
    fs_.seekg(pos);
    return c;
}

char32_t Utf32BeStreamReader::read()
{
    if (fs_.peek() == EOF)
    {
        return EOF;
    }
    else
    {
        uint64_t pos = fs_.tellg();
        int32_t c = 0;
        for (int i = 0; i < 4; ++i)
        {
            if (fs_.peek() == EOF)
            {
                std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
                return REPLACEMENT_CHAR;
            }
            c = (c << CHAR_BIT) | fs_.get();
        }
        if (c > 0x1FFFFF)
        {
            std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
            return REPLACEMENT_CHAR;
        }
        if (c >= 0xD800 && c < 0xDFFF)
        {
            // 0xD800 to 0xDFFF are forbidden in Unicode. They are reserved to encode UTF-16
            std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
            return REPLACEMENT_CHAR;       
        }
        return c;
    }
}
