#include "gtest/gtest.h"

#include "text_stream_reader.h"
#include <sstream>
#include <string>

TEST(UTF32LE_Reader, utf32le)
{
    std::string input("\x79\0\0\0\xAC\x20\0\0", 8);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_32_LE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\x79\x20AC");
}

TEST(UTF32LE_Reader, invalid_utf32le_incomplete)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input("\xAC\x20\0", 3);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_32_LE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF32LE_Reader, invalid_utf32le_encoded_surrogate)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = std::string("\0\xD8\0\0", 4);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_32_LE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF32LE_Reader, invalid_utf32le_oversized_codepoint)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = std::string("\0\0\x11\0", 4);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(iss, Charset::UTF_32_LE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}
