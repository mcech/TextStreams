#pragma once

#include <string>

class TextStreamWriter
{
public:
    TextStreamWriter() noexcept = default;
    TextStreamWriter(const TextStreamWriter&) = delete;
    virtual ~TextStreamWriter() = default;
    TextStreamWriter& operator=(const TextStreamWriter&) = delete;

    virtual void write(char32_t c) = 0;
    virtual void write(const std::u32string& str);
    virtual void write_line(const std::u32string& str) = 0;
};
