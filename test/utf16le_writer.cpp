#include "gtest/gtest.h"

#include "text_stream_writer.h"
#include <sstream>
#include <string>

TEST(UTF16LE_Writer, utf16le_single_word)
{
    std::u32string input = U"\x79\x20AC";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_16_LE);
    writer->write(input);
    EXPECT_EQ(oss.str(), std::string("\x79\0\xAC\x20", 4));
}

TEST(UTF16LE_Writer, utf16le_double_word)
{
    std::u32string input = U"\x0001D11E";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_16_LE);
    writer->write(input);
    EXPECT_EQ(oss.str(), "\x34\xD8\x1E\xDD");
}

TEST(UTF16LE_Writer, utf16le_invalid_codepoints)
{
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_16_LE);
    EXPECT_THROW(writer->write(0xD800), std::invalid_argument);
    EXPECT_THROW(writer->write(0x00110000), std::invalid_argument);
}
