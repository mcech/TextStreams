#include "text_stream_reader.h"

#include <iostream>
#include <unordered_map>

std::unordered_map<Charset, std::string> tests =
{
    {Charset::CP_437, "C:/Users/MichaelCech/Avatars/TextStreams/test/ascii.txt"},
    {Charset::CP_850, "C:/Users/MichaelCech/Avatars/TextStreams/test/ascii.txt"},
    {Charset::CP_1252, "C:/Users/MichaelCech/Avatars/TextStreams/test/iso_latin.txt"},
    {Charset::ISO_8859_15, "C:/Users/MichaelCech/Avatars/TextStreams/test/iso_latin.txt"},

    {Charset::UTF_8, "C:/Users/MichaelCech/Avatars/TextStreams/test/utf8.txt"},
    {Charset::UTF_16_LE, "C:/Users/MichaelCech/Avatars/TextStreams/test/utf16le.txt"},
    {Charset::UTF_16_BE, "C:/Users/MichaelCech/Avatars/TextStreams/test/utf16be.txt"},
    {Charset::UTF_32_LE, "C:/Users/MichaelCech/Avatars/TextStreams/test/utf32le.txt"},
    {Charset::UTF_32_BE, "C:/Users/MichaelCech/Avatars/TextStreams/test/utf32be.txt"},

    {Charset::UTF_8_BOM, "C:/Users/MichaelCech/Avatars/TextStreams/test/utf8_bom.txt"},
    {Charset::UTF_16_LE_BOM, "C:/Users/MichaelCech/Avatars/TextStreams/test/utf16le_bom.txt"},
    {Charset::UTF_16_BE_BOM, "C:/Users/MichaelCech/Avatars/TextStreams/test/utf16be_bom.txt"},
    {Charset::UTF_32_LE_BOM, "C:/Users/MichaelCech/Avatars/TextStreams/test/utf32le_bom.txt"},
    {Charset::UTF_32_BE_BOM, "C:/Users/MichaelCech/Avatars/TextStreams/test/utf32be_bom.txt"}
};

int main()
{
    for (const auto& [cs, path] : tests)
    {
        std::ifstream fs(path, std::ios_base::in | std::ios_base::binary);
        std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(fs, cs);
        std::u32string line = reader->read_line();
        for (char32_t c : line)
        {
            std::cout << char(c);
        }
        std::cout << std::endl;
    }
    return 0;
}
