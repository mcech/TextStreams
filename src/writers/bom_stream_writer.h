#pragma once

#include "text_stream_writer.h"
#include <array>
#include <cstddef>
#include <cstdint>

template <class T, size_t N>
class BomStreamWriter : public T
{
public:
    BomStreamWriter() = delete;
    BomStreamWriter(std::ostream& out, LineEnding nl, const std::array<uint8_t, N>& bom);
    BomStreamWriter(const BomStreamWriter&) = delete;
    ~BomStreamWriter() override = default;
    BomStreamWriter& operator=(const BomStreamWriter&) = delete;
};

template <class T, size_t N>
inline BomStreamWriter<T, N>::BomStreamWriter(std::ostream& out, LineEnding nl, const std::array<uint8_t, N>& bom) : T(out, nl)
{
    for (uint8_t c : bom)
    {
        out.put(c);
    }
}
