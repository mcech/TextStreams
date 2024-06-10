#pragma once

#include "text_stream_reader.h"

class Utf32BeStreamReader : public TextStreamReader
{
public:
    Utf32BeStreamReader() = delete;
    Utf32BeStreamReader(std::istream& in);
    Utf32BeStreamReader(const Utf32BeStreamReader&) = delete;
    ~Utf32BeStreamReader() override = default;
    Utf32BeStreamReader& operator=(const Utf32BeStreamReader&) = delete;

protected:
    char32_t get() override;

private:
    std::istream& in_;
};
