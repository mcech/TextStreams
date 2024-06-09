#pragma once

#include "text_stream_reader.h"

class Utf16LeStreamReader : public TextStreamReader
{
public:
    Utf16LeStreamReader() = delete;
    Utf16LeStreamReader(const Utf16LeStreamReader&) = delete;
    ~Utf16LeStreamReader() override = default;
    Utf16LeStreamReader& operator=(const Utf16LeStreamReader&) = delete;

    char32_t peek() override;
    char32_t read() override;

protected:
    friend class TextStreamReader;

    Utf16LeStreamReader(std::istream& fs);

    void advance();

    std::istream& fs_;
    char32_t next_ = EOF;
};
