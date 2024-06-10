#pragma once

#include "text_stream_writer.h"

class Utf16BeStreamWriter : public TextStreamWriter
{
public:
    Utf16BeStreamWriter() = delete;
    Utf16BeStreamWriter(std::ostream& out, LineEnding nl);
    Utf16BeStreamWriter(const Utf16BeStreamWriter&) = delete;
    ~Utf16BeStreamWriter() override = default;
    Utf16BeStreamWriter& operator=(const Utf16BeStreamWriter&) = delete;

protected:
    void put(char32_t c) override;

private:
    std::ostream& out_;
};
