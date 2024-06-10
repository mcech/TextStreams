#include "utf32le_stream_reader.h"

#include <stdexcept>

Utf32LeStreamReader::Utf32LeStreamReader(std::istream& in) : in_(in)
{
}

char32_t Utf32LeStreamReader::get()
{
    uint64_t pos = in_.tellg();

    if (in_.peek() == EOF)
    {
        return EOF;
    }

    int32_t c = 0;
    for (int32_t i = 0; i < 4; ++i)
    {
        if (in_.peek() == EOF)
        {
            throw std::ios::failure("Invalid byte sequence at position " + std::to_string(in_.tellg()));
        }
        c |= in_.get() << (i * CHAR_BIT);
    }

    if (c >= 0xD800 && c < 0xDFFF)
    {
        // 0xD800 to 0xDFFF not assigned in Unicode. They are reserved to encode UTF-16
        throw std::ios::failure("Invalid byte sequence at position " + std::to_string(in_.tellg()));
    }
    else if (c > 0x10FFFF)
    {
        // Unicode ends at 0x10FFFF as larger values cannot be encoded in UTF-16.
        throw std::ios::failure("Invalid byte sequence at position " + std::to_string(in_.tellg()));
    }
}
