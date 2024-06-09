#pragma once

enum class Charset
{
    CP_437,
    CP_850,
    CP_1252,
    ISO_8859_1 [[deprecated]] = CP_1252,
    ISO_8859_15,

    UTF_8,
    UTF_16_LE,
    UTF_16_BE,
    UTF_32_LE,
    UTF_32_BE,

    UTF_8_BOM,
    UTF_16_LE_BOM,
    UTF_16_BE_BOM,
    UTF_32_LE_BOM,
    UTF_32_BE_BOM
};
