#pragma once

#include "text_stream_reader.h"

class Utf16BeStreamReader : public TextStreamReader
{
public:
    Utf16BeStreamReader() = delete;
    Utf16BeStreamReader(const Utf16BeStreamReader&) = delete;
    ~Utf16BeStreamReader() override = default;
    Utf16BeStreamReader& operator=(const Utf16BeStreamReader&) = delete;

protected:
    char32_t advance() override;

private:
    friend class TextStreamReader;

    explicit Utf16BeStreamReader(std::istream& in) noexcept;

    std::istream& in_;
};
