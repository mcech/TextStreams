// TODO separate class CharsetDetector
// - https://github.com/chardet/chardet/blob/main/chardet/universaldetector.py
// - https://github.com/nijel/enca

#include "charset.h"
#include <istream>

namespace CharsetDetector
{
    Charset detect(std::istream& in);
};
