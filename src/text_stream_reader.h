#pragma once

#include <string>

class TextStreamReader
{
public:
    TextStreamReader() noexcept = default;
    TextStreamReader(const TextStreamReader&) = delete;
    virtual ~TextStreamReader() = default;
    TextStreamReader& operator=(const TextStreamReader&) = delete;

    virtual char32_t peek() = 0;
    virtual char32_t read() = 0;
    virtual std::u32string read(size_t n);
    virtual std::u32string read_line();

    static constexpr char32_t REPLACEMENT_CHAR = 0xFFFD;
};
