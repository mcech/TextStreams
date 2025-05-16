#include "mapped_stream_reader.h"

#include <ios>       // std::ios::failure
#include <iostream>  // std::cerr, std::endl

char32_t MappedStreamReader::advance()
{
    uint64_t pos = in_.tellg();

    char32_t result = in_.get();
    if (result != static_cast<char32_t>(EOF))
    {
        if (unicode_mapping_.contains(result))
        {
            result = unicode_mapping_.at(result);
        }
        else
        {
            std::cerr << "Warning: invalid byte sequence at position " << pos << std::endl;
            result = REPLACEMENT_CHAR;
        }
    }
    return result;
}

MappedStreamReader::MappedStreamReader(std::istream& in, const std::unordered_map<int, char32_t>& unicode_mapping) noexcept : in_(in), unicode_mapping_(unicode_mapping)
{
}
