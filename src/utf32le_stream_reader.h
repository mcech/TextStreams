#pragma once

#include "text_stream_reader.h"

class Utf32LeStreamReader : public TextStreamReader
{
public:
    Utf32LeStreamReader() = delete;
    Utf32LeStreamReader(const Utf32LeStreamReader&) = delete;
    ~Utf32LeStreamReader() override = default;
    Utf32LeStreamReader& operator=(const Utf32LeStreamReader&) = delete;

    char32_t peek() override;
    char32_t read() override;

protected:
    friend class TextStreamReader;

    Utf32LeStreamReader(std::istream& fs);

    std::istream& fs_;
};
