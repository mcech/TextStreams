#include "gtest/gtest.h"

#include "text_stream_reader.h"
#include <sstream>
#include <string>

TEST(MappedReader, cp437)
{
    std::string input = "\x80\x9B\x9D\x15\xF1";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::CP_437);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xC7\xA2\xA5\xA7\xB1");
}

TEST(MappedReader, cp850)
{
    std::string input = "\x80\xBD\xBE\x15\xF5\xF1";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::CP_850);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xC7\xA2\xA5\xA7\xA7\xB1");
}

TEST(MappedReader, cp1252)
{
    std::string input = "\xC7\xA2\xA5\xA7\xB1\x80";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::CP_1252);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xC7\xA2\xA5\xA7\xB1\x20AC");
}

TEST(MappedReader, iso8859_15)
{
    std::string input = "\xC7\xA2\xA5\xA7\xB1\xA4";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::ISO_8859_15);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xC7\xA2\xA5\xA7\xB1\x20AC");
}

TEST(MappedReader, invalid_codepoints)
{
    std::ostringstream err;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(err.rdbuf());

    std::istringstream iss("\x12\x90");
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::ISO_8859_15);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD\xFFFD");
    EXPECT_TRUE(err.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}
