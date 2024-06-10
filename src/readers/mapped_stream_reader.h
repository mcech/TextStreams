#pragma once

#include "text_stream_reader.h"
#include <unordered_map>

class MappedStreamReader : public TextStreamReader
{
public:
    MappedStreamReader() = delete;
    MappedStreamReader(std::istream& in, const std::unordered_map<int32_t, char32_t>& unicode_mapping);
    MappedStreamReader(const MappedStreamReader&) = delete;
    ~MappedStreamReader() override = default;
    MappedStreamReader& operator=(const MappedStreamReader&) = delete;

protected:
    char32_t get() override;

private:
    std::istream& in_;
    const std::unordered_map<int32_t, char32_t>& unicode_mapping_;
};
