#pragma once

#include "charset.h"
#include <istream>  // std::istream
#include <memory>   // std::unique_ptr
#include <string>   // std::u32string
#include <cstddef>  // size_t

class TextStreamReader
{
public:
    static std::unique_ptr<TextStreamReader> open(std::istream& in, Charset cs);

    TextStreamReader(const TextStreamReader&) = delete;
    virtual ~TextStreamReader() = default;  // LCOV_EXCL_LINE
    TextStreamReader& operator=(const TextStreamReader&) = delete;

    char32_t peek() const noexcept;
    char32_t read();
    std::u32string read(size_t n);
    std::u32string read_line();

    static constexpr char32_t REPLACEMENT_CHAR = 0xFFFD;

protected:
    TextStreamReader() noexcept = default;

    virtual char32_t advance() = 0;
    char32_t next_ = EOF;
};
