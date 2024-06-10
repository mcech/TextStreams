#pragma once

#include "text_stream_reader.h"

class Utf8StreamReader : public TextStreamReader
{
public:
    Utf8StreamReader() = delete;
    Utf8StreamReader(std::istream& in);
    Utf8StreamReader(const Utf8StreamReader&) = delete;
    ~Utf8StreamReader() override = default;
    Utf8StreamReader& operator=(const Utf8StreamReader&) = delete;

protected:
    char32_t get() override;

private:
    std::istream& in_;
};
