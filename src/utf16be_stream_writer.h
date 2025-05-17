#pragma once

#include "text_stream_writer.h"

class Utf16BeStreamWriter : public TextStreamWriter
{
public:
    Utf16BeStreamWriter() = delete;
    Utf16BeStreamWriter(const Utf16BeStreamWriter&) = delete;
    ~Utf16BeStreamWriter() override = default;
    Utf16BeStreamWriter& operator=(const Utf16BeStreamWriter&) = delete;

    void write(char32_t c) override;

private:
    friend class TextStreamWriter;

    Utf16BeStreamWriter(std::ostream& out, LineEndings nl);

    std::ostream& out_;
};
