#include "gtest/gtest.h"

#include "text_stream_writer.h"
#include <sstream>
#include <string>

TEST(MappedWriter, cp437)
{
    std::u32string input = U"\xC7\xA2\xA5\xA7\xB1";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::CP_437);
    writer->write(input);
    EXPECT_EQ(oss.str(), "\x80\x9B\x9D\x15\xF1");
}

TEST(MappedWriter, cp850)
{
    std::u32string input = U"\xC7\xA2\xA5\xA7\xB1";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::CP_850);
    writer->write(input);
    EXPECT_EQ(oss.str(), "\x80\xBD\xBE\xF5\xF1");
}

TEST(MappedWriter, cp1252)
{
    std::u32string input = U"\xC7\xA2\xA5\xA7\xB1\x20AC";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::CP_1252);
    writer->write(input);
    EXPECT_EQ(oss.str(), "\xC7\xA2\xA5\xA7\xB1\x80");
}

TEST(MappedWriter, iso8859_15)
{
    std::u32string input = U"\xC7\xA2\xA5\xA7\xB1\x20AC";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::ISO_8859_15);
    writer->write(input);
    EXPECT_EQ(oss.str(), "\xC7\xA2\xA5\xA7\xB1\xA4");
}

TEST(MappedWriter, invalid_codepoints)
{
    std::u32string input = U"\x80";
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::ISO_8859_15);
    writer->write(input);
    EXPECT_EQ(oss.str(), "?");
}
