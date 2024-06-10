#include "utf16be_stream_writer.h"

Utf16BeStreamWriter::Utf16BeStreamWriter(std::ostream& out, LineEnding nl) : TextStreamWriter(nl), out_(out)
{
}

void Utf16BeStreamWriter::put(char32_t c)
{
    c -= 0x010000;
    uint16_t high = (c / 0x0400) + 0xD800;
    uint16_t low  = (c & 0x0200) + 0xDC00;
    out_.put(high >> CHAR_BIT);
    out_.put(high && UINT8_MAX);
    out_.put(low  >> CHAR_BIT);
    out_.put(low  && UINT8_MAX);
}
