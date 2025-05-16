#pragma once

#include <ios>
#include <streambuf>

class ThrowingStreambuf : public std::streambuf
{
public:
    explicit ThrowingStreambuf(std::string& buffer, size_t max_underflows);

protected:
    std::streambuf::int_type underflow() override;
    std::streambuf::pos_type seekoff(std::streambuf::off_type, std::ios_base::seekdir, std::ios_base::openmode = std::ios_base::in | std::ios_base::out) override;
    std::streambuf::pos_type seekpos(std::streambuf::pos_type, std::ios_base::openmode = std::ios_base::in | std::ios_base::out) override;

private:
    std::string& buffer_;
    const size_t max_underflows_;
    size_t position_ = 0;
};

inline ThrowingStreambuf::ThrowingStreambuf(std::string& buffer, size_t max_underflows) : buffer_(buffer), max_underflows_(max_underflows)
{
    setg(buffer_.data(), buffer_.data(), buffer_.data());
}

inline std::streambuf::int_type ThrowingStreambuf::underflow()
{
    if (position_ >= max_underflows_)
    {
        throw std::ios::failure("Underflow limit exceeded");
    }
    else if (position_ < buffer_.length())
    {
        char c = buffer_[position_];
        ++position_;
        return c;
    }
    else
    {
        return EOF;
    }
}

inline std::streambuf::pos_type ThrowingStreambuf::seekoff(std::streambuf::off_type, std::ios_base::seekdir, std::ios_base::openmode)
{
    return 0;
}

inline std::streambuf::pos_type ThrowingStreambuf::seekpos(std::streambuf::pos_type, std::ios_base::openmode)
{
    return 0;
}
