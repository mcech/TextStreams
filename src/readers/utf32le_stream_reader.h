#pragma once

#include "text_stream_reader.h"

class Utf32LeStreamReader : public TextStreamReader
{
public:
    Utf32LeStreamReader() = delete;
    Utf32LeStreamReader(std::istream& in);
    Utf32LeStreamReader(const Utf32LeStreamReader&) = delete;
    ~Utf32LeStreamReader() override = default;
    Utf32LeStreamReader& operator=(const Utf32LeStreamReader&) = delete;

protected:
    char32_t get() override;

private:
    std::istream& in_;
};
