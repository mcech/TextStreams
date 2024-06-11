#include "charset_detector.h"

#include "byte_order_mark.h"
#include "text_stream_reader.h"
#include <array>
#include <map>
#include <cstddef>
#include <cstdint>

namespace
{
    template <size_t N>
    bool check_bom(std::istream& in, const std::array<uint8_t, N>& bom)
    {
        std::array<uint8_t, N> prefix;
        for (size_t i = 0; i < N; ++i)
        {
            int32_t b = in.get();
            if (b == EOF)
            {
                in.clear();
                in.seekg(0, std::ios::beg);
                return false;
            }
            prefix[i] = b;
        }
        in.clear();
        in.seekg(0, std::ios::beg);
        return prefix == bom;
    }

    double check_reader(TextStreamReader& in)
    {
        uint64_t failures = 0;
        uint64_t total = 0;
        char32_t c = 0;
        do
        {
            try
            {
                c = in.read();
            }
            catch (...)
            {
                ++failures;
            }
            ++total;
        } while (c != EOF);
        return static_cast<double>(failures) / static_cast<double>(total);
    }
}

Charset CharsetDetector::detect(std::istream& in)
{
    if (check_bom(in, ByteOrderMark::BOM_UTF8))
    {
        return Charset::UTF_8_BOM;
    }
    else if (check_bom(in, ByteOrderMark::BOM_UTF32_LE))
    {
        return Charset::UTF_32_LE_BOM;
    }
    else if (check_bom(in, ByteOrderMark::BOM_UTF32_BE))
    {
        return Charset::UTF_32_BE_BOM;
    }
    else if (check_bom(in, ByteOrderMark::BOM_UTF16_LE))
    {
        return Charset::UTF_16_LE_BOM;
    }
    else if (check_bom(in, ByteOrderMark::BOM_UTF16_BE))
    {
        return Charset::UTF_16_BE_BOM;
    }

    std::initializer_list<Charset> charsets = {Charset::CP_437,
                                               Charset::CP_850,
                                               Charset::CP_1252,
                                               Charset::ISO_8859_15,
                                               Charset::UTF_8,
                                               Charset::UTF_16_LE,
                                               Charset::UTF_16_BE,
                                               Charset::UTF_32_LE,
                                               Charset::UTF_32_BE};
    std::multimap<double, Charset> fail_rate;
    for (Charset cs : charsets)
    {
        std::unique_ptr<TextStreamReader> reader = TextStreamReader::open(in, cs);
        in.clear();
        in.seekg(0, std::ios::beg);
        fail_rate.emplace(check_reader(*reader), cs);
    }
    return fail_rate.begin()->second;
}
