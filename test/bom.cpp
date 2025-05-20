#include "gtest/gtest.h"

#include "bom.h"
#include "text_stream_reader.h"
#include "text_stream_writer.h"
#include "throwing_streambuf.h"
#include <sstream>
#include <string>

TEST(Reader_BOM, utf8)
{
    // Valid BOM
    std::string input = "\xEF\xBB\xBFHallo Welt!";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_8_BOM);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output[0], 'H');

    // Missing BOM
    input = "Hallo Welt!";
    iss.str(input);
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_8_BOM), std::ios::failure);

    // shorter than BOM
    input = "\xEF\xBB";
    iss.str(input);
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_8_BOM), std::ios::failure);
}

TEST(Reader_BOM, utf16le)
{
    // Valid BOM
    std::string input("\xFF\xFEH\0a\0l\0l\0o\0 \0W\0e\0l\0t\0!\0", 24);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_16_LE_BOM);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output[0], 'H');

    // Missing BOM
    input = "H\0a\0l\0l\0o\0 \0W\0e\0l\0t\0!\0";
    iss.str(input);
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_16_LE_BOM), std::ios::failure);

    // shorter than BOM
    input = "\xFF";
    iss.str(input);
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_16_LE_BOM), std::ios::failure);
}

TEST(Reader_BOM, utf16be)
{
    // Valid BOM
    std::string input("\xFE\xFF\0H\0a\0l\0l\0o\0 \0W\0e\0l\0t\0!", 24);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_16_BE_BOM);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output[0], 'H');

    // Missing BOM
    input = "\0H\0a\0l\0l\0o\0 \0W\0e\0l\0t\0!";
    iss.str(input);
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_16_BE_BOM), std::ios::failure);

    // shorter than BOM
    input = "\xFE";
    iss.str(input);
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_16_BE_BOM), std::ios::failure);
}

TEST(Reader_BOM, utf32le)
{
    // Valid BOM
    std::string input("\xFF\xFE\0\0H\0\0\0a\0\0\0l\0\0\0l\0\0\0o\0\0\0 \0\0\0W\0\0\0e\0\0\0l\0\0\0t\0\0\0!\0\0\0", 48);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_32_LE_BOM);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output[0], 'H');

    // Missing BOM
    input = "H\0\0\0a\0\0\0l\0\0\0l\0\0\0o\0\0\0 \0\0\0W\0\0\0e\0\0\0l\0\0\0t\0\0\0!\0\0\0";
    iss.str(input);
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_32_LE_BOM), std::ios::failure);

    // shorter than BOM
    input = "\xFF\xFE\0";
    iss.str(input);
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_32_LE_BOM), std::ios::failure);
}

TEST(Reader_BOM, utf32be)
{
    // Valid BOM
    std::string input("\0\0\xFE\xFF\0\0\0H\0\0\0a\0\0\0l\0\0\0l\0\0\0o\0\0\0 \0\0\0W\0\0\0e\0\0\0l\0\0\0t\0\0\0!", 48);
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::UTF_32_BE_BOM);
    std::u32string output = reader->read_line();
    EXPECT_EQ(output[0], 'H');

    // Missing BOM
    input = "\0\0\0H\0\0\0a\0\0\0l\0\0\0l\0\0\0o\0\0\0 \0\0\0W\0\0\0e\0\0\0l\0\0\0t\0\0\0!";
    iss.str(input);
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_32_BE_BOM), std::ios::failure);

    // shorter than BOM
    input = "\0\0\xFE";
    iss.str(input);
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_32_BE_BOM), std::ios::failure);
}

TEST(Writer_BOM, utf8)
{
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_8_BOM);
    EXPECT_EQ(memcmp(oss.str().data(), BOM_UTF8.data(), BOM_UTF8.size()), 0);
}

TEST(Writer_BOM, utf16le)
{
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_16_LE_BOM);
    EXPECT_EQ(memcmp(oss.str().data(), BOM_UTF16_LE.data(), BOM_UTF16_LE.size()), 0);
}

TEST(Writer_BOM, utf16be)
{
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_16_BE_BOM);
    EXPECT_EQ(memcmp(oss.str().data(), BOM_UTF16_BE.data(), BOM_UTF16_BE.size()), 0);
}

TEST(Writer_BOM, utf32le)
{
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_32_LE_BOM);
    EXPECT_EQ(memcmp(oss.str().data(), BOM_UTF32_LE.data(), BOM_UTF32_LE.size()), 0);
}

TEST(Writer_BOM, utf32be)
{
    std::ostringstream oss;
    std::unique_ptr<TextStreamWriter> writer = TextStreamWriter::create(oss, Charset::UTF_32_BE_BOM);
    EXPECT_EQ(memcmp(oss.str().data(), BOM_UTF32_BE.data(), BOM_UTF32_BE.size()), 0);
}

TEST(Writer_BOM, utf8_failure)
{
    std::string buffer = "    ";
    ThrowingStreambuf streambuf(buffer, 0);
    std::ostream os(&streambuf);
    os.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    EXPECT_THROW(TextStreamWriter::create(os, Charset::UTF_8_BOM), std::ios::failure);
}

TEST(Writer_BOM, utf16le_failure)
{
    std::string buffer = "    ";
    ThrowingStreambuf streambuf(buffer, 0);
    std::ostream os(&streambuf);
    os.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    EXPECT_THROW(TextStreamWriter::create(os, Charset::UTF_16_LE_BOM), std::ios::failure);
}

TEST(Writer_BOM, utf16be_failure)
{
    std::string buffer = "    ";
    ThrowingStreambuf streambuf(buffer, 0);
    std::ostream os(&streambuf);
    os.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    EXPECT_THROW(TextStreamWriter::create(os, Charset::UTF_16_BE_BOM), std::ios::failure);
}

TEST(Writer_BOM, utf32le_failure)
{
    std::string buffer = "    ";
    ThrowingStreambuf streambuf(buffer, 0);
    std::ostream os(&streambuf);
    os.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    EXPECT_THROW(TextStreamWriter::create(os, Charset::UTF_32_LE_BOM), std::ios::failure);
}

TEST(Writer_BOM, utf32be_failure)
{
    std::string buffer = "    ";
    ThrowingStreambuf streambuf(buffer, 0);
    std::ostream os(&streambuf);
    os.exceptions(std::ios_base::failbit | std::ios_base::badbit);
    EXPECT_THROW(TextStreamWriter::create(os, Charset::UTF_32_BE_BOM), std::ios::failure);
}



//TODO für alle writer: BOM darf nicht nochmal auftauchen. unit test dafür schreiben.
