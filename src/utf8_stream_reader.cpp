#include "utf8_stream_reader.h"

#include <bit>
#include <iostream>


Utf8StreamReader::Utf8StreamReader(std::istream& fs) : fs_(fs)
{
}

char32_t Utf8StreamReader::peek()
{
    std::streampos pos = fs_.tellg();
    char32_t c = read();
    fs_.seekg(pos);
    return c;
}

char32_t Utf8StreamReader::read()
{
    uint64_t pos = fs_.tellg();
    int32_t b = fs_.get();
    if (b == EOF)
    {
        return EOF;
    }
    else
    {
        int leading = std::countl_one<uint8_t>(b);
        if (leading == 0)
        {
            return b;
        }
        else if (leading == 1 || leading > 4)
        {
            std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
            return REPLACEMENT_CHAR;
        }
        else
        {
            int32_t c = static_cast<uint8_t>(b << leading) >> leading;
            for (int i = 1; i < leading; ++i)
            {
                b = fs_.get();
                if (b == EOF || (b & 0x80) == 0 || (b & 0x40) != 0)
                {
                    std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
                    return REPLACEMENT_CHAR;
                }
                c = (c << 6) | (b & 0x3F);
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
}
