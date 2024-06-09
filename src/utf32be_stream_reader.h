#pragma once

#include "text_stream_reader.h"

class Utf32BeStreamReader : public TextStreamReader
{
public:
    Utf32BeStreamReader() = delete;
    Utf32BeStreamReader(const Utf32BeStreamReader&) = delete;
    ~Utf32BeStreamReader() override = default;
    Utf32BeStreamReader& operator=(const Utf32BeStreamReader&) = delete;

    char32_t peek() override;
    char32_t read() override;

protected:
    friend class TextStreamReader;

    Utf32BeStreamReader(std::istream& fs);

    std::istream& fs_;
};
