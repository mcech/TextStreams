// #include "utf8_stream_writer.h"

// #include <ios>  // std::ios::failure

// Utf8StreamWriter::Utf8StreamWriter(std::ostream& out, LineEndings nl) : TextStreamWriter(nl), out_(out)
// {
// }

// void Utf8StreamWriter::write(char32_t c)
// {
//     if (c < 0x80)
//     {
//         out_.put(c);
//     }
//     else if (c < 0x0800)
//     {
//         out_.put(((c >>  6) & 0x3F) | 0xC0);
//         out_.put(( c        & 0x3F) | 0x80);
//     }
//     else if (c >= 0xD800 && c <= 0xDFFF)
//     {
//         // 0xD800 to 0xDFFF not assigned in Unicode. They are reserved to encode UTF-16.
//         throw std::ios::failure("Invalid Unicode character");
//     }
//     else if (c < 0x00010000)
//     {
//         out_.put(((c >> 12) & 0x3F) | 0xE0);
//         out_.put(((c >>  6) & 0x3F) | 0x80);
//         out_.put(( c        & 0x3F) | 0x80);
//     }
//     else if (c < 0x00110000)
//     {
//         out_.put(((c >> 18) & 0x3F) | 0xF0);
//         out_.put(((c >> 12) & 0x3F) | 0x80);
//         out_.put(((c >>  6) & 0x3F) | 0x80);
//         out_.put(( c        & 0x3F) | 0x80);
//     }
//     else
//     {
//         throw std::ios::failure("Invalid Unicode character");
//     }
// }
