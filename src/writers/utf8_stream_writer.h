#pragma once

#include "text_stream_writer.h"

class Utf8StreamWriter : public TextStreamWriter
{
public:
    Utf8StreamWriter() = delete;
    Utf8StreamWriter(std::ostream& out, LineEnding nl);
    Utf8StreamWriter(const Utf8StreamWriter&) = delete;
    ~Utf8StreamWriter() override = default;
    Utf8StreamWriter& operator=(const Utf8StreamWriter&) = delete;

protected:
    void put(char32_t c) override;

private:
    std::ostream& out_;
};
