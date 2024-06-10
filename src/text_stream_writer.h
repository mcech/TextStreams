#pragma once

#include "charset.h"
#include "line_ending.h"
#include <ostream>
#include <memory>
#include <string>

class TextStreamWriter
{
public:
    static std::unique_ptr<TextStreamWriter> open(std::ostream& out, Charset cs = Charset::UTF_8, LineEnding nl = LineEnding::UNIX);

    TextStreamWriter() = delete;
    TextStreamWriter(LineEnding nl) noexcept;
    TextStreamWriter(const TextStreamWriter&) = delete;
    virtual ~TextStreamWriter() = default;
    TextStreamWriter& operator=(const TextStreamWriter&) = delete;

    void write(char32_t c);
    void write(const std::u32string& str);
    void write_line(const std::u32string& str);

protected:
    virtual void put(char32_t c) = 0;

private:
    LineEnding nl_;
};
