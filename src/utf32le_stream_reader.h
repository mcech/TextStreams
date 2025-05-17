#pragma once

#include "text_stream_reader.h"

class Utf32LeStreamReader : public TextStreamReader
{
public:
    Utf32LeStreamReader() = delete;
    Utf32LeStreamReader(const Utf32LeStreamReader&) = delete;
    ~Utf32LeStreamReader() override = default;
    Utf32LeStreamReader& operator=(const Utf32LeStreamReader&) = delete;

protected:
    char32_t advance() override;

private:
    friend class TextStreamReader;

    explicit Utf32LeStreamReader(std::istream& in) noexcept;

    std::istream& in_;
};
