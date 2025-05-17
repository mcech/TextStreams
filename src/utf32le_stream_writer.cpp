#include "utf32le_stream_writer.h"

#include <stdexcept>  // std::invalid_argument

namespace
{
    const std::invalid_argument INVALID_CHARACTER("Invalid Unicode character");
}

void Utf32LeStreamWriter::write(char32_t c)
{
    if (c >= 0xD800 && c <= 0xDFFF)
    {
        // Codepoints 0xD800 to 0xDFFF are not assigned in Unicode. They are reserved to encode UTF-16.
        throw INVALID_CHARACTER;
    }
    else if (c > 0x0010FFFF)
    {
        // Codepoints 0xD800 to 0xDFFF are not assigned in Unicode. They are reserved to encode UTF-16.
        throw INVALID_CHARACTER;
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            out_.put(c & UINT8_MAX);
            c >>= 8;
        }
    }
}

Utf32LeStreamWriter::Utf32LeStreamWriter(std::ostream& out, LineEndings nl) : TextStreamWriter(nl), out_(out)
{
}
