#pragma once

#include "text_stream_writer.h"

class Utf16LeStreamWriter : public TextStreamWriter
{
public:
    Utf16LeStreamWriter() = delete;
    Utf16LeStreamWriter(const Utf16LeStreamWriter&) = delete;
    ~Utf16LeStreamWriter() override = default;
    Utf16LeStreamWriter& operator=(const Utf16LeStreamWriter&) = delete;

    void write(char32_t c) override;

private:
    friend class TextStreamWriter;

    Utf16LeStreamWriter(std::ostream& out, LineEndings nl);

    std::ostream& out_;
};
