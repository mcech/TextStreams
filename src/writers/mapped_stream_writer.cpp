#include "mapped_stream_writer.h"

#include <stdexcept>

MappedStreamWriter::MappedStreamWriter(std::ostream& out, const std::unordered_map<int32_t, char32_t>& unicode_mapping, LineEnding nl) : TextStreamWriter(nl), out_(out), unicode_mapping_(unicode_mapping)
{
}

void MappedStreamWriter::put(char32_t c)
{
    if (c >= 0x7F)
    {
        if (unicode_mapping_.contains(c))
        {
            c = unicode_mapping_.at(c);
        }
        else
        {
            throw std::ios::failure("Invalid codepoint");
        }
    }
    out_.put(c);
}
