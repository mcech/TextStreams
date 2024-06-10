#include "utf32le_stream_writer.h"

Utf32LeStreamWriter::Utf32LeStreamWriter(std::ostream& out, LineEnding nl) : TextStreamWriter(nl), out_(out)
{
}

void Utf32LeStreamWriter::put(char32_t c)
{
    for (int32_t i = 3; i >= 0; --i)
    {
        out_.put(c & UINT8_MAX);
        c >>= CHAR_BIT;
    }
}
