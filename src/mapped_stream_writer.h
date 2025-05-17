#pragma once

#include "text_stream_writer.h"
#include <unordered_map>  // std::unordered_map

class MappedStreamWriter : public TextStreamWriter
{
public:
    MappedStreamWriter() = delete;
    MappedStreamWriter(const MappedStreamWriter&) = delete;
    ~MappedStreamWriter() override = default;
    MappedStreamWriter& operator=(const MappedStreamWriter&) = delete;

    void write(char32_t c) override;

private:
    friend class TextStreamWriter;

    MappedStreamWriter(std::ostream& out, const std::unordered_map<char32_t, uint8_t>& unicode_mapping, LineEndings nl);

    static constexpr uint8_t REPLACEMENT_CHAR = '?';

    std::ostream& out_;
    const std::unordered_map<char32_t, uint8_t>& unicode_mapping_;
};
