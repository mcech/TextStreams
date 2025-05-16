#include "text_stream_writer.h"

#include <fstream>
#include <stdexcept>

std::unique_ptr<TextStreamWriter> TextStreamWriter::open(std::string path, Charset cs, LineEndings nl)
{
    std::basic_fstream<uint8_t> fs(path, std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
    switch (cs)
    {
    // case Charset::CP_1252:
    //     return std::unique_ptr<TextStreamWriter>(new Cp1252StreamWriter(std::move(fs)));
    // case Charset::ISO_8859_15:
    //     return std::unique_ptr<TextStreamWriter>(new Iso8859euroStreamWriter(std::move(fs)));
    // case Charset::UTF_32_LE:
    //     return std::unique_ptr<TextStreamWriter>(new Utf32leStreamWriter(std::move(fs)));
    // case Charset::UTF_32_BE:
    //     return std::unique_ptr<TextStreamWriter>(new Utf32beStreamWriter(std::move(fs)));
    // case Charset::UTF_32_LE_BOM:
    //     return std::unique_ptr<TextStreamWriter>(new Utf32lebomStreamWriter(std::move(fs)));
    // case Charset::UTF_32_BE_BOM:
    //     return std::unique_ptr<TextStreamWriter>(new Utf32bebomStreamWriter(std::move(fs)));
    default:
        throw std::invalid_argument("Unknown character encoding");
    }
}

void TextStreamWriter::write(const std::u32string& str)
{
    for (char32_t c : str)
    {
        write(c);
    }
}

void TextStreamWriter::write_line(const std::u32string& str)
{
    write(str);
    switch (nl)
    {
    case LineEndings::DOS:
        write('\r');
        write('\n');
        break;
    case LineEndings::MAC:
        write('\r');
        break;
    case LineEndings::UNIX:
        write('\n');
        break;
    }
}

TextStreamWriter::TextStreamWriter(LineEndings nl) noexcept : nl(nl)
{
}
