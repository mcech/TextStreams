#include "gtest/gtest.h"

#include "text_stream_writer.h"
#include <sstream>
#include <string>

TEST(Writer_Common, writeline_dos)
{
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::CP_1252, LineEndings::DOS);
    writer->write_line(U"Zeile 1");
    writer->write_line(U"Zeile 2");
    EXPECT_EQ(oss.str(), "Zeile 1\r\nZeile 2\r\n");
}

TEST(Writer_Common, writeline_mac)
{
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::CP_1252, LineEndings::MAC);
    writer->write_line(U"Zeile 1");
    writer->write_line(U"Zeile 2");
    EXPECT_EQ(oss.str(), "Zeile 1\rZeile 2\r");
}

TEST(Writer_Common, writeline_unix)
{
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::CP_1252, LineEndings::UNIX);
    writer->write_line(U"Zeile 1");
    writer->write_line(U"Zeile 2");
    EXPECT_EQ(oss.str(), "Zeile 1\nZeile 2\n");
}

TEST(Writer_Common, writeline_invalid)
{
    std::ostringstream oss;
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::CP_1252, static_cast<LineEndings>(255)), std::invalid_argument);
}

TEST(Writer_Common, unknown_encoding)
{
    std::ostringstream oss;
    EXPECT_THROW(TextStreamWriter::create(oss, static_cast<Charset>(255)), std::invalid_argument);
}

TEST(Writer_Common, unknown_newline)
{
    std::ostringstream oss;
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::CP_437, static_cast<LineEndings>(255)), std::invalid_argument);
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::CP_850, static_cast<LineEndings>(255)), std::invalid_argument);
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::CP_1252, static_cast<LineEndings>(255)), std::invalid_argument);
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::ISO_8859_15, static_cast<LineEndings>(255)), std::invalid_argument);
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::UTF_8, static_cast<LineEndings>(255)), std::invalid_argument);
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::UTF_16_LE, static_cast<LineEndings>(255)), std::invalid_argument);
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::UTF_16_BE, static_cast<LineEndings>(255)), std::invalid_argument);
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::UTF_32_LE, static_cast<LineEndings>(255)), std::invalid_argument);
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::UTF_32_BE, static_cast<LineEndings>(255)), std::invalid_argument);
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::UTF_8_BOM, static_cast<LineEndings>(255)), std::invalid_argument);
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::UTF_16_LE_BOM, static_cast<LineEndings>(255)), std::invalid_argument);
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::UTF_16_BE_BOM, static_cast<LineEndings>(255)), std::invalid_argument);
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::UTF_32_LE_BOM, static_cast<LineEndings>(255)), std::invalid_argument);
    EXPECT_THROW(TextStreamWriter::create(oss, Charset::UTF_32_BE_BOM, static_cast<LineEndings>(255)), std::invalid_argument);
}
