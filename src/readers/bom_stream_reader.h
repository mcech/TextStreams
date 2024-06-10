#pragma once

#include "text_stream_reader.h"
#include <array>
#include <cstddef>

template <class T, size_t N>
class BomStreamReader : public T
{
public:
    BomStreamReader() = delete;
    BomStreamReader(std::istream& in, const std::array<uint8_t, N>& bom);
    BomStreamReader(const BomStreamReader&) = delete;
    ~BomStreamReader() override = default;
    BomStreamReader& operator=(const BomStreamReader&) = delete;
};

template <class T, size_t N>
inline BomStreamReader<T, N>::BomStreamReader(std::istream& in, const std::array<uint8_t, N>& bom) : T(in)
{
    std::array<uint8_t, N> prefix;
    for (int32_t i = 0; i < bom.size(); ++i)
    {
        int32_t c = in.get();
        if (c == EOF)
        {
            throw std::ios::failure("Invalid byte order mark");
        }
        prefix[i] = c;
    }
    if (prefix != bom)
    {
        throw std::ios::failure("Invalid byte order mark");
    }
}
