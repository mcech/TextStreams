#pragma once

#include "text_stream_writer.h"
#include <unordered_map>

class MappedStreamWriter : public TextStreamWriter
{
public:
    MappedStreamWriter() = delete;
    MappedStreamWriter(std::ostream& out, const std::unordered_map<int32_t, char32_t>& unicode_mapping, LineEnding nl);
    MappedStreamWriter(const MappedStreamWriter&) = delete;
    ~MappedStreamWriter() override = default;
    MappedStreamWriter& operator=(const MappedStreamWriter&) = delete;

protected:
    void put(char32_t c) override;

private:
    std::ostream& out_;
    const std::unordered_map<int32_t, char32_t>& unicode_mapping_;
};
