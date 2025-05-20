#include "gtest/gtest.h"

#include "text_stream_reader.h"
#include <sstream>
#include <string>

TEST(UTF32BE_Reader, utf32be_single_word)
{
    std::string input("\0\0\0\x79\0\0\x20\xAC", 8);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_32_BE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\x79\x20AC");
}

TEST(UTF32BE_Reader, invalid_utf32be_incomplete_first_word)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input("\0\0\x20", 3);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_32_BE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF32BE_Reader, invalid_utf32be_encoded_surrogate)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = std::string("\0\0\xD8\0", 4);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_32_BE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}

TEST(UTF32BE_Reader, invalid_utf32be_oversized_codepoint)
{
    std::ostringstream oss;
    std::streambuf* cerr_buf = std::cerr.rdbuf();
    std::cerr.rdbuf(oss.rdbuf());

    std::string input = std::string("\0\x11\0\0", 4);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_32_BE);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"\xFFFD");
    EXPECT_TRUE(oss.str().starts_with("Warning"));

    std::cerr.rdbuf(cerr_buf);
}
