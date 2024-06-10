#include "utf32be_stream_writer.h"

Utf32BeStreamWriter::Utf32BeStreamWriter(std::ostream& out, LineEnding nl) : TextStreamWriter(nl), out_(out)
{
}

void Utf32BeStreamWriter::put(char32_t c)
{
    for (int32_t i = 3; i >= 0; --i)
    {
        out_.put(c >> (i * CHAR_BIT));
    }
}
