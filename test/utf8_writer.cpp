#include "gtest/gtest.h"

#include "text_stream_writer.h"
#include <sstream>
#include <string>

TEST(UTF8_Writer, utf8_single_byte)
{
    std::u32string input = U"\x79";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_8);
    writer->write(input);
    EXPECT_EQ(oss.str(), "\x79");
}

TEST(UTF8_Writer, utf8_two_bytes)
{
    std::u32string input = U"\xE4\x03A9";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_8);
    writer->write(input);
    EXPECT_EQ(oss.str(), "\xC3\xA4\xCE\xA9");
}

TEST(UTF8_Writer, utf8_three_bytes)
{
    std::u32string input = U"\x20AC\xE000";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_8);
    writer->write(input);
    EXPECT_EQ(oss.str(), "\xE2\x82\xAC\xEE\x80\x80");
}

TEST(UTF8_Writer, utf8_four_bytes)
{
    std::u32string input = U"\x0001D11E";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_8);
    writer->write(input);
    EXPECT_EQ(oss.str(), "\xF0\x9D\x84\x9E");
}

TEST(UTF8_Writer, utf8_invalid_codepoints)
{
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_8);
    EXPECT_THROW(writer->write(0xD800), std::invalid_argument);
    EXPECT_THROW(writer->write(0x00110000), std::invalid_argument);
}
