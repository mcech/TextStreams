#pragma once

#include "text_stream_reader.h"

class Utf16BeStreamReader : public TextStreamReader
{
public:
    Utf16BeStreamReader() = delete;
    Utf16BeStreamReader(std::istream& in);
    Utf16BeStreamReader(const Utf16BeStreamReader&) = delete;
    ~Utf16BeStreamReader() override = default;
    Utf16BeStreamReader& operator=(const Utf16BeStreamReader&) = delete;

protected:
    char32_t get() override;

private:
    std::istream& in_;
};
