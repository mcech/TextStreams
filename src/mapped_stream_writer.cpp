#include "mapped_stream_writer.h"

#include "transliterations.h"
#include <ios>       // std::ios::failure
#include <iostream>  // std::cerr, std::endl
#include <cstring>   // strlen

void MappedStreamWriter::write(char32_t c)
{
    uint64_t pos = out_.tellp();
    if (unicode_mapping_.contains(c))
    {
        out_.put(unicode_mapping_.at(c));
    }
    else if (transliterations.contains(c))
    {
        std::cerr << "Warning: invalid character at position " << pos << std::endl;
        const char* replacement = transliterations.at(c);
        out_.write(replacement, strlen(replacement));
    }
    else
    {
        std::cerr << "Warning: invalid character at position " << pos << std::endl;
        out_.put(REPLACEMENT_CHAR);
    }
}

MappedStreamWriter::MappedStreamWriter(std::ostream& out, const std::unordered_map<char32_t, uint8_t>& unicode_mapping, LineEndings nl) : TextStreamWriter(nl), out_(out), unicode_mapping_(unicode_mapping)
{
}
