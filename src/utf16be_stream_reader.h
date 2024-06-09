#pragma once

#include "text_stream_reader.h"

class Utf16BeStreamReader : public TextStreamReader
{
public:
    Utf16BeStreamReader() = delete;
    Utf16BeStreamReader(const Utf16BeStreamReader&) = delete;
    ~Utf16BeStreamReader() override = default;
    Utf16BeStreamReader& operator=(const Utf16BeStreamReader&) = delete;

    char32_t peek() override;
    char32_t read() override;

protected:
    friend class TextStreamReader;

    Utf16BeStreamReader(std::istream& fs);

    std::istream& fs_;
};
