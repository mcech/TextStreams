#pragma once

#include <zlib.h>
#include <ostream>
// #include <memory>

class GzipWriter : private std::basic_streambuf<uint8_t>, public std::basic_ostream<uint8_t>
{
public:
    GzipWriter();
    explicit GzipWriter(std::basic_ostream<uint8_t>& out);
    GzipWriter(const GzipWriter&) = delete;
    GzipWriter(GzipWriter&& x) noexcept;
    ~GzipWriter() noexcept override;
    GzipWriter& operator=(const GzipWriter&) = delete;
    GzipWriter& operator=(GzipWriter&& x) noexcept;

protected:
    std::basic_streambuf<uint8_t>::int_type overflow(std::basic_streambuf<uint8_t>::int_type c = traits_type::eof()) override;

// private:
//     static constexpr size_t BUFFER_SIZE = 4096;

//     std::basic_istream<uint8_t>* input_stream_ = nullptr;
//     std::unique_ptr<uint8_t[]> input_buffer_;
//     std::unique_ptr<uint8_t[]> output_buffer_;
//     std::unique_ptr<z_stream> z_strm_ = nullptr;
//     int z_err_ = Z_OK;
};
