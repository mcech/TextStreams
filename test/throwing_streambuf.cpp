#include "throwing_streambuf.h"

#include <ios>

ThrowingStreambuf::ThrowingStreambuf(std::string& buffer, size_t max_accesses) : buffer_(buffer), max_accesses_(max_accesses)
{
    setg(buffer_.data(), buffer_.data(), buffer_.data());
}

int ThrowingStreambuf::overflow(int c)
{
    if (counter_ >= max_accesses_)
    {
        throw std::ios::failure("Access limit exceeded");
    }
    else if (counter_ < buffer_.length())
    {
        buffer_[counter_] = c;
        ++counter_;
        return c;
    }
    else
    {
        return EOF;
    }
}

std::streambuf::int_type ThrowingStreambuf::underflow()
{
    if (counter_ >= max_accesses_)
    {
        throw std::ios::failure("Access limit exceeded");
    }
    else if (counter_ < buffer_.length())
    {
        char c = buffer_[counter_];
        ++counter_;
        return c;
    }
    else
    {
        return EOF;
    }
}

std::streambuf::pos_type ThrowingStreambuf::seekoff(std::streambuf::off_type, std::ios_base::seekdir, std::ios_base::openmode)
{
    return 0;
}

std::streambuf::pos_type ThrowingStreambuf::seekpos(std::streambuf::pos_type, std::ios_base::openmode)
{
    return 0;
}
