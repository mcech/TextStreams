#pragma once

#include "charset.h"
#include <istream>
#include <memory>
#include <string>

class TextStreamReader
{
public:
    static std::unique_ptr<TextStreamReader> open(std::istream& in, Charset cs);

    TextStreamReader() noexcept = default;
    TextStreamReader(const TextStreamReader&) = delete;
    virtual ~TextStreamReader() = default;
    TextStreamReader& operator=(const TextStreamReader&) = delete;

    char32_t peek();
    char32_t read();
    std::u32string read(size_t n);
    std::u32string read_line();

protected:
    virtual char32_t get() = 0;

private:
    int32_t next_ = EOF;
};
