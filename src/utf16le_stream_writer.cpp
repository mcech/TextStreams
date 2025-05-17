#include "utf16le_stream_writer.h"

#include <stdexcept>  // std::invalid_argument

namespace
{
    const std::invalid_argument INVALID_CHARACTER("Invalid Unicode character");
}

void Utf16LeStreamWriter::write(char32_t c)
{
    if ((c <= 0xD7FF) || (c > 0xDFFF && c <= 0xFFFF))
    {
        out_.put(c & UINT8_MAX);
        out_.put(c >> 8);
    }
    else if (c >= 0x00010000 && c <= 0x0010FFFF)
    {
        uint32_t tmp  = c - 0x10000;
        uint16_t high = 0xD800 | (tmp >> 10);
        uint16_t low  = 0xDC00 | (tmp & 0x03FF);
        out_.put(high & UINT8_MAX);
        out_.put(high >> 8);
        out_.put(low & UINT8_MAX);
        out_.put(low >> 8);
    }
    else
    {
        // Codepoints 0xD800 to 0xDFFF are not assigned in Unicode. They are reserved to encode UTF-16.
        // Codepoints beyond 0x0010FFFF are not assigned in Unicode.
        throw INVALID_CHARACTER;
    }
}

Utf16LeStreamWriter::Utf16LeStreamWriter(std::ostream& out, LineEndings nl) : TextStreamWriter(nl), out_(out)
{
}
