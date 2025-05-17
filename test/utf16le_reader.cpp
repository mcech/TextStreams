#include "gtest/gtest.h"

#include "text_stream_reader.h"
#include <sstream>
#include <string>

TEST(UTF16LE_Reader, utf16le_single_word)
{
    std::string input("\x79\0\xAC\x20", 4);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_16_LE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\x79\x20AC");
}

TEST(UTF16LE_Reader, utf16le_double_word)
{
    std::string input = "\x34\xD8\x1E\xDD";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_16_LE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\x0001D11E");
}

TEST(UTF16LE_Reader, invalid_utf16le_incomplete_first_word)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = "\x34";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_16_LE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF16LE_Reader, invalid_utf16le_incomplete_second_word)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = "\x34\xD8\x1E";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_16_LE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF16LE_Reader, invalid_utf16le_missing_second_word)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input("\x34\xD8\x79\0", 4);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_16_LE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");

    std::cerr.rdbuf(cerr_buf);
}
