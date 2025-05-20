#include "gtest/gtest.h"

#include "text_stream_writer.h"
#include <sstream>
#include <string>

TEST(UTF32LE_Writer, utf32le_single_word)
{
    std::u32string input = U"\x79\x20AC";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_32_LE);
    writer->write(input);
    EXPECT_EQ(oss.str(), std::string("\x79\0\0\0\xAC\x20\0\0", 8));
}

TEST(UTF32LE_Writer, utf32le_invalid_codepoints)
{
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_32_LE);
    EXPECT_THROW(writer->write(0xD800), std::invalid_argument);
    EXPECT_THROW(writer->write(0x00110000), std::invalid_argument);
}
