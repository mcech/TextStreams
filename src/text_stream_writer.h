#pragma once

#include "charset.h"
#include "line_endings.h"
#include <memory>   // std::unique_ptr
#include <ostream>  // std::ostream
#include <string>   // std::u32string

class TextStreamWriter
{
public:
    static std::unique_ptr<TextStreamWriter> create(std::ostream& out, Charset cs = Charset::UTF_8, LineEndings nl = LineEndings::UNIX);

    TextStreamWriter() = delete;
    TextStreamWriter(const TextStreamWriter&) = delete;
    virtual ~TextStreamWriter() = default;  // LCOV_EXCL_LINE
    TextStreamWriter& operator=(const TextStreamWriter&) = delete;

    virtual void write(char32_t c) = 0;
    virtual void write(const std::u32string& str);
    virtual void write_line(const std::u32string& str);

protected:
    TextStreamWriter(LineEndings nl);

private:
    const std::u32string* newline_;
};
