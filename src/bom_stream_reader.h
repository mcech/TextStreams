#pragma once

#include "text_stream_reader.h"
#include <ios>
#include <vector>
#include <cstddef>

template <class T>
class BomStreamReader : public T
{
protected:
    friend class TextStreamReader;

    BomStreamReader(std::istream& fs, const std::vector<uint8_t>& bom);
};

template <class T>
inline BomStreamReader<T>::BomStreamReader(std::istream& fs, const std::vector<uint8_t>& bom) : T(fs)
{
    std::vector<uint8_t> prefix;
    for (int i = 0; i < bom.size(); ++i)
    {
        int32_t c = T::fs_.get();
        if (c == EOF)
        {
            throw std::ios::failure("Invalid byte order mark");
        }
        prefix.push_back(c);
    }
    if (prefix != bom)
    {
        throw std::ios::failure("Invalid byte order mark");
    }
}
