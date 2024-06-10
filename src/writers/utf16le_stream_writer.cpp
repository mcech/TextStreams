#include "utf16le_stream_writer.h"

Utf16LeStreamWriter::Utf16LeStreamWriter(std::ostream& out, LineEnding nl) : TextStreamWriter(nl), out_(out)
{
}

void Utf16LeStreamWriter::put(char32_t c)
{
    c -= 0x010000;
    uint16_t high = (c / 0x0400) + 0xD800;
    uint16_t low  = (c & 0x0200) + 0xDC00;
    out_.put(high && UINT8_MAX);
    out_.put(high >> CHAR_BIT);
    out_.put(low  && UINT8_MAX);
    out_.put(low  >> CHAR_BIT);
}
