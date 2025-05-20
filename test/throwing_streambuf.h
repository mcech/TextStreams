#pragma once

#include <streambuf>

class ThrowingStreambuf : public std::streambuf
{
public:
    explicit ThrowingStreambuf(std::string& buffer, size_t max_accesses);

protected:
    int overflow(int c = EOF);
    std::streambuf::int_type underflow() override;
    std::streambuf::pos_type seekoff(std::streambuf::off_type, std::ios_base::seekdir, std::ios_base::openmode = std::ios_base::in | std::ios_base::out) override;
    std::streambuf::pos_type seekpos(std::streambuf::pos_type, std::ios_base::openmode = std::ios_base::in | std::ios_base::out) override;

private:
    std::string& buffer_;
    const size_t max_accesses_;
    size_t counter_ = 0;
};
