#include "gtest/gtest.h"

#include "throwing_streambuf.h"
#include "text_stream_reader.h"
#include <sstream>
#include <string>

TEST(Reader_Common, read_n)
{
    std::string input = "Hallo Welt!";
    std::istringstream iss(input);

    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::CP_850);
    std::u32string output = reader->read(5);
    EXPECT_EQ(output, U"Hallo");
}

TEST(Reader_Common, read_n_eof)
{
    std::string input = "Hallo Welt!";
    std::istringstream iss(input);

    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::CP_850);
    std::u32string output = reader->read(15);
    EXPECT_EQ(output, U"Hallo Welt!");
}

TEST(Reader_Common, readline)
{
    std::string input = "Zeile 1\r\nZeile 2\rZeile 3\nZeile 4";
    std::istringstream iss(input);

    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::CP_850);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output, U"Zeile 1");
    output = reader->read_line();
    EXPECT_EQ(output, U"Zeile 2");
    output = reader->read_line();
    EXPECT_EQ(output, U"Zeile 3");
    output = reader->read_line();
    EXPECT_EQ(output, U"Zeile 4");
}

TEST(Reader_Common, construct_failure)
{
    std::string input = "";
    ThrowingStreambuf streambuf(input, 0);
    std::istream is(&streambuf);
    is.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    EXPECT_THROW(TextStreamReader::create(is, Charset::CP_850), std::ios::failure);
}

TEST(Reader_Common, read_n_failure)
{
    std::string input = "Zeile 1\r\nZeile 2\rZeile 3\nZeile 4";
    ThrowingStreambuf streambuf(input, 1);
    std::istream is(&streambuf);
    is.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(is, Charset::CP_850);
    EXPECT_THROW(reader->read(5), std::ios::failure);
}

TEST(Reader_Common, readline_failure)
{
    for (size_t i = 1; i < 10; ++i)
    {
        std::string input = "Zeile 1\r\nZeile 2\rZeile 3\nZeile 4";
        ThrowingStreambuf streambuf(input, i);
        std::istream is(&streambuf);
        is.exceptions(std::ios_base::failbit | std::ios_base::badbit);
        std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(is, Charset::CP_850);
        EXPECT_THROW(reader->read_line(), std::ios::failure);
    }
}

TEST(Reader_Common, unknown_encoding)
{
    std::string input = "Hallo Welt!";
    std::istringstream iss(input);
    EXPECT_THROW(TextStreamReader::create(iss, static_cast<Charset>(255)), std::invalid_argument);
}
