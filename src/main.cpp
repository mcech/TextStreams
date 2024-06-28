#include "readers/gzip_reader.h"
#include <fstream>
#include <iostream>

int main() {
    std::basic_ifstream<uint8_t> a("C:/Users/MichaelCech/TextStreams/test/html.gz", std::ios_base::in | std::ios_base::binary);
    GzipReader b(a);
    GzipReader c = {};
    for (int i = 0; i < 80; ++i)
    {
        std::cout << char(b.get());
    }
    c = std::move(b);
    while (c.peek() != EOF)
    {
        std::cout << char(c.get());
    }
    std::cout << std::endl;
    return 0;
}
