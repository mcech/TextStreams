#include "charset_detector.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> files =
{
    // "C:/Users/MichaelCech/TextStreams/test/ascii.txt",
    // "C:/Users/MichaelCech/TextStreams/test/ascii.txt",
    // "C:/Users/MichaelCech/TextStreams/test/iso_latin.txt",
    // "C:/Users/MichaelCech/TextStreams/test/iso_latin.txt",

    "C:/Users/MichaelCech/TextStreams/test/utf8.txt",
    "C:/Users/MichaelCech/TextStreams/test/utf16le.txt",
    "C:/Users/MichaelCech/TextStreams/test/utf16be.txt",
    "C:/Users/MichaelCech/TextStreams/test/utf32le.txt",
    "C:/Users/MichaelCech/TextStreams/test/utf32be.txt",

    // "C:/Users/MichaelCech/TextStreams/test/utf8_bom.txt",
    // "C:/Users/MichaelCech/TextStreams/test/utf16le_bom.txt",
    // "C:/Users/MichaelCech/TextStreams/test/utf16be_bom.txt",
    // "C:/Users/MichaelCech/TextStreams/test/utf32le_bom.txt",
    // "C:/Users/MichaelCech/TextStreams/test/utf32be_bom.txt"
};

int main()
{
    for (const std::string& path : files)
    {
        std::ifstream in(path, std::ios_base::in, std::ios_base::binary);
        Charset cs = CharsetDetector::detect(in);
        std::cout << path << ": " << int(cs) << std::endl;
    }
    return 0;
}
