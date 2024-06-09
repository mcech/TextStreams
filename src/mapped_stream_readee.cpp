#include "mapped_stream_reader.h"

#include <iostream>
#include <unordered_map>

char32_t MappedStreamReader::peek()
{

    if (next_ >= 0x7F)
    {
        if (unicode_mapping_.contains(next_))
        {
            return unicode_mapping_.at(next_);
        }
        else
        {
            throw std::ios::failure("Warning: invalid byte sequence at position " + std::to_string(fs_.tellg()));
        }
    }

    return next_;
}

char32_t MappedStreamReader::read()
{
    char32_t c = peek();
    advance();
    return c;
}

MappedStreamReader::MappedStreamReader(std::istream& fs, const std::unordered_map<int32_t, char32_t>& unicode_mapping) : fs_(fs), unicode_mapping_(unicode_mapping)
{
    advance();
}

void MappedStreamReader::advance()
{
    next_ = fs_.get();
}
