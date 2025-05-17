#include "utf8_stream_writer.h"

#include <stdexcept>  // std::invalid_argument

namespace
{
    const std::invalid_argument INVALID_CHARACTER("Invalid Unicode character");
}

void Utf8StreamWriter::write(char32_t c)
{
    if (c < 0x80)
    {
        out_.put(c);
    }
    else if (c < 0x0800)
    {
        out_.put(((c >>  6) & 0x3F) | 0xC0);
        out_.put(( c        & 0x3F) | 0x80);
    }
    else if (c >= 0xD800 && c <= 0xDFFF)
    {
        // Codepoints 0xD800 to 0xDFFF are not assigned in Unicode. They are reserved to encode UTF-16.
        throw INVALID_CHARACTER;
    }
    else if (c < 0x00010000)
    {
        out_.put(((c >> 12) & 0x3F) | 0xE0);
        out_.put(((c >>  6) & 0x3F) | 0x80);
        out_.put(( c        & 0x3F) | 0x80);
    }
    else if (c < 0x00110000)
    {
        out_.put(((c >> 18) & 0x3F) | 0xF0);
        out_.put(((c >> 12) & 0x3F) | 0x80);
        out_.put(((c >>  6) & 0x3F) | 0x80);
        out_.put(( c        & 0x3F) | 0x80);
    }
    else
    {
        // Codepoints beyond 0x0010FFFF are not assigned in Unicode.
        throw INVALID_CHARACTER;
    }
}

Utf8StreamWriter::Utf8StreamWriter(std::ostream& out, LineEndings nl) : TextStreamWriter(nl), out_(out)
{
}
