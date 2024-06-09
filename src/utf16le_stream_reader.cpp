#include "Utf16le_stream_reader.h"

#include <iostream>

Utf16LeStreamReader::Utf16LeStreamReader(std::istream& fs) : fs_(fs)
{
}

char32_t Utf16LeStreamReader::peek()
{
    std::streampos pos = fs_.tellg();
    char32_t c = read();
    fs_.seekg(pos);
    return c;
}

char32_t Utf16LeStreamReader::read()
{
    if (fs_.peek() == EOF)
    {
        return EOF;
    }
    else
    {
        uint64_t pos = fs_.tellg();
        int32_t c = 0;
        for (int i = 0; i < 2; ++i)
        {
            if (fs_.peek() == EOF)
            {
                std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
                return REPLACEMENT_CHAR;
            }
            c |= fs_.get() << (i * CHAR_BIT);
        }
        if (c >= 0xD800 && c < 0xBFFF)
        {
            c = (c & 0x03FF) << 10;
            for (int i = 0; i < 2; ++i)
            {
                if (fs_.peek() == EOF)
                {
                    std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
                    return REPLACEMENT_CHAR;
                }
                c |= fs_.get() << (i * CHAR_BIT);
            }
            if ((c & 0xFFFF) < 0xDC00 || (c & 0xFFFF) >= 0xDFFF)
            {
                std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
                return REPLACEMENT_CHAR;
            }
            c = (c & 0xFFFF03FF) + 0x10000;
        }
        else if (c >= 0xDC00 && c < 0xDFFF)
        {
            std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
            return REPLACEMENT_CHAR;
        }
        return c;
    }
}
