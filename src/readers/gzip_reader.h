#pragma once

#include <zlib.h>
#include <istream>
#include <memory>
#include <utility>
#include <cstdio>

class GzipReader : private std::basic_streambuf<uint8_t>, public std::basic_istream<uint8_t>
{
public:
    GzipReader() noexcept;
    GzipReader(std::basic_istream<uint8_t>& in);
    GzipReader(const GzipReader&) = delete;
    GzipReader(GzipReader&& x) noexcept;
    ~GzipReader() noexcept override;
    GzipReader& operator=(const GzipReader&) = delete;
    GzipReader& operator=(GzipReader&& x) noexcept;

protected:
    std::basic_streambuf<uint8_t>::int_type underflow() override;

private:
    static constexpr size_t BUFFER_SIZE = 4096;

    std::basic_istream<uint8_t>* input_stream_ = nullptr;
    std::unique_ptr<uint8_t[]> input_buffer_;
    std::unique_ptr<uint8_t[]> output_buffer_;
    std::unique_ptr<z_stream> z_strm_ = nullptr;
    int z_err_ = Z_OK;
};

GzipReader::GzipReader() noexcept
    : std::basic_istream<uint8_t>(this)
{
}

GzipReader::GzipReader(std::basic_istream<uint8_t>& in)
    : std::basic_istream<uint8_t>(this),
      input_stream_(std::addressof(in)),
      input_buffer_(std::make_unique<uint8_t[]>(BUFFER_SIZE)),
      output_buffer_(std::make_unique<uint8_t[]>(BUFFER_SIZE)),
      z_strm_(std::make_unique<z_stream>())
{
    z_strm_->zalloc = Z_NULL;
    z_strm_->zfree  = Z_NULL;
    z_strm_->opaque = Z_NULL;
    z_err_ = inflateInit2(z_strm_.get(), MAX_WBITS + 16);
    if (z_err_ != Z_OK)
    {
        setstate(std::ios_base::badbit);
    }
}

GzipReader::GzipReader(GzipReader&& x) noexcept
    : std::basic_streambuf<uint8_t>(std::move(x)),
      std::basic_istream<uint8_t>(std::move(x)),
      input_stream_(std::exchange(x.input_stream_, nullptr)),
      input_buffer_(std::move(x.input_buffer_)),
      output_buffer_(std::move(x.output_buffer_)),
      z_strm_(std::move(x.z_strm_)),
      z_err_(std::exchange(x.z_err_, Z_OK))
{
    set_rdbuf(this);
}

GzipReader::~GzipReader() noexcept
{
    if (input_stream_ != nullptr)
    {
        inflateEnd(z_strm_.get());
    }
}

GzipReader& GzipReader::operator=(GzipReader&& x) noexcept
{
    if (std::addressof(x) != this)
    {
        if (input_stream_ != nullptr)
        {
            inflateEnd(z_strm_.get());
        }
        setg(x.eback(), x.gptr(), x.egptr());
        x.setg(nullptr, nullptr, nullptr);
        input_stream_ = std::exchange(x.input_stream_, nullptr);
        input_buffer_ = std::move(x.input_buffer_);
        output_buffer_ = std::move(x.output_buffer_);
        z_strm_ = std::move(x.z_strm_);
        z_err_ = std::exchange(x.z_err_, Z_OK);
    }
    return *this;
}

typename std::basic_streambuf<uint8_t>::int_type GzipReader::underflow()
{
    while (z_err_ == Z_OK && gptr() == egptr())
    {
        if (z_strm_->avail_in == 0)
        {
            z_strm_->avail_in = input_stream_->read(input_buffer_.get(), BUFFER_SIZE).gcount();
            z_strm_->next_in  = input_buffer_.get();
        }
        z_strm_->next_out  = output_buffer_.get();
        z_strm_->avail_out = BUFFER_SIZE;
        z_err_ = inflate(z_strm_.get(), Z_SYNC_FLUSH);
        //TODO process error code
        setg(output_buffer_.get(), output_buffer_.get(), output_buffer_.get() + BUFFER_SIZE - z_strm_->avail_out);
    }

    if (gptr() == egptr())
    {
        setstate(std::ios_base::eofbit);
        return EOF;
    }

    return *gptr();
}
