#pragma once

#include "charset.h"
#include "line_endings.h"
#include <memory>
#include <string>

class TextStreamWriter
{
public:
    static std::unique_ptr<TextStreamWriter> open(std::string path, Charset cs = Charset::UTF_8, LineEndings nl = LineEndings::UNIX);

    TextStreamWriter(const TextStreamWriter&) = delete;
    virtual ~TextStreamWriter() = default;
    TextStreamWriter& operator=(const TextStreamWriter&) = delete;

    virtual void write(char32_t c) = 0;
    virtual void write(const std::u32string& str);
    virtual void write_line(const std::u32string& str);

protected:
    TextStreamWriter(LineEndings nl) noexcept;

    LineEndings nl;
};
