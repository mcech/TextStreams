#pragma once

#include "text_stream_writer.h"

class Utf32LeStreamWriter : public TextStreamWriter
{
public:
    Utf32LeStreamWriter() = delete;
    Utf32LeStreamWriter(const Utf32LeStreamWriter&) = delete;
    ~Utf32LeStreamWriter() override = default;
    Utf32LeStreamWriter& operator=(const Utf32LeStreamWriter&) = delete;

    void write(char32_t c) override;

private:
    friend class TextStreamWriter;

    Utf32LeStreamWriter(std::ostream& out, LineEndings nl);

    std::ostream& out_;
};
