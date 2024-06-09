#pragma once

#include "text_stream_reader.h"
#include <unordered_map>

class MappedStreamReader : public TextStreamReader
{
public:
    MappedStreamReader() = delete;
    MappedStreamReader(const MappedStreamReader&) = delete;
    ~MappedStreamReader() override = default;
    MappedStreamReader& operator=(const MappedStreamReader&) = delete;

    char32_t peek() override;
    char32_t read() override;

private:
    friend class TextStreamReader;

    MappedStreamReader(std::istream& fs, const std::unordered_map<int32_t, char32_t>& unicode_mapping);

    void advance();

    std::istream& fs_;
    const std::unordered_map<int32_t, char32_t>& unicode_mapping_;
    int32_t next_ = EOF;
};
