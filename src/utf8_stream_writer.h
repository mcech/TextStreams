#pragma once

#include "text_stream_writer.h"

class Utf8StreamWriter : public TextStreamWriter
{
public:
    Utf8StreamWriter() = delete;
    Utf8StreamWriter(const Utf8StreamWriter&) = delete;
    ~Utf8StreamWriter() override = default;
    Utf8StreamWriter& operator=(const Utf8StreamWriter&) = delete;

    void write(char32_t c) override;

private:
    friend class TextStreamWriter;

    Utf8StreamWriter(std::ostream& out, LineEndings nl);

    std::ostream& out_;
};
