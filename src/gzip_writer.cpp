#include "gzip_writer.h"

#include <utility>

GzipWriter::GzipWriter() : std::basic_istream<uint8_t>(this)
{
}

