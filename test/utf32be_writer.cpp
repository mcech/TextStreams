#include "gtest/gtest.h"

#include "text_stream_writer.h"
#include <sstream>
#include <string>

TEST(UTF32BE_Writer, utf32be_single_word)
{
    std::u32string input = U"\x79\x20AC";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_32_BE);
    writer->write(input);
    EXPECT_EQ(oss.str(), std::string("\0\0\0\x79\0\0\x20\xAC", 8));
}

TEST(UTF32BE_Writer, utf32be_invalid_codepoints)
{
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_32_BE);
    EXPECT_THROW(writer->write(0xD800), std::invalid_argument);
    EXPECT_THROW(writer->write(0x00110000), std::invalid_argument);
}
