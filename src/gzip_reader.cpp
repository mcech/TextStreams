#include "gzip_reader.h"

#include <utility>
#include <cstdio>

GzipReader::GzipReader() : std::basic_istream<uint8_t>(this)
{
}

GzipReader::GzipReader(std::basic_istream<uint8_t>& in)
    : std::basic_istream<uint8_t>(this),
      src_(std::addressof(in)),
      in_(std::make_unique<uint8_t[]>(BUFFER_SIZE)),
      out_(std::make_unique<uint8_t[]>(BUFFER_SIZE)),
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

GzipReader::GzipReader(GzipReader&& x) noexcept : std::basic_istream<uint8_t>(this)
{
    setg(x.eback(), x.gptr(), x.egptr());
    x.setg(nullptr, nullptr, nullptr);
    src_ = std::exchange(x.src_, nullptr);
    in_  = std::move(x.in_);
    out_ = std::move(x.out_);
    z_strm_ = std::move(x.z_strm_);
    z_err_  = std::exchange(x.z_err_, Z_OK);
}

GzipReader::~GzipReader() noexcept
{
    if (src_ != nullptr)
    {
        inflateEnd(z_strm_.get());
    }
}

GzipReader& GzipReader::operator=(GzipReader&& x) noexcept
{
    if (std::addressof(x) != this)
    {
        if (src_ != nullptr)
        {
            inflateEnd(z_strm_.get());
        }
        setg(x.eback(), x.gptr(), x.egptr());
        x.setg(nullptr, nullptr, nullptr);
        src_ = std::exchange(x.src_, nullptr);
        in_  = std::move(x.in_);
        out_ = std::move(x.out_);
        z_strm_ = std::move(x.z_strm_);
        z_err_  = std::exchange(x.z_err_, Z_OK);
    }
    return *this;
}

typename std::basic_streambuf<uint8_t>::int_type GzipReader::underflow()
{
    while (z_err_ == Z_OK && gptr() == egptr())
    {
        if (z_strm_->avail_in == 0)
        {
            z_strm_->avail_in = src_->read(in_.get(), BUFFER_SIZE).gcount();
            z_strm_->next_in  = in_.get();
        }
        z_strm_->next_out  = out_.get();
        z_strm_->avail_out = BUFFER_SIZE;
        z_err_ = inflate(z_strm_.get(), Z_SYNC_FLUSH);
        //TODO process error code
        setg(out_.get(), out_.get(), out_.get() + BUFFER_SIZE - z_strm_->avail_out);
    }

    if (gptr() == egptr())
    {
        setstate(std::ios_base::eofbit);
        return EOF;
    }

    return *gptr();
}
