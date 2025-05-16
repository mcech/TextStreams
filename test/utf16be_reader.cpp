#include "gtest/gtest.h"

#include "text_stream_reader.h"
#include <sstream>
#include <string>

TEST(UTF16BE_Reader, utf16be_single_word)
{
    std::string input("\0\x79\x20\xAC", 4);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_16_BE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\x79\x20AC");
}

TEST(UTF16BE_Reader, utf16be_double_word)
{
    std::string input = "\xD8\x34\xDD\x1E";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_16_BE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\x0001D11E");
}

TEST(UTF16BE_Reader, invalid_utf16be_incomplete_first_word)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = "\xD8";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_16_BE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF16BE_Reader, invalid_utf16be_incomplete_second_word)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = "\xD8\x34\xDD";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_16_BE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF16BE_Reader, invalid_utf16be_missing_second_word)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input("\xD8\x34\0\x79", 4);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_16_BE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");

    std::cerr.rdbuf(cerr_buf);
}
