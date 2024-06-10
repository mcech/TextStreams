#include "utf8_stream_writer.h"

Utf8StreamWriter::Utf8StreamWriter(std::ostream& out, LineEnding nl) : TextStreamWriter(nl), out_(out)
{
}

void Utf8StreamWriter::put(char32_t c)
{
    if (c <= 0x7F)
    {
        out_.put(c);
    }
    else if (c <= 0x07FF)
    {
        out_.put(0xC0 | (c >> 6));
        out_.put(0x80 | (c & 0x3F));
    }
    else if (c < 0xFFFF)
    {
        out_.put(0xE0 | (c >> 12));
        out_.put(0x80 | ((c >> 6) & 0x3F));
        out_.put(0x80 | (c & 0x3F));
    }
    else
    {
        out_.put(0xF0 | (c >> 18));
        out_.put(0x80 | ((c >> 12) & 0x3F));
        out_.put(0x80 | ((c >> 6) & 0x3F));
        out_.put(0x80 | (c & 0x3F));
    }
}
