#pragma once

#include "text_stream_reader.h"

class Utf16LeStreamReader : public TextStreamReader
{
public:
    Utf16LeStreamReader() = delete;
    Utf16LeStreamReader(const Utf16LeStreamReader&) = delete;
    ~Utf16LeStreamReader() override = default;
    Utf16LeStreamReader& operator=(const Utf16LeStreamReader&) = delete;

protected:
    char32_t advance() override;

private:
    friend class TextStreamReader;

    explicit Utf16LeStreamReader(std::istream& in) noexcept;

    std::istream& in_;
};
