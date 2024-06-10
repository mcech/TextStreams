#pragma once

#include "text_stream_writer.h"

class Utf16LeStreamWriter : public TextStreamWriter
{
public:
    Utf16LeStreamWriter() = delete;
    Utf16LeStreamWriter(std::ostream& out, LineEnding nl);
    Utf16LeStreamWriter(const Utf16LeStreamWriter&) = delete;
    ~Utf16LeStreamWriter() override = default;
    Utf16LeStreamWriter& operator=(const Utf16LeStreamWriter&) = delete;

protected:
    void put(char32_t c) override;

private:
    std::ostream& out_;
};
