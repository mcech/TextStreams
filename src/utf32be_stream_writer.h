#pragma once

#include "text_stream_writer.h"

class Utf32BeStreamWriter : public TextStreamWriter
{
public:
    Utf32BeStreamWriter() = delete;
    Utf32BeStreamWriter(const Utf32BeStreamWriter&) = delete;
    ~Utf32BeStreamWriter() override = default;
    Utf32BeStreamWriter& operator=(const Utf32BeStreamWriter&) = delete;

    void write(char32_t c) override;

private:
    friend class TextStreamWriter;

    Utf32BeStreamWriter(std::ostream& out, LineEndings nl);

    std::ostream& out_;
};
