#pragma once

#include "text_stream_reader.h"

class Utf8StreamReader : public TextStreamReader
{
public:
    Utf8StreamReader() = delete;
    Utf8StreamReader(const Utf8StreamReader&) = delete;
    ~Utf8StreamReader() override = default;
    Utf8StreamReader& operator=(const Utf8StreamReader&) = delete;

protected:
    char32_t advance() override;

private:
    friend class TextStreamReader;

    explicit Utf8StreamReader(std::istream& in) noexcept;

    char32_t read_composed(uint8_t prefix, size_t consecutives);

    std::istream& in_;
};
