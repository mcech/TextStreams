#include "mapped_stream_reader.h"

#include <stdexcept>

MappedStreamReader::MappedStreamReader(std::istream& in, const std::unordered_map<int32_t, char32_t>& unicode_mapping) : in_(in), unicode_mapping_(unicode_mapping)
{
}

char32_t MappedStreamReader::get()
{
    int32_t c = in_.get();

    if (c >= 0x7F)
    {
        if (unicode_mapping_.contains(c))
        {
            c = unicode_mapping_.at(c);
        }
        else
        {
            throw std::ios::failure("Invalid byte sequence at position " + std::to_string(in_.tellg()));
        }
    }

    return c;
}
