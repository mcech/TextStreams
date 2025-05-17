#include "gtest/gtest.h"

#include "text_stream_writer.h"
#include <sstream>
#include <string>

// TEST(Writer_Common, read_n)
// {
//     std::string input = "Hallo Welt!";
//     std::istringstream iss(input);

//     std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(iss, Charset::CP_850);
//     std::u32string output = writer->read(5);
//     EXPECT_EQ(output, U"Hallo");
// }

// TEST(Writer_Common, read_n_eof)
// {
//     std::string input = "Hallo Welt!";
//     std::istringstream iss(input);

//     std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(iss, Charset::CP_850);
//     std::u32string output = writer->read(15);
//     EXPECT_EQ(output, U"Hallo Welt!");
// }

// TEST(Writer_Common, readline)
// {
//     std::string input = "Zeile 1\r\nZeile 2\rZeile 3\nZeile 4";
//     std::istringstream iss(input);

//     std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(iss, Charset::CP_850);
//     std::u32string output = writer->read_line();
//     EXPECT_EQ(output, U"Zeile 1");
//     output = writer->read_line();
//     EXPECT_EQ(output, U"Zeile 2");
//     output = writer->read_line();
//     EXPECT_EQ(output, U"Zeile 3");
//     output = writer->read_line();
//     EXPECT_EQ(output, U"Zeile 4");
// }

// TEST(Writer_Common, construct_failure)
// {
//     std::string input = "";
//     ThrowingStreambuf streambuf(input, 0);
//     std::istream is(&streambuf);
//     is.exceptions(std::ios_base::failbit | std::ios_base::badbit);
//     EXPECT_THROW(TextStreamWriter::create(is, Charset::CP_850), std::ios::failure);
// }

// TEST(Writer_Common, read_n_failure)
// {
//     std::string input = "Zeile 1\r\nZeile 2\rZeile 3\nZeile 4";
//     ThrowingStreambuf streambuf(input, 1);
//     std::istream is(&streambuf);
//     is.exceptions(std::ios_base::failbit | std::ios_base::badbit);
//     std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(is, Charset::CP_850);
//     EXPECT_THROW(writer->read(5), std::ios::failure);
// }

// TEST(Writer_Common, readline_failure)
// {
//     for (size_t i = 1; i < 10; ++i)
//     {
//         std::string input = "Zeile 1\r\nZeile 2\rZeile 3\nZeile 4";
//         ThrowingStreambuf streambuf(input, i);
//         std::istream is(&streambuf);
//         is.exceptions(std::ios_base::failbit | std::ios_base::badbit);
//         std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(is, Charset::CP_850);
//         EXPECT_THROW(writer->read_line(), std::ios::failure);
//     }
// }

TEST(Writer_Common, unknown_encoding)
{
    std::ostringstream oss;
    EXPECT_THROW(TextStreamWriter::create(oss, static_cast<Charset>(255)), std::invalid_argument);
}

TEST(Writer_Common, unknown_newline)
{
    std::ostringstream oss;
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::CP_1252, static_cast<LineEndings>(255)), std::invalid_argument);
}
