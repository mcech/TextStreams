#pragma once

#include "text_stream_writer.h"

class Utf32LeStreamWriter : public TextStreamWriter
{
public:
    Utf32LeStreamWriter() = delete;
    Utf32LeStreamWriter(std::ostream& out, LineEnding nl);
    Utf32LeStreamWriter(const Utf32LeStreamWriter&) = delete;
    ~Utf32LeStreamWriter() override = default;
    Utf32LeStreamWriter& operator=(const Utf32LeStreamWriter&) = delete;

protected:
    void put(char32_t c) override;

private:
    std::ostream& out_;
};
