#pragma once

#include <zlib.h>
#include <istream>
#include <memory>

class GzipReader : private std::basic_streambuf<uint8_t>, public std::basic_istream<uint8_t>
{
public:
    GzipReader();
    explicit GzipReader(std::basic_istream<uint8_t>& src);
    GzipReader(const GzipReader&) = delete;
    GzipReader(GzipReader&& x) noexcept;
    ~GzipReader() noexcept override;
    GzipReader& operator=(const GzipReader&) = delete;
    GzipReader& operator=(GzipReader&& x) noexcept;

protected:
    std::basic_streambuf<uint8_t>::int_type underflow() override;

private:
    static constexpr size_t BUFFER_SIZE = 4096;

    std::basic_istream<uint8_t>* src_ = nullptr;
    std::unique_ptr<uint8_t[]> in_;
    std::unique_ptr<uint8_t[]> out_;
    std::unique_ptr<z_stream> z_strm_ = nullptr;
    int z_err_ = Z_OK;
};
