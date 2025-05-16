//TODO test five or six byte encodings
//TODO test CESU-8 encodings
//TODO test codepoint beyond 0x0010FFFF

#include "gtest/gtest.h"

#include "text_stream_reader.h"
#include <sstream>
#include <string>

TEST(UTF8_Reader, empty)
{
    std::string input = "";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_8);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"");
}

TEST(UTF8_Reader, utf8_single_byte)
{
    std::string input = "\x79";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_8);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\x79");
}

TEST(UTF8_Reader, utf8_two_bytes)
{
    std::string input = "\xC3\xA4\xCE\xA9";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_8);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xE4\x03A9");
}

TEST(UTF8_Reader, utf8_three_bytes)
{
    std::string input = "\xE2\x82\xAC\xEE\x80\x80";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_8);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\x20AC\xE000");
}

TEST(UTF8_Reader, utf8_four_bytes)
{
    std::string input = "\xF0\x9D\x84\x9E";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_8);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\x0001D11E");
}

TEST(UTF8_Reader, utf8_alternative_encoding)
{
    std::string input = "\x79\xC1\xB9\xCE\xA9\xE0\x8E\xA9\xF0\x80\x8E\xA9";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_8);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"yy\x03A9\x03A9\x03A9");
}

TEST(UTF8_Reader, invalid_utf8_single_leading_one)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = std::string("\x80", 1);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_8);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF8_Reader, invalid_utf8_five_leading_ones)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = std::string("\xF8", 1);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_8);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF8_Reader, invalid_utf8_undersized_consecutive_byte)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = std::string("\xC0\x7F", 2);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_8);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF8_Reader, invalid_utf8_oversized_consecutive_byte)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = std::string("\xC0\xC0", 2);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_8);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF8_Reader, invalid_utf8_missing_second_byte)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = std::string("\xC0", 1);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_8);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF8_Reader, invalid_utf8_encoded_surrogate)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = std::string("\xED\xA0\x80", 3);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_8);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF8_Reader, invalid_utf8_oversized_codepoint)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = std::string("\xF7\xBF\xBF\xBF", 4);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_8);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}
