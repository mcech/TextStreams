#include "gtest/gtest.h"

#include "text_stream_writer.h"
#include <sstream>
#include <string>

TEST(UTF16BE_Writer, utf16be_single_word)
{
    std::u32string input = U"\x79\x20AC";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_16_BE);
    writer->write(input);
    EXPECT_EQ(oss.str(), std::string("\0\x79\x20\xAC", 4));
}

TEST(UTF16BE_Writer, utf16be_double_word)
{
    std::u32string input = U"\x0001D11E";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_16_BE);
    writer->write(input);
    EXPECT_EQ(oss.str(), "\xD8\x34\xDD\x1E");
}

TEST(UTF16BE_Writer, utf16be_invalid_codepoints)
{
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_16_BE);
    EXPECT_THROW(writer->write(0xD800), std::invalid_argument);
    EXPECT_THROW(writer->write(0x00110000), std::invalid_argument);
}
