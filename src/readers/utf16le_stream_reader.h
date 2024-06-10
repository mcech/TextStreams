#pragma once

#include "text_stream_reader.h"

class Utf16LeStreamReader : public TextStreamReader
{
public:
    Utf16LeStreamReader() = delete;
    Utf16LeStreamReader(std::istream& in);
    Utf16LeStreamReader(const Utf16LeStreamReader&) = delete;
    ~Utf16LeStreamReader() override = default;
    Utf16LeStreamReader& operator=(const Utf16LeStreamReader&) = delete;

protected:
    char32_t get() override;

private:
    std::istream& in_;
};
