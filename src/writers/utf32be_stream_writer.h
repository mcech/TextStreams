#pragma once

#include "text_stream_writer.h"

class Utf32BeStreamWriter : public TextStreamWriter
{
public:
    Utf32BeStreamWriter() = delete;
    Utf32BeStreamWriter(std::ostream& out, LineEnding nl);
    Utf32BeStreamWriter(const Utf32BeStreamWriter&) = delete;
    ~Utf32BeStreamWriter() override = default;
    Utf32BeStreamWriter& operator=(const Utf32BeStreamWriter&) = delete;

protected:
    void put(char32_t c) override;

private:
    std::ostream& out_;
};
