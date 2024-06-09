#pragma once

#include "text_stream_reader.h"

class Utf8StreamReader : public TextStreamReader
{
public:
    Utf8StreamReader() = delete;
    Utf8StreamReader(const Utf8StreamReader&) = delete;
    ~Utf8StreamReader() override = default;
    Utf8StreamReader& operator=(const Utf8StreamReader&) = delete;

    char32_t peek() override;
    char32_t read() override;

protected:
    friend class TextStreamReader;

    Utf8StreamReader(std::istream& fs);

    void advance();

    std::istream& fs_;
    char32_t next_ = EOF;
};
