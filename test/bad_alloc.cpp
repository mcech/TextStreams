#include "gtest/gtest.h"

#include "text_stream_reader.h"
#include <sstream>
#include <string>
#include <cstdlib>

static bool throw_bad_alloc = false;

void* operator new(size_t size)
{
    if (throw_bad_alloc)
    {
        throw std::bad_alloc();
    }
    else
    {
        void* p = malloc(size);
        if (p == nullptr)
        {
            throw std::bad_alloc();
        }
        else
        {
            return p;
        }
    }
}

void operator delete(void* p)
{
    free(p);
}

void operator delete(void* p, size_t)
{
    free(p);
}

TEST(Reader_bad_alloc, cp437)
{
    std::string input = "Hallo Welt!";
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::CP_437), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, cp850)
{
    std::string input = "Hallo Welt!";
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::CP_850), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, cp1252)
{
    std::string input = "Hallo Welt!";
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::CP_1252), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, iso8859_15)
{
    std::string input = "Hallo Welt!";
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::ISO_8859_15), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, utf8)
{
    std::string input = "Hallo Welt!";
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_8), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, utf16le)
{
    std::string input = "Hallo Welt!";
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_16_LE), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, utf16be)
{
    std::string input = "Hallo Welt!";
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_16_BE), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, utf32le)
{
    std::string input = "Hallo Welt!";
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_32_LE), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, utf32be)
{
    std::string input = "Hallo Welt!";
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_32_BE), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, utf8bom)
{
    std::string input = "\xEF\xBB\xBFHallo Welt!";
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_8_BOM), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, utf16lebom)
{
    std::string input("\xFF\xFEH\0a\0l\0l\0o\0 \0W\0e\0l\0t\0!\0", 24);
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_16_LE_BOM), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, utf16bebom)
{
    std::string input("\xFE\xFF\0H\0a\0l\0l\0o\0 \0W\0e\0l\0t\0!", 24);
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_16_BE_BOM), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, utf32lebom)
{
    std::string input("\xFF\xFE\0\0H\0\0\0a\0\0\0l\0\0\0l\0\0\0o\0\0\0 \0\0\0W\0\0\0e\0\0\0l\0\0\0t\0\0\0!\0\0\0", 48);
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_32_LE_BOM), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, utf32bebom)
{
    std::string input("\0\0\xFE\xFF\0\0\0H\0\0\0a\0\0\0l\0\0\0l\0\0\0o\0\0\0 \0\0\0W\0\0\0e\0\0\0l\0\0\0t\0\0\0!", 48);
    std::istringstream iss(input);
    throw_bad_alloc = true;
    EXPECT_THROW(TextStreamReader::create(iss, Charset::UTF_32_BE_BOM), std::bad_alloc);
    throw_bad_alloc = false;
}

TEST(Reader_bad_alloc, readline_bad_alloc)
{
    std::string input = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed eiusmod tempor incidunt ut "
                        "labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco "
                        "laboris nisi ut aliquid ex ea commodi consequat. Quis aute iure reprehenderit in voluptate "
                        "velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint obcaecat cupiditat non "
                        "proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
    std::istringstream iss(input);
    std::unique_ptr<TextStreamReader> reader = TextStreamReader::create(iss, Charset::CP_850);
    throw_bad_alloc = true;
    EXPECT_THROW(reader->read_line(), std::bad_alloc);
    throw_bad_alloc = false;
}
