#pragma once

#include "text_stream_reader.h"
#include <cstdio>  // EOF

class Utf32BeStreamReader : public TextStreamReader
{
public:
    Utf32BeStreamReader() = delete;
    Utf32BeStreamReader(const Utf32BeStreamReader&) = delete;
    ~Utf32BeStreamReader() override = default;
    Utf32BeStreamReader& operator=(const Utf32BeStreamReader&) = delete;

protected:
    char32_t advance() override;

private:
    friend class TextStreamReader;

    explicit Utf32BeStreamReader(std::istream& in) noexcept;

    std::istream& in_;
};
