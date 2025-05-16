#pragma once

#include "text_stream_reader.h"
#include <unordered_map>  // std::unordered_map
#include <cstdio>         // EOF

class MappedStreamReader : public TextStreamReader
{
public:
    MappedStreamReader() = delete;
    MappedStreamReader(const MappedStreamReader&) = delete;
    ~MappedStreamReader() override = default;
    MappedStreamReader& operator=(const MappedStreamReader&) = delete;

protected:
    char32_t advance() override;

private:
    friend class TextStreamReader;

    MappedStreamReader(std::istream& in, const std::unordered_map<int, char32_t>& unicode_mapping) noexcept;

    std::istream& in_;
    const std::unordered_map<int, char32_t>& unicode_mapping_;
};
