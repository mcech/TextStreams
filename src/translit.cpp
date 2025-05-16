#include <unordered_map>

std::unordered_map<int, const char*> transliterations = 
{
    {0x00A0, " "},        // no-break space
    {0x00A1, "!"},        // inverted exclamation mark
    {0x00A2, "c"},        // cent sign
    {0x00A3, "lb"},       // pound sign
    {0x00A4, ""},         // currency sign
    {0x00A5, "yen"},      // yen sign
    {0x00A6, "|"},        // broken bar
    {0x00A7, "SS"},       // section sign
    {0x00A8, "\""},       // diaeresis
    {0x00A9, "(c)"},      // copyright sign
    {0x00AA, "a"},        // feminine ordinal indicator
    {0x00AB, "<<"},       // left-pointing double angle quotation mark
    {0x00AC, "not"},      // not sign
    {0x00AD, "-"},        // soft hyphen
    {0x00AE, "(R)"},      // registered sign
    {0x00AF, ""},         // macron
    {0x00B0, "^0"},       // degree sign
    {0x00B1, "+/-"},      // plus-minus sign
    {0x00B2, "^2"},       // superscript two
    {0x00B3, "^3"},       // superscript three
    {0x00B4, "'"},        // acute accent
    {0x00B5, "u"},        // micro sign
    {0x00B6, "P"},        // pilcrow sign
    {0x00B7, "."},        // middle dot
    {0x00B8, ","},        // cedilla
    {0x00B9, "^1"},       // superscript one
    {0x00BA, "o"},        // masculine ordinal indicator
    {0x00BB, ">>"},       // right-pointing double angle quotation mark
    {0x00BF, "?"},        // inverted question mark
    {0x00C0, "`A"},       // latin capital letter a with grave
    {0x00C2, "^A"},       // latin capital letter a with circumflex
    {0x00C3, "~A"},       // latin capital letter a with tilde
    {0x00C4, "\"A"},      // latin capital letter a with diaeresis
    {0x00C5, "A"},        // latin capital letter a with ring above
    {0x00C6, "AE"},       // latin capital letter ae
    {0x00C7, "C"},        // latin capital letter c with cedilla
    {0x00C8, "`E"},       // latin capital letter e with grave
    {0x00CA, "^E"},       // latin capital letter e with circumflex
    {0x00CB, "\"E"},      // latin capital letter e with diaeresis
    {0x00CC, "`I"},       // latin capital letter i with grave
    {0x00CE, "^I"},       // latin capital letter i with circumflex
    {0x00CF, "\"I"},      // latin capital letter i with diaeresis
    {0x00D0, "D"},        // latin capital letter eth
    {0x00D1, "~N"},       // latin capital letter n with tilde
    {0x00D2, "`O"},       // latin capital letter o with grave
    {0x00D4, "^O"},       // latin capital letter o with circumflex
    {0x00D5, "~O"},       // latin capital letter o with tilde
    {0x00D6, "\"O"},      // latin capital letter o with diaeresis
    {0x00D7, "x"},        // multiplication sign
    {0x00D8, "O"},        // latin capital letter o with stroke
    {0x00D9, "`U"},       // latin capital letter u with grave
    {0x00DB, "^U"},       // latin capital letter u with circumflex
    {0x00DC, "\"U"},      // latin capital letter u with diaeresis
    {0x00DE, "Th"},       // latin capital letter thorn
    {0x00DF, "ss"},       // latin small letter sharp s
    {0x00E0, "`a"},       // latin small letter a with grave
    {0x00E2, "^a"},       // latin small letter a with circumflex
    {0x00E3, "~a"},       // latin small letter a with tilde
    {0x00E4, "\"a"},      // latin small letter a with diaeresis
    {0x00E5, "a"},        // latin small letter a with ring above
    {0x00E6, "ae"},       // latin small letter ae
    {0x00E7, "c"},        // latin small letter c with cedilla
    {0x00E8, "`e"},       // latin small letter e with grave
    {0x00EA, "^e"},       // latin small letter e with circumflex
    {0x00EB, "\"e"},      // latin small letter e with diaeresis
    {0x00EC, "`i"},       // latin small letter i with grave
    {0x00EE, "^i"},       // latin small letter i with circumflex
    {0x00EF, "\"i"},      // latin small letter i with diaeresis
    {0x00F0, "d"},        // latin small letter eth
    {0x00F1, "~n"},       // latin small letter n with tilde
    {0x00F2, "`o"},       // latin small letter o with grave
    {0x00F4, "^o"},       // latin small letter o with circumflex
    {0x00F5, "~o"},       // latin small letter o with tilde
    {0x00F6, "\"o"},      // latin small letter o with diaeresis
    {0x00F7, ":"},        // division sign
    {0x00F8, "o"},        // latin small letter o with stroke
    {0x00F9, "`u"},       // latin small letter u with grave
    {0x00FB, "^u"},       // latin small letter u with circumflex
    {0x00FC, "\"u"},      // latin small letter u with diaeresis
    {0x00FE, "th"},       // latin small letter thorn
    {0x00FF, "\"y"},      // latin small letter y with diaeresis
    {0x0100, "A"},        // latin capital letter a with macron
    {0x0101, "a"},        // latin small letter a with macron
    {0x0102, "A"},        // latin capital letter a with breve
    {0x0103, "a"},        // latin small letter a with breve
    {0x0104, "A"},        // latin capital letter a with ogonek
    {0x0105, "a"},        // latin small letter a with ogonek
    {0x0108, "^C"},       // latin capital letter c with circumflex
    {0x0109, "^c"},       // latin small letter c with circumflex
    {0x010A, "C"},        // latin capital letter c with dot above
    {0x010B, "c"},        // latin small letter c with dot above
    {0x010C, "C"},        // latin capital letter c with caron
    {0x010D, "c"},        // latin small letter c with caron
    {0x010E, "D"},        // latin capital letter d with caron
    {0x010F, "d"},        // latin small letter d with caron
    {0x0110, "D"},        // latin capital letter d with stroke
    {0x0111, "d"},        // latin small letter d with stroke
    {0x0112, "E"},        // latin capital letter e with macron
    {0x0113, "e"},        // latin small letter e with macron
    {0x0114, "E"},        // latin capital letter e with breve
    {0x0115, "e"},        // latin small letter e with breve
    {0x0116, "E"},        // latin capital letter e with dot above
    {0x0117, "e"},        // latin small letter e with dot above
    {0x0118, "E"},        // latin capital letter e with ogonek
    {0x0119, "e"},        // latin small letter e with ogonek
    {0x011A, "E"},        // latin capital letter e with caron
    {0x011B, "e"},        // latin small letter e with caron
    {0x011C, "^G"},       // latin capital letter g with circumflex
    {0x011D, "^g"},       // latin small letter g with circumflex
    {0x011E, "G"},        // latin capital letter g with breve
    {0x011F, "g"},        // latin small letter g with breve
    {0x0120, "G"},        // latin capital letter g with dot above
    {0x0121, "g"},        // latin small letter g with dot above
    {0x0122, "G"},        // latin capital letter g with cedilla
    {0x0123, "g"},        // latin small letter g with cedilla
    {0x0124, "^H"},       // latin capital letter h with circumflex
    {0x0125, "^h"},       // latin small letter h with circumflex
    {0x0126, "H"},        // latin capital letter h with stroke
    {0x0127, "h"},        // latin small letter h with stroke
    {0x0128, "~I"},       // latin capital letter i with tilde
    {0x0129, "~i"},       // latin small letter i with tilde
    {0x012A, "I"},        // latin capital letter i with macron
    {0x012B, "i"},        // latin small letter i with macron
    {0x012C, "I"},        // latin capital letter i with breve
    {0x012D, "i"},        // latin small letter i with breve
    {0x012E, "I"},        // latin capital letter i with ogonek
    {0x012F, "i"},        // latin small letter i with ogonek
    {0x0130, "I"},        // latin capital letter i with dot above
    {0x0131, "i"},        // latin small letter dotless i
    {0x0132, "IJ"},       // latin capital ligature ij
    {0x0133, "ij"},       // latin small ligature ij
    {0x0134, "^J"},       // latin capital letter j with circumflex
    {0x0135, "^j"},       // latin small letter j with circumflex
    {0x0136, "K"},        // latin capital letter k with cedilla
    {0x0137, "k"},        // latin small letter k with cedilla
    {0x0138, ""},         // latin small letter kra
    {0x0139, "L"},        // latin capital letter l with acute
    {0x013A, "l"},        // latin small letter l with acute
    {0x013B, "L"},        // latin capital letter l with cedilla
    {0x013C, "l"},        // latin small letter l with cedilla
    {0x013D, "L"},        // latin capital letter l with caron
    {0x013E, "l"},        // latin small letter l with caron
    {0x013F, "L"},        // latin capital letter l with middle dot
    {0x0140, "l"},        // latin small letter l with middle dot
    {0x0141, "L"},        // latin capital letter l with stroke
    {0x0142, "l"},        // latin small letter l with stroke
    {0x0145, "N"},        // latin capital letter n with cedilla
    {0x0146, "n"},        // latin small letter n with cedilla
    {0x0147, "N"},        // latin capital letter n with caron
    {0x0148, "n"},        // latin small letter n with caron
    {0x0149, "'n"},       // latin small letter n preceded by apostrophe
    {0x014A, ""},         // latin capital letter eng
    {0x014B, ""},         // latin small letter eng
    {0x014C, "O"},        // latin capital letter o with macron
    {0x014D, "o"},        // latin small letter o with macron
    {0x014E, "O"},        // latin capital letter o with breve
    {0x014F, "o"},        // latin small letter o with breve
    {0x0150, "\"O"},      // latin capital letter o with double acute
    {0x0151, "\"o"},      // latin small letter o with double acute
    {0x0152, "OE"},       // latin capital ligature oe
    {0x0153, "oe"},       // latin small ligature oe
    {0x0156, "R"},        // latin capital letter r with cedilla
    {0x0157, "r"},        // latin small letter r with cedilla
    {0x0158, "R"},        // latin capital letter r with caron
    {0x0159, "r"},        // latin small letter r with caron
    {0x015C, "^S"},       // latin capital letter s with circumflex
    {0x015D, "^s"},       // latin small letter s with circumflex
    {0x015E, "S"},        // latin capital letter s with cedilla
    {0x015F, "s"},        // latin small letter s with cedilla
    {0x0160, "S"},        // latin capital letter s with caron
    {0x0161, "s"},        // latin small letter s with caron
    {0x0162, "T"},        // latin capital letter t with cedilla
    {0x0163, "t"},        // latin small letter t with cedilla
    {0x0164, "T"},        // latin capital letter t with caron
    {0x0165, "t"},        // latin small letter t with caron
    {0x0166, "T"},        // latin capital letter t with stroke
    {0x0167, "t"},        // latin small letter t with stroke
    {0x0168, "~U"},       // latin capital letter u with tilde
    {0x0169, "~u"},       // latin small letter u with tilde
    {0x016A, "U"},        // latin capital letter u with macron
    {0x016B, "u"},        // latin small letter u with macron
    {0x016C, "U"},        // latin capital letter u with breve
    {0x016D, "u"},        // latin small letter u with breve
    {0x016E, "U"},        // latin capital letter u with ring above
    {0x016F, "u"},        // latin small letter u with ring above
    {0x0170, "\"U"},      // latin capital letter u with double acute
    {0x0171, "\"u"},      // latin small letter u with double acute
    {0x0172, "U"},        // latin capital letter u with ogonek
    {0x0173, "u"},        // latin small letter u with ogonek
    {0x0174, "^W"},       // latin capital letter w with circumflex
    {0x0175, "^w"},       // latin small letter w with circumflex
    {0x0176, "^Y"},       // latin capital letter y with circumflex
    {0x0177, "^y"},       // latin small letter y with circumflex
    {0x0178, "\"Y"},      // latin capital letter y with diaeresis
    {0x017B, "Z"},        // latin capital letter z with dot above
    {0x017C, "z"},        // latin small letter z with dot above
    {0x017D, "Z"},        // latin capital letter z with caron
    {0x017E, "z"},        // latin small letter z with caron
    {0x017F, "s"},        // latin small letter long s
    {0x018F, ""},         // latin capital letter schwa
    {0x0192, "f"},        // latin small letter f with hook
    {0x01C7, "LJ"},       // latin capital letter lj
    {0x01C8, "Lj"},       // latin capital letter l with small letter j
    {0x01C9, "lj"},       // latin small letter lj
    {0x01CA, "NJ"},       // latin capital letter nj
    {0x01CB, "Nj"},       // latin capital letter n with small letter j
    {0x01CC, "nj"},       // latin small letter nj
    {0x01F1, "DZ"},       // latin capital letter dz
    {0x01F2, "Dz"},       // latin capital letter d with small letter z
    {0x01F3, "dz"},       // latin small letter dz
    {0x0218, "S"},        // latin capital letter s with comma below
    {0x0219, "s"},        // latin small letter s with comma below
    {0x021A, "T"},        // latin capital letter t with comma below
    {0x021B, "t"},        // latin small letter t with comma below
    {0x0259, ""},         // latin small letter schwa
    {0x02C6, "^"},        // modifier letter circumflex accent
    {0x02C7, ""},         // caron
    {0x02C8, "'"},        // modifier letter vertical line
    {0x02CB, "`"},        // modifier letter grave accent
    {0x02CD, "_"},        // modifier letter low macron
    {0x02D8, ""},         // breve
    {0x02D9, ""},         // dot above
    {0x02DA, ""},         // ring above
    {0x02DB, ""},         // ogonek
    {0x02DC, "~"},        // small tilde
    {0x02DD, "\""},       // double acute accent
    {0x0374, ""},         // greek numeral sign
    {0x0375, ""},         // greek lower numeral sign
    {0x037A, ""},         // greek ypogegrammeni
    {0x037E, ""},         // greek question mark
    {0x0384, ""},         // greek tonos
    {0x0385, ""},         // greek dialytika tonos
    {0x0386, ""},         // greek capital letter alpha with tonos
    {0x0387, ""},         // greek ano teleia
    {0x0388, ""},         // greek capital letter epsilon with tonos
    {0x0389, ""},         // greek capital letter eta with tonos
    {0x038A, ""},         // greek capital letter iota with tonos
    {0x038C, ""},         // greek capital letter omicron with tonos
    {0x038E, ""},         // greek capital letter upsilon with tonos
    {0x038F, ""},         // greek capital letter omega with tonos
    {0x0390, ""},         // greek small letter iota with dialytika and tonos
    {0x0391, ""},         // greek capital letter alpha
    {0x0392, ""},         // greek capital letter beta
    {0x0393, ""},         // greek capital letter gamma
    {0x0394, ""},         // greek capital letter delta
    {0x0395, ""},         // greek capital letter epsilon
    {0x0396, ""},         // greek capital letter zeta
    {0x0397, ""},         // greek capital letter eta
    {0x0398, ""},         // greek capital letter theta
    {0x0399, ""},         // greek capital letter iota
    {0x039A, ""},         // greek capital letter kappa
    {0x039B, ""},         // greek capital letter lamda
    {0x039C, ""},         // greek capital letter mu
    {0x039D, ""},         // greek capital letter nu
    {0x039E, ""},         // greek capital letter xi
    {0x039F, ""},         // greek capital letter omicron
    {0x03A0, ""},         // greek capital letter pi
    {0x03A1, ""},         // greek capital letter rho
    {0x03A3, ""},         // greek capital letter sigma
    {0x03A4, ""},         // greek capital letter tau
    {0x03A5, ""},         // greek capital letter upsilon
    {0x03A6, ""},         // greek capital letter phi
    {0x03A7, ""},         // greek capital letter chi
    {0x03A8, ""},         // greek capital letter psi
    {0x03A9, ""},         // greek capital letter omega
    {0x03AA, ""},         // greek capital letter iota with dialytika
    {0x03AB, ""},         // greek capital letter upsilon with dialytika
    {0x03AC, ""},         // greek small letter alpha with tonos
    {0x03AD, ""},         // greek small letter epsilon with tonos
    {0x03AE, ""},         // greek small letter eta with tonos
    {0x03AF, ""},         // greek small letter iota with tonos
    {0x03B0, ""},         // greek small letter upsilon with dialytika and tonos
    {0x03B1, ""},         // greek small letter alpha
    {0x03B2, ""},         // greek small letter beta
    {0x03B3, ""},         // greek small letter gamma
    {0x03B4, ""},         // greek small letter delta
    {0x03B5, ""},         // greek small letter epsilon
    {0x03B6, ""},         // greek small letter zeta
    {0x03B7, ""},         // greek small letter eta
    {0x03B8, ""},         // greek small letter theta
    {0x03B9, ""},         // greek small letter iota
    {0x03BA, ""},         // greek small letter kappa
    {0x03BB, ""},         // greek small letter lamda
    {0x03BC, ""},         // greek small letter mu
    {0x03BD, ""},         // greek small letter nu
    {0x03BE, ""},         // greek small letter xi
    {0x03BF, ""},         // greek small letter omicron
    {0x03C0, ""},         // greek small letter pi
    {0x03C1, ""},         // greek small letter rho
    {0x03C2, ""},         // greek small letter final sigma
    {0x03C3, ""},         // greek small letter sigma
    {0x03C4, ""},         // greek small letter tau
    {0x03C5, ""},         // greek small letter upsilon
    {0x03C6, ""},         // greek small letter phi
    {0x03C7, ""},         // greek small letter chi
    {0x03C8, ""},         // greek small letter psi
    {0x03C9, ""},         // greek small letter omega
    {0x03CA, ""},         // greek small letter iota with dialytika
    {0x03CB, ""},         // greek small letter upsilon with dialytika
    {0x03CC, ""},         // greek small letter omicron with tonos
    {0x03CD, ""},         // greek small letter upsilon with tonos
    {0x03CE, ""},         // greek small letter omega with tonos
    {0x0401, ""},         // cyrillic capital letter io
    {0x0402, ""},         // cyrillic capital letter dje
    {0x0403, ""},         // cyrillic capital letter gje
    {0x0404, ""},         // cyrillic capital letter ukrainian ie
    {0x0405, ""},         // cyrillic capital letter dze
    {0x0406, ""},         // cyrillic capital letter byelorussian-ukrainian i
    {0x0407, ""},         // cyrillic capital letter yi
    {0x0408, ""},         // cyrillic capital letter je
    {0x0409, ""},         // cyrillic capital letter lje
    {0x040A, ""},         // cyrillic capital letter nje
    {0x040B, ""},         // cyrillic capital letter tshe
    {0x040C, ""},         // cyrillic capital letter kje
    {0x040E, ""},         // cyrillic capital letter short u
    {0x040F, ""},         // cyrillic capital letter dzhe
    {0x0410, ""},         // cyrillic capital letter a
    {0x0411, ""},         // cyrillic capital letter be
    {0x0412, ""},         // cyrillic capital letter ve
    {0x0413, ""},         // cyrillic capital letter ghe
    {0x0414, ""},         // cyrillic capital letter de
    {0x0415, ""},         // cyrillic capital letter ie
    {0x0416, ""},         // cyrillic capital letter zhe
    {0x0417, ""},         // cyrillic capital letter ze
    {0x0418, ""},         // cyrillic capital letter i
    {0x0419, ""},         // cyrillic capital letter short i
    {0x041A, ""},         // cyrillic capital letter ka
    {0x041B, ""},         // cyrillic capital letter el
    {0x041C, ""},         // cyrillic capital letter em
    {0x041D, ""},         // cyrillic capital letter en
    {0x041E, ""},         // cyrillic capital letter o
    {0x041F, ""},         // cyrillic capital letter pe
    {0x0420, ""},         // cyrillic capital letter er
    {0x0421, ""},         // cyrillic capital letter es
    {0x0422, ""},         // cyrillic capital letter te
    {0x0423, ""},         // cyrillic capital letter u
    {0x0424, ""},         // cyrillic capital letter ef
    {0x0425, ""},         // cyrillic capital letter ha
    {0x0426, ""},         // cyrillic capital letter tse
    {0x0427, ""},         // cyrillic capital letter che
    {0x0428, ""},         // cyrillic capital letter sha
    {0x0429, ""},         // cyrillic capital letter shcha
    {0x042A, ""},         // cyrillic capital letter hard sign
    {0x042B, ""},         // cyrillic capital letter yeru
    {0x042C, ""},         // cyrillic capital letter soft sign
    {0x042D, ""},         // cyrillic capital letter e
    {0x042E, ""},         // cyrillic capital letter yu
    {0x042F, ""},         // cyrillic capital letter ya
    {0x0430, ""},         // cyrillic small letter a
    {0x0431, ""},         // cyrillic small letter be
    {0x0432, ""},         // cyrillic small letter ve
    {0x0433, ""},         // cyrillic small letter ghe
    {0x0434, ""},         // cyrillic small letter de
    {0x0435, ""},         // cyrillic small letter ie
    {0x0436, ""},         // cyrillic small letter zhe
    {0x0437, ""},         // cyrillic small letter ze
    {0x0438, ""},         // cyrillic small letter i
    {0x0439, ""},         // cyrillic small letter short i
    {0x043A, ""},         // cyrillic small letter ka
    {0x043B, ""},         // cyrillic small letter el
    {0x043C, ""},         // cyrillic small letter em
    {0x043D, ""},         // cyrillic small letter en
    {0x043E, ""},         // cyrillic small letter o
    {0x043F, ""},         // cyrillic small letter pe
    {0x0440, ""},         // cyrillic small letter er
    {0x0441, ""},         // cyrillic small letter es
    {0x0442, ""},         // cyrillic small letter te
    {0x0443, ""},         // cyrillic small letter u
    {0x0444, ""},         // cyrillic small letter ef
    {0x0445, ""},         // cyrillic small letter ha
    {0x0446, ""},         // cyrillic small letter tse
    {0x0447, ""},         // cyrillic small letter che
    {0x0448, ""},         // cyrillic small letter sha
    {0x0449, ""},         // cyrillic small letter shcha
    {0x044A, ""},         // cyrillic small letter hard sign
    {0x044B, ""},         // cyrillic small letter yeru
    {0x044C, ""},         // cyrillic small letter soft sign
    {0x044D, ""},         // cyrillic small letter e
    {0x044E, ""},         // cyrillic small letter yu
    {0x044F, ""},         // cyrillic small letter ya
    {0x0451, ""},         // cyrillic small letter io
    {0x0452, ""},         // cyrillic small letter dje
    {0x0453, ""},         // cyrillic small letter gje
    {0x0454, ""},         // cyrillic small letter ukrainian ie
    {0x0455, ""},         // cyrillic small letter dze
    {0x0456, ""},         // cyrillic small letter byelorussian-ukrainian i
    {0x0457, ""},         // cyrillic small letter yi
    {0x0458, ""},         // cyrillic small letter je
    {0x0459, ""},         // cyrillic small letter lje
    {0x045A, ""},         // cyrillic small letter nje
    {0x045B, ""},         // cyrillic small letter tshe
    {0x045C, ""},         // cyrillic small letter kje
    {0x045E, ""},         // cyrillic small letter short u
    {0x045F, ""},         // cyrillic small letter dzhe
    {0x0490, ""},         // cyrillic capital letter ghe with upturn
    {0x0491, ""},         // cyrillic small letter ghe with upturn
    {0x05D0, ""},         // hebrew letter alef
    {0x05D1, ""},         // hebrew letter bet
    {0x05D2, ""},         // hebrew letter gimel
    {0x05D3, ""},         // hebrew letter dalet
    {0x05D4, ""},         // hebrew letter he
    {0x05D5, ""},         // hebrew letter vav
    {0x05D6, ""},         // hebrew letter zayin
    {0x05D7, ""},         // hebrew letter het
    {0x05D8, ""},         // hebrew letter tet
    {0x05D9, ""},         // hebrew letter yod
    {0x05DA, ""},         // hebrew letter final kaf
    {0x05DB, ""},         // hebrew letter kaf
    {0x05DC, ""},         // hebrew letter lamed
    {0x05DD, ""},         // hebrew letter final mem
    {0x05DE, ""},         // hebrew letter mem
    {0x05DF, ""},         // hebrew letter final nun
    {0x05E0, ""},         // hebrew letter nun
    {0x05E1, ""},         // hebrew letter samekh
    {0x05E2, ""},         // hebrew letter ayin
    {0x05E3, ""},         // hebrew letter final pe
    {0x05E4, ""},         // hebrew letter pe
    {0x05E5, ""},         // hebrew letter final tsadi
    {0x05E6, ""},         // hebrew letter tsadi
    {0x05E7, ""},         // hebrew letter qof
    {0x05E8, ""},         // hebrew letter resh
    {0x05E9, ""},         // hebrew letter shin
    {0x05EA, ""},         // hebrew letter tav
    {0x1E02, "B"},        // latin capital letter b with dot above
    {0x1E03, "b"},        // latin small letter b with dot above
    {0x1E0A, "D"},        // latin capital letter d with dot above
    {0x1E0B, "d"},        // latin small letter d with dot above
    {0x1E1E, "F"},        // latin capital letter f with dot above
    {0x1E1F, "f"},        // latin small letter f with dot above
    {0x1E40, "M"},        // latin capital letter m with dot above
    {0x1E41, "m"},        // latin small letter m with dot above
    {0x1E56, "P"},        // latin capital letter p with dot above
    {0x1E57, "p"},        // latin small letter p with dot above
    {0x1E60, "S"},        // latin capital letter s with dot above
    {0x1E61, "s"},        // latin small letter s with dot above
    {0x1E6A, "T"},        // latin capital letter t with dot above
    {0x1E6B, "t"},        // latin small letter t with dot above
    {0x1E80, "`W"},       // latin capital letter w with grave
    {0x1E81, "`w"},       // latin small letter w with grave
    {0x1E84, "\"W"},      // latin capital letter w with diaeresis
    {0x1E85, "\"w"},      // latin small letter w with diaeresis
    {0x1EF2, "`Y"},       // latin capital letter y with grave
    {0x1EF3, "`y"},       // latin small letter y with grave
    {0x2002, " "},        // en space
    {0x2003, " "},        // em space
    {0x2004, " "},        // three-per-em space
    {0x2005, " "},        // four-per-em space
    {0x2006, " "},        // six-per-em space
    {0x2008, " "},        // punctuation space
    {0x2009, " "},        // thin space
    {0x200A, " "},        // hair space
    {0x2010, "-"},        // hyphen
    {0x2011, "-"},        // non-breaking hyphen
    {0x2012, "-"},        // figure dash
    {0x2013, "-"},        // en dash
    {0x2014, "-"},        // em dash
    {0x2015, "-"},        // horizontal bar
    {0x2016, ""},         // double vertical line
    {0x2017, ""},         // double low line
    {0x2018, "'"},        // left single quotation mark
    {0x2019, "'"},        // right single quotation mark
    {0x201A, ","},        // single low-9 quotation mark
    {0x201B, "'"},        // single high-reversed-9 quotation mark
    {0x201C, "\""},       // left double quotation mark
    {0x201D, "\""},       // right double quotation mark
    {0x201E, "\""},       // double low-9 quotation mark
    {0x201F, "\""},       // double high-reversed-9 quotation mark
    {0x2020, "+"},        // dagger
    {0x2021, ""},         // double dagger
    {0x2022, "o"},        // bullet
    {0x2024, "."},        // one dot leader
    {0x2025, ".."},       // two dot leader
    {0x2026, "..."},      // horizontal ellipsis
    {0x2030, "o/oo"},     // per mille sign
    {0x2039, "<"},        // single left-pointing angle quotation mark
    {0x203A, ">"},        // single right-pointing angle quotation mark
    {0x203C, "!!"},       // double exclamation mark
    {0x203E, ""},         // overline
    {0x2044, "/"},        // fraction slash
    {0x2047, "??"},       // double question mark
    {0x2048, "?!"},       // question exclamation mark
    {0x2049, "!?"},       // exclamation question mark
    {0x20A8, "Rs"},       // rupee sign
    {0x20AC, "EUR"},      // euro sign
    {0x2100, "a/c"},      // account of
    {0x2101, "a/s"},      // addressed to the subject
    {0x2102, "C"},        // double-struck capital c
    {0x2105, "c/o"},      // care of
    {0x2106, "c/u"},      // cada una
    {0x210A, "g"},        // script small g
    {0x210B, "H"},        // script capital h
    {0x210C, "H"},        // black-letter capital h
    {0x210D, "H"},        // double-struck capital h
    {0x210E, "h"},        // planck constant
    {0x2110, "I"},        // script capital i
    {0x2111, "I"},        // black-letter capital i
    {0x2112, "L"},        // script capital l
    {0x2113, "l"},        // script small l
    {0x2115, "N"},        // double-struck capital n
    {0x2116, "No"},       // numero sign
    {0x2119, "P"},        // double-struck capital p
    {0x211A, "Q"},        // double-struck capital q
    {0x211B, "R"},        // script capital r
    {0x211C, "R"},        // black-letter capital r
    {0x211D, "R"},        // double-struck capital r
    {0x2121, "TEL"},      // telephone sign
    {0x2122, "TM"},       // trade mark sign
    {0x2124, "Z"},        // double-struck capital z
    {0x2126, "Ohm"},      // ohm sign
    {0x2128, "Z"},        // black-letter capital z
    {0x212C, "B"},        // script capital b
    {0x212D, "C"},        // black-letter capital c
    {0x212E, "e"},        // estimated symbol
    {0x212F, "e"},        // script small e
    {0x2130, "E"},        // script capital e
    {0x2131, "F"},        // script capital f
    {0x2133, "M"},        // script capital m
    {0x2134, "o"},        // script small o
    {0x2139, "i"},        // information source
    {0x213B, "FAX"},      // facsimile sign
    {0x2145, "D"},        // double-struck italic capital d
    {0x2146, "d"},        // double-struck italic small d
    {0x2147, "e"},        // double-struck italic small e
    {0x2148, "i"},        // double-struck italic small i
    {0x2149, "j"},        // double-struck italic small j
    {0x2160, "I"},        // roman numeral one
    {0x2161, "II"},       // roman numeral two
    {0x2162, "III"},      // roman numeral three
    {0x2163, "IV"},       // roman numeral four
    {0x2164, "V"},        // roman numeral five
    {0x2165, "VI"},       // roman numeral six
    {0x2166, "VII"},      // roman numeral seven
    {0x2167, "VIII"},     // roman numeral eight
    {0x2168, "IX"},       // roman numeral nine
    {0x2169, "X"},        // roman numeral ten
    {0x216A, "XI"},       // roman numeral eleven
    {0x216B, "XII"},      // roman numeral twelve
    {0x216C, "L"},        // roman numeral fifty
    {0x216D, "C"},        // roman numeral one hundred
    {0x216E, "D"},        // roman numeral five hundred
    {0x216F, "M"},        // roman numeral one thousand
    {0x2170, "i"},        // small roman numeral one
    {0x2171, "ii"},       // small roman numeral two
    {0x2172, "iii"},      // small roman numeral three
    {0x2173, "iv"},       // small roman numeral four
    {0x2174, "v"},        // small roman numeral five
    {0x2175, "vi"},       // small roman numeral six
    {0x2176, "vii"},      // small roman numeral seven
    {0x2177, "viii"},     // small roman numeral eight
    {0x2178, "ix"},       // small roman numeral nine
    {0x2179, "x"},        // small roman numeral ten
    {0x217A, "xi"},       // small roman numeral eleven
    {0x217B, "xii"},      // small roman numeral twelve
    {0x217C, "l"},        // small roman numeral fifty
    {0x217D, "c"},        // small roman numeral one hundred
    {0x217E, "d"},        // small roman numeral five hundred
    {0x217F, "m"},        // small roman numeral one thousand
    {0x2190, "<-"},       // leftwards arrow
    {0x2191, "^"},        // upwards arrow
    {0x2192, "->"},       // rightwards arrow
    {0x2193, "V"},        // downwards arrow
    {0x2194, "<->"},      // left right arrow
    {0x21D0, "<="},       // leftwards double arrow
    {0x21D2, "=>"},       // rightwards double arrow
    {0x21D4, "<=>"},      // left right double arrow
    {0x2212, "-"},        // minus sign
    {0x2215, "/"},        // division slash
    {0x2216, "\\"},       // set minus
    {0x2217, "*"},        // asterisk operator
    {0x2223, "|"},        // divides
    {0x2236, ":"},        // ratio
    {0x223C, "~"},        // tilde operator
    {0x2260, "/="},       // not equal to
    {0x2264, "<="},       // less-than or equal to
    {0x2265, ">="},       // greater-than or equal to
    {0x226A, "<<"},       // much less-than
    {0x226B, ">>"},       // much greater-than
    {0x22D8, "<<<"},      // very much less-than
    {0x22D9, ">>>"},      // very much greater-than
    {0x2400, "[NUL]"},    // symbol for null
    {0x2401, "[SOH]"},    // symbol for start of heading
    {0x2402, "[STX]"},    // symbol for start of text
    {0x2403, "[ETX]"},    // symbol for end of text
    {0x2404, "[EOT]"},    // symbol for end of transmission
    {0x2405, "[ENQ]"},    // symbol for enquiry
    {0x2406, "[ACK]"},    // symbol for acknowledge
    {0x2407, "[BEL]"},    // symbol for bell
    {0x2408, "[BS]"},     // symbol for backspace
    {0x2409, "[HT]"},     // symbol for horizontal tabulation
    {0x240A, "[LF]"},     // symbol for line feed
    {0x240B, "[VT]"},     // symbol for vertical tabulation
    {0x240C, "[FF]"},     // symbol for form feed
    {0x240D, "[CR]"},     // symbol for carriage return
    {0x240E, "[SO]"},     // symbol for shift out
    {0x240F, "[SI]"},     // symbol for shift in
    {0x2410, "[DLE]"},    // symbol for data link escape
    {0x2411, "[DC1]"},    // symbol for device control one
    {0x2412, "[DC2]"},    // symbol for device control two
    {0x2413, "[DC3]"},    // symbol for device control three
    {0x2414, "[DC4]"},    // symbol for device control four
    {0x2415, "[NAK]"},    // symbol for negative acknowledge
    {0x2416, "[SYN]"},    // symbol for synchronous idle
    {0x2417, "[ETB]"},    // symbol for end of transmission block
    {0x2418, "[CAN]"},    // symbol for cancel
    {0x2419, "[EM]"},     // symbol for end of medium
    {0x241A, "[SUB]"},    // symbol for substitute
    {0x241B, "[ESC]"},    // symbol for escape
    {0x241C, "[FS]"},     // symbol for file separator
    {0x241D, "[GS]"},     // symbol for group separator
    {0x241E, "[RS]"},     // symbol for record separator
    {0x241F, "[US]"},     // symbol for unit separator
    {0x2420, "[SP]"},     // symbol for space
    {0x2421, "[DEL]"},    // symbol for delete
    {0x2424, "[NL]"},     // symbol for newline
    {0x2460, "(1)"},      // circled digit one
    {0x2461, "(2)"},      // circled digit two
    {0x2462, "(3)"},      // circled digit three
    {0x2463, "(4)"},      // circled digit four
    {0x2464, "(5)"},      // circled digit five
    {0x2465, "(6)"},      // circled digit six
    {0x2466, "(7)"},      // circled digit seven
    {0x2467, "(8)"},      // circled digit eight
    {0x2468, "(9)"},      // circled digit nine
    {0x2469, "(10)"},     // circled number ten
    {0x246A, "(11)"},     // circled number eleven
    {0x246B, "(12)"},     // circled number twelve
    {0x246C, "(13)"},     // circled number thirteen
    {0x246D, "(14)"},     // circled number fourteen
    {0x246E, "(15)"},     // circled number fifteen
    {0x246F, "(16)"},     // circled number sixteen
    {0x2470, "(17)"},     // circled number seventeen
    {0x2471, "(18)"},     // circled number eighteen
    {0x2472, "(19)"},     // circled number nineteen
    {0x2473, "(20)"},     // circled number twenty
    {0x2474, "(1)"},      // parenthesized digit one
    {0x2475, "(2)"},      // parenthesized digit two
    {0x2476, "(3)"},      // parenthesized digit three
    {0x2477, "(4)"},      // parenthesized digit four
    {0x2478, "(5)"},      // parenthesized digit five
    {0x2479, "(6)"},      // parenthesized digit six
    {0x247A, "(7)"},      // parenthesized digit seven
    {0x247B, "(8)"},      // parenthesized digit eight
    {0x247C, "(9)"},      // parenthesized digit nine
    {0x247D, "(10)"},     // parenthesized number ten
    {0x247E, "(11)"},     // parenthesized number eleven
    {0x247F, "(12)"},     // parenthesized number twelve
    {0x2480, "(13)"},     // parenthesized number thirteen
    {0x2481, "(14)"},     // parenthesized number fourteen
    {0x2482, "(15)"},     // parenthesized number fifteen
    {0x2483, "(16)"},     // parenthesized number sixteen
    {0x2484, "(17)"},     // parenthesized number seventeen
    {0x2485, "(18)"},     // parenthesized number eighteen
    {0x2486, "(19)"},     // parenthesized number nineteen
    {0x2487, "(20)"},     // parenthesized number twenty
    {0x2488, "1."},       // digit one full stop
    {0x2489, "2."},       // digit two full stop
    {0x248A, "3."},       // digit three full stop
    {0x248B, "4."},       // digit four full stop
    {0x248C, "5."},       // digit five full stop
    {0x248D, "6."},       // digit six full stop
    {0x248E, "7."},       // digit seven full stop
    {0x248F, "8."},       // digit eight full stop
    {0x2490, "9."},       // digit nine full stop
    {0x2491, "10."},      // number ten full stop
    {0x2492, "11."},      // number eleven full stop
    {0x2493, "12."},      // number twelve full stop
    {0x2494, "13."},      // number thirteen full stop
    {0x2495, "14."},      // number fourteen full stop
    {0x2496, "15."},      // number fifteen full stop
    {0x2497, "16."},      // number sixteen full stop
    {0x2498, "17."},      // number seventeen full stop
    {0x2499, "18."},      // number eighteen full stop
    {0x249A, "19."},      // number nineteen full stop
    {0x249B, "20."},      // number twenty full stop
    {0x249C, "(a)"},      // parenthesized latin small letter a
    {0x249D, "(b)"},      // parenthesized latin small letter b
    {0x249E, "(c)"},      // parenthesized latin small letter c
    {0x249F, "(d)"},      // parenthesized latin small letter d
    {0x24A0, "(e)"},      // parenthesized latin small letter e
    {0x24A1, "(f)"},      // parenthesized latin small letter f
    {0x24A2, "(g)"},      // parenthesized latin small letter g
    {0x24A3, "(h)"},      // parenthesized latin small letter h
    {0x24A4, "(i)"},      // parenthesized latin small letter i
    {0x24A5, "(j)"},      // parenthesized latin small letter j
    {0x24A6, "(k)"},      // parenthesized latin small letter k
    {0x24A7, "(l)"},      // parenthesized latin small letter l
    {0x24A8, "(m)"},      // parenthesized latin small letter m
    {0x24A9, "(n)"},      // parenthesized latin small letter n
    {0x24AA, "(o)"},      // parenthesized latin small letter o
    {0x24AB, "(p)"},      // parenthesized latin small letter p
    {0x24AC, "(q)"},      // parenthesized latin small letter q
    {0x24AD, "(r)"},      // parenthesized latin small letter r
    {0x24AE, "(s)"},      // parenthesized latin small letter s
    {0x24AF, "(t)"},      // parenthesized latin small letter t
    {0x24B0, "(u)"},      // parenthesized latin small letter u
    {0x24B1, "(v)"},      // parenthesized latin small letter v
    {0x24B2, "(w)"},      // parenthesized latin small letter w
    {0x24B3, "(x)"},      // parenthesized latin small letter x
    {0x24B4, "(y)"},      // parenthesized latin small letter y
    {0x24B5, "(z)"},      // parenthesized latin small letter z
    {0x24B6, "(A)"},      // circled latin capital letter a
    {0x24B7, "(B)"},      // circled latin capital letter b
    {0x24B8, "(C)"},      // circled latin capital letter c
    {0x24B9, "(D)"},      // circled latin capital letter d
    {0x24BA, "(E)"},      // circled latin capital letter e
    {0x24BB, "(F)"},      // circled latin capital letter f
    {0x24BC, "(G)"},      // circled latin capital letter g
    {0x24BD, "(H)"},      // circled latin capital letter h
    {0x24BE, "(I)"},      // circled latin capital letter i
    {0x24BF, "(J)"},      // circled latin capital letter j
    {0x24C0, "(K)"},      // circled latin capital letter k
    {0x24C1, "(L)"},      // circled latin capital letter l
    {0x24C2, "(M)"},      // circled latin capital letter m
    {0x24C3, "(N)"},      // circled latin capital letter n
    {0x24C4, "(O)"},      // circled latin capital letter o
    {0x24C5, "(P)"},      // circled latin capital letter p
    {0x24C6, "(Q)"},      // circled latin capital letter q
    {0x24C7, "(R)"},      // circled latin capital letter r
    {0x24C8, "(S)"},      // circled latin capital letter s
    {0x24C9, "(T)"},      // circled latin capital letter t
    {0x24CA, "(U)"},      // circled latin capital letter u
    {0x24CB, "(V)"},      // circled latin capital letter v
    {0x24CC, "(W)"},      // circled latin capital letter w
    {0x24CD, "(X)"},      // circled latin capital letter x
    {0x24CE, "(Y)"},      // circled latin capital letter y
    {0x24CF, "(Z)"},      // circled latin capital letter z
    {0x24D0, "(a)"},      // circled latin small letter a
    {0x24D1, "(b)"},      // circled latin small letter b
    {0x24D2, "(c)"},      // circled latin small letter c
    {0x24D3, "(d)"},      // circled latin small letter d
    {0x24D4, "(e)"},      // circled latin small letter e
    {0x24D5, "(f)"},      // circled latin small letter f
    {0x24D6, "(g)"},      // circled latin small letter g
    {0x24D7, "(h)"},      // circled latin small letter h
    {0x24D8, "(i)"},      // circled latin small letter i
    {0x24D9, "(j)"},      // circled latin small letter j
    {0x24DA, "(k)"},      // circled latin small letter k
    {0x24DB, "(l)"},      // circled latin small letter l
    {0x24DC, "(m)"},      // circled latin small letter m
    {0x24DD, "(n)"},      // circled latin small letter n
    {0x24DE, "(o)"},      // circled latin small letter o
    {0x24DF, "(p)"},      // circled latin small letter p
    {0x24E0, "(q)"},      // circled latin small letter q
    {0x24E1, "(r)"},      // circled latin small letter r
    {0x24E2, "(s)"},      // circled latin small letter s
    {0x24E3, "(t)"},      // circled latin small letter t
    {0x24E4, "(u)"},      // circled latin small letter u
    {0x24E5, "(v)"},      // circled latin small letter v
    {0x24E6, "(w)"},      // circled latin small letter w
    {0x24E7, "(x)"},      // circled latin small letter x
    {0x24E8, "(y)"},      // circled latin small letter y
    {0x24E9, "(z)"},      // circled latin small letter z
    {0x24EA, "(0)"},      // circled digit zero
    {0x2500, "-"},        // box drawings light horizontal
    {0x2502, "|"},        // box drawings light vertical
    {0x250C, "+"},        // box drawings light down and right
    {0x2510, "+"},        // box drawings light down and left
    {0x2514, "+"},        // box drawings light up and right
    {0x2518, "+"},        // box drawings light up and left
    {0x251C, "+"},        // box drawings light vertical and right
    {0x2524, "+"},        // box drawings light vertical and left
    {0x252C, "+"},        // box drawings light down and horizontal
    {0x2534, "+"},        // box drawings light up and horizontal
    {0x253C, "+"},        // box drawings light vertical and horizontal
    {0x2592, ""},         // medium shade
    {0x25AE, ""},         // black vertical rectangle
    {0x25C6, ""},         // black diamond
    {0x25E6, "o"},        // white bullet
    {0x266A, ""},         // eighth note
    {0x2A74, "::="},      // double colon equal
    {0x2A75, "=="},       // two consecutive equals signs
    {0x2A76, "==="},      // three consecutive equals signs
    {0x3000, " "},        // ideographic space
    {0x30A0, "="},        // katakana-hiragana double hyphen
    {0x3250, "PTE"},      // partnership sign
    {0x3251, "(21)"},     // circled number twenty one
    {0x3252, "(22)"},     // circled number twenty two
    {0x3253, "(23)"},     // circled number twenty three
    {0x3254, "(24)"},     // circled number twenty four
    {0x3255, "(25)"},     // circled number twenty five
    {0x3256, "(26)"},     // circled number twenty six
    {0x3257, "(27)"},     // circled number twenty seven
    {0x3258, "(28)"},     // circled number twenty eight
    {0x3259, "(29)"},     // circled number twenty nine
    {0x325A, "(30)"},     // circled number thirty
    {0x325B, "(31)"},     // circled number thirty one
    {0x325C, "(32)"},     // circled number thirty two
    {0x325D, "(33)"},     // circled number thirty three
    {0x325E, "(34)"},     // circled number thirty four
    {0x325F, "(35)"},     // circled number thirty five
    {0x32B1, "(36)"},     // circled number thirty six
    {0x32B2, "(37)"},     // circled number thirty seven
    {0x32B3, "(38)"},     // circled number thirty eight
    {0x32B4, "(39)"},     // circled number thirty nine
    {0x32B5, "(40)"},     // circled number forty
    {0x32B6, "(41)"},     // circled number forty one
    {0x32B7, "(42)"},     // circled number forty two
    {0x32B8, "(43)"},     // circled number forty three
    {0x32B9, "(44)"},     // circled number forty four
    {0x32BA, "(45)"},     // circled number forty five
    {0x32BB, "(46)"},     // circled number forty six
    {0x32BC, "(47)"},     // circled number forty seven
    {0x32BD, "(48)"},     // circled number forty eight
    {0x32BE, "(49)"},     // circled number forty nine
    {0x32BF, "(50)"},     // circled number fifty
    {0x32CC, "Hg"},       // square hg
    {0x32CD, "erg"},      // square erg
    {0x32CE, "eV"},       // square ev
    {0x32CF, "LTD"},      // limited liability sign
    {0x3371, "hPa"},      // square hpa
    {0x3372, "da"},       // square da
    {0x3373, "AU"},       // square au
    {0x3374, "bar"},      // square bar
    {0x3375, "oV"},       // square ov
    {0x3376, "pc"},       // square pc
    {0x3377, "dm"},       // square dm
    {0x3378, "dm^2"},     // square dm squared
    {0x3379, "dm^3"},     // square dm cubed
    {0x337A, "IU"},       // square iu
    {0x3380, "pA"},       // square pa amps
    {0x3381, "nA"},       // square na
    {0x3383, "mA"},       // square ma
    {0x3384, "kA"},       // square ka
    {0x3385, "KB"},       // square kb
    {0x3386, "MB"},       // square mb
    {0x3387, "GB"},       // square gb
    {0x3388, "cal"},      // square cal
    {0x3389, "kcal"},     // square kcal
    {0x338A, "pF"},       // square pf
    {0x338B, "nF"},       // square nf
    {0x338E, "mg"},       // square mg
    {0x338F, "kg"},       // square kg
    {0x3390, "Hz"},       // square hz
    {0x3391, "kHz"},      // square khz
    {0x3392, "MHz"},      // square mhz
    {0x3393, "GHz"},      // square ghz
    {0x3394, "THz"},      // square thz
    {0x3396, "ml"},       // square ml
    {0x3397, "dl"},       // square dl
    {0x3398, "kl"},       // square kl
    {0x3399, "fm"},       // square fm
    {0x339A, "nm"},       // square nm
    {0x339C, "mm"},       // square mm
    {0x339D, "cm"},       // square cm
    {0x339E, "km"},       // square km
    {0x339F, "mm^2"},     // square mm squared
    {0x33A0, "cm^2"},     // square cm squared
    {0x33A1, "m^2"},      // square m squared
    {0x33A2, "km^2"},     // square km squared
    {0x33A3, "mm^3"},     // square mm cubed
    {0x33A4, "cm^3"},     // square cm cubed
    {0x33A5, "m^3"},      // square m cubed
    {0x33A6, "km^3"},     // square km cubed
    {0x33A7, "m/s"},      // square m over s
    {0x33A8, "m/s^2"},    // square m over s squared
    {0x33A9, "Pa"},       // square pa
    {0x33AA, "kPa"},      // square kpa
    {0x33AB, "MPa"},      // square mpa
    {0x33AC, "GPa"},      // square gpa
    {0x33AD, "rad"},      // square rad
    {0x33AE, "rad/s"},    // square rad over s
    {0x33AF, "rad/s^2"},  // square rad over s squared
    {0x33B0, "ps"},       // square ps
    {0x33B1, "ns"},       // square ns
    {0x33B3, "ms"},       // square ms
    {0x33B4, "pV"},       // square pv
    {0x33B5, "nV"},       // square nv
    {0x33B7, "mV"},       // square mv
    {0x33B8, "kV"},       // square kv
    {0x33B9, "MV"},       // square mv mega
    {0x33BA, "pW"},       // square pw
    {0x33BB, "nW"},       // square nw
    {0x33BD, "mW"},       // square mw
    {0x33BE, "kW"},       // square kw
    {0x33BF, "MW"},       // square mw mega
    {0x33C2, "a.m."},     // square am
    {0x33C3, "Bq"},       // square bq
    {0x33C4, "cc"},       // square cc
    {0x33C5, "cd"},       // square cd
    {0x33C6, "C/kg"},     // square c over kg
    {0x33C7, "Co."},      // square co
    {0x33C8, "dB"},       // square db
    {0x33C9, "Gy"},       // square gy
    {0x33CA, "ha"},       // square ha
    {0x33CB, "HP"},       // square hp
    {0x33CC, "in"},       // square in
    {0x33CD, "KK"},       // square kk
    {0x33CE, "KM"},       // square km capital
    {0x33CF, "kt"},       // square kt
    {0x33D0, "lm"},       // square lm
    {0x33D1, "ln"},       // square ln
    {0x33D2, "log"},      // square log
    {0x33D3, "lx"},       // square lx
    {0x33D4, "mb"},       // square mb small
    {0x33D5, "mil"},      // square mil
    {0x33D6, "mol"},      // square mol
    {0x33D7, "PH"},       // square ph
    {0x33D8, "p.m."},     // square pm
    {0x33D9, "PPM"},      // square ppm
    {0x33DA, "PR"},       // square pr
    {0x33DB, "sr"},       // square sr
    {0x33DC, "Sv"},       // square sv
    {0x33DD, "Wb"},       // square wb
    {0x33DE, "V/m"},      // square v over m
    {0x33DF, "A/m"},      // square a over m
    {0x33FF, "gal"},      // square gal
    {0xFB00, "ff"},       // latin small ligature ff
    {0xFB01, "fi"},       // latin small ligature fi
    {0xFB02, "fl"},       // latin small ligature fl
    {0xFB03, "ffi"},      // latin small ligature ffi
    {0xFB04, "ffl"},      // latin small ligature ffl
    {0xFB06, "st"},       // latin small ligature st
    {0xFB29, "+"},        // hebrew letter alternative plus sign
    {0xFE4D, "_"},        // dashed low line
    {0xFE4E, "_"},        // centreline low line
    {0xFE4F, "_"},        // wavy low line
    {0xFE50, ","},        // small comma
    {0xFE52, "."},        // small full stop
    {0xFE54, ";"},        // small semicolon
    {0xFE55, ":"},        // small colon
    {0xFE56, "?"},        // small question mark
    {0xFE57, "!"},        // small exclamation mark
    {0xFE59, "("},        // small left parenthesis
    {0xFE5A, ")"},        // small right parenthesis
    {0xFE5B, "{"},        // small left curly bracket
    {0xFE5C, "}"},        // small right curly bracket
    {0xFE5F, "#"},        // small number sign
    {0xFE60, "&"},        // small ampersand
    {0xFE61, "*"},        // small asterisk
    {0xFE62, "+"},        // small plus sign
    {0xFE63, "-"},        // small hyphen-minus
    {0xFE64, "<"},        // small less-than sign
    {0xFE65, ">"},        // small greater-than sign
    {0xFE66, "="},        // small equals sign
    {0xFE68, "\\"},       // small reverse solidus
    {0xFE69, "$"},        // small dollar sign
    {0xFE6A, "%"},        // small percent sign
    {0xFE6B, "@"},        // small commercial at
    {0xFF01, "!"},        // fullwidth exclamation mark
    {0xFF02, "\""},       // fullwidth quotation mark
    {0xFF03, "#"},        // fullwidth number sign
    {0xFF04, "$"},        // fullwidth dollar sign
    {0xFF05, "%"},        // fullwidth percent sign
    {0xFF06, "&"},        // fullwidth ampersand
    {0xFF07, "'"},        // fullwidth apostrophe
    {0xFF08, "("},        // fullwidth left parenthesis
    {0xFF09, ")"},        // fullwidth right parenthesis
    {0xFF0A, "*"},        // fullwidth asterisk
    {0xFF0B, "+"},        // fullwidth plus sign
    {0xFF0C, ","},        // fullwidth comma
    {0xFF0D, "-"},        // fullwidth hyphen-minus
    {0xFF0E, "."},        // fullwidth full stop
    {0xFF0F, "/"},        // fullwidth solidus
    {0xFF10, "0"},        // fullwidth digit zero
    {0xFF11, "1"},        // fullwidth digit one
    {0xFF12, "2"},        // fullwidth digit two
    {0xFF13, "3"},        // fullwidth digit three
    {0xFF14, "4"},        // fullwidth digit four
    {0xFF15, "5"},        // fullwidth digit five
    {0xFF16, "6"},        // fullwidth digit six
    {0xFF17, "7"},        // fullwidth digit seven
    {0xFF18, "8"},        // fullwidth digit eight
    {0xFF19, "9"},        // fullwidth digit nine
    {0xFF1A, ":"},        // fullwidth colon
    {0xFF1B, ";"},        // fullwidth semicolon
    {0xFF1C, "<"},        // fullwidth less-than sign
    {0xFF1D, "="},        // fullwidth equals sign
    {0xFF1E, ">"},        // fullwidth greater-than sign
    {0xFF1F, "?"},        // fullwidth question mark
    {0xFF20, "@"},        // fullwidth commercial at
    {0xFF21, "A"},        // fullwidth latin capital letter a
    {0xFF22, "B"},        // fullwidth latin capital letter b
    {0xFF23, "C"},        // fullwidth latin capital letter c
    {0xFF24, "D"},        // fullwidth latin capital letter d
    {0xFF25, "E"},        // fullwidth latin capital letter e
    {0xFF26, "F"},        // fullwidth latin capital letter f
    {0xFF27, "G"},        // fullwidth latin capital letter g
    {0xFF28, "H"},        // fullwidth latin capital letter h
    {0xFF29, "I"},        // fullwidth latin capital letter i
    {0xFF2A, "J"},        // fullwidth latin capital letter j
    {0xFF2B, "K"},        // fullwidth latin capital letter k
    {0xFF2C, "L"},        // fullwidth latin capital letter l
    {0xFF2D, "M"},        // fullwidth latin capital letter m
    {0xFF2E, "N"},        // fullwidth latin capital letter n
    {0xFF2F, "O"},        // fullwidth latin capital letter o
    {0xFF30, "P"},        // fullwidth latin capital letter p
    {0xFF31, "Q"},        // fullwidth latin capital letter q
    {0xFF32, "R"},        // fullwidth latin capital letter r
    {0xFF33, "S"},        // fullwidth latin capital letter s
    {0xFF34, "T"},        // fullwidth latin capital letter t
    {0xFF35, "U"},        // fullwidth latin capital letter u
    {0xFF36, "V"},        // fullwidth latin capital letter v
    {0xFF37, "W"},        // fullwidth latin capital letter w
    {0xFF38, "X"},        // fullwidth latin capital letter x
    {0xFF39, "Y"},        // fullwidth latin capital letter y
    {0xFF3A, "Z"},        // fullwidth latin capital letter z
    {0xFF3B, "["},        // fullwidth left square bracket
    {0xFF3C, "\\"},       // fullwidth reverse solidus
    {0xFF3D, "]"},        // fullwidth right square bracket
    {0xFF3E, "^"},        // fullwidth circumflex accent
    {0xFF3F, "_"},        // fullwidth low line
    {0xFF40, "`"},        // fullwidth grave accent
    {0xFF41, "a"},        // fullwidth latin small letter a
    {0xFF42, "b"},        // fullwidth latin small letter b
    {0xFF43, "c"},        // fullwidth latin small letter c
    {0xFF44, "d"},        // fullwidth latin small letter d
    {0xFF45, "e"},        // fullwidth latin small letter e
    {0xFF46, "f"},        // fullwidth latin small letter f
    {0xFF47, "g"},        // fullwidth latin small letter g
    {0xFF48, "h"},        // fullwidth latin small letter h
    {0xFF49, "i"},        // fullwidth latin small letter i
    {0xFF4A, "j"},        // fullwidth latin small letter j
    {0xFF4B, "k"},        // fullwidth latin small letter k
    {0xFF4C, "l"},        // fullwidth latin small letter l
    {0xFF4D, "m"},        // fullwidth latin small letter m
    {0xFF4E, "n"},        // fullwidth latin small letter n
    {0xFF4F, "o"},        // fullwidth latin small letter o
    {0xFF50, "p"},        // fullwidth latin small letter p
    {0xFF51, "q"},        // fullwidth latin small letter q
    {0xFF52, "r"},        // fullwidth latin small letter r
    {0xFF53, "s"},        // fullwidth latin small letter s
    {0xFF54, "t"},        // fullwidth latin small letter t
    {0xFF55, "u"},        // fullwidth latin small letter u
    {0xFF56, "v"},        // fullwidth latin small letter v
    {0xFF57, "w"},        // fullwidth latin small letter w
    {0xFF58, "x"},        // fullwidth latin small letter x
    {0xFF59, "y"},        // fullwidth latin small letter y
    {0xFF5A, "z"},        // fullwidth latin small letter z
    {0xFF5B, "{"},        // fullwidth left curly bracket
    {0xFF5C, "|"},        // fullwidth vertical line
    {0xFF5D, "}"},        // fullwidth right curly bracket
    {0xFF5E, "~"},        // fullwidth tilde
    {0x0001D400, "A"},    // mathematical bold capital a
    {0x0001D401, "B"},    // mathematical bold capital b
    {0x0001D402, "C"},    // mathematical bold capital c
    {0x0001D403, "D"},    // mathematical bold capital d
    {0x0001D404, "E"},    // mathematical bold capital e
    {0x0001D405, "F"},    // mathematical bold capital f
    {0x0001D406, "G"},    // mathematical bold capital g
    {0x0001D407, "H"},    // mathematical bold capital h
    {0x0001D408, "I"},    // mathematical bold capital i
    {0x0001D409, "J"},    // mathematical bold capital j
    {0x0001D40A, "K"},    // mathematical bold capital k
    {0x0001D40B, "L"},    // mathematical bold capital l
    {0x0001D40C, "M"},    // mathematical bold capital m
    {0x0001D40D, "N"},    // mathematical bold capital n
    {0x0001D40E, "O"},    // mathematical bold capital o
    {0x0001D40F, "P"},    // mathematical bold capital p
    {0x0001D410, "Q"},    // mathematical bold capital q
    {0x0001D411, "R"},    // mathematical bold capital r
    {0x0001D412, "S"},    // mathematical bold capital s
    {0x0001D413, "T"},    // mathematical bold capital t
    {0x0001D414, "U"},    // mathematical bold capital u
    {0x0001D415, "V"},    // mathematical bold capital v
    {0x0001D416, "W"},    // mathematical bold capital w
    {0x0001D417, "X"},    // mathematical bold capital x
    {0x0001D418, "Y"},    // mathematical bold capital y
    {0x0001D419, "Z"},    // mathematical bold capital z
    {0x0001D41A, "a"},    // mathematical bold small a
    {0x0001D41B, "b"},    // mathematical bold small b
    {0x0001D41C, "c"},    // mathematical bold small c
    {0x0001D41D, "d"},    // mathematical bold small d
    {0x0001D41E, "e"},    // mathematical bold small e
    {0x0001D41F, "f"},    // mathematical bold small f
    {0x0001D420, "g"},    // mathematical bold small g
    {0x0001D421, "h"},    // mathematical bold small h
    {0x0001D422, "i"},    // mathematical bold small i
    {0x0001D423, "j"},    // mathematical bold small j
    {0x0001D424, "k"},    // mathematical bold small k
    {0x0001D425, "l"},    // mathematical bold small l
    {0x0001D426, "m"},    // mathematical bold small m
    {0x0001D427, "n"},    // mathematical bold small n
    {0x0001D428, "o"},    // mathematical bold small o
    {0x0001D429, "p"},    // mathematical bold small p
    {0x0001D42A, "q"},    // mathematical bold small q
    {0x0001D42B, "r"},    // mathematical bold small r
    {0x0001D42C, "s"},    // mathematical bold small s
    {0x0001D42D, "t"},    // mathematical bold small t
    {0x0001D42E, "u"},    // mathematical bold small u
    {0x0001D42F, "v"},    // mathematical bold small v
    {0x0001D430, "w"},    // mathematical bold small w
    {0x0001D431, "x"},    // mathematical bold small x
    {0x0001D432, "y"},    // mathematical bold small y
    {0x0001D433, "z"},    // mathematical bold small z
    {0x0001D434, "A"},    // mathematical italic capital a
    {0x0001D435, "B"},    // mathematical italic capital b
    {0x0001D436, "C"},    // mathematical italic capital c
    {0x0001D437, "D"},    // mathematical italic capital d
    {0x0001D438, "E"},    // mathematical italic capital e
    {0x0001D439, "F"},    // mathematical italic capital f
    {0x0001D43A, "G"},    // mathematical italic capital g
    {0x0001D43B, "H"},    // mathematical italic capital h
    {0x0001D43C, "I"},    // mathematical italic capital i
    {0x0001D43D, "J"},    // mathematical italic capital j
    {0x0001D43E, "K"},    // mathematical italic capital k
    {0x0001D43F, "L"},    // mathematical italic capital l
    {0x0001D440, "M"},    // mathematical italic capital m
    {0x0001D441, "N"},    // mathematical italic capital n
    {0x0001D442, "O"},    // mathematical italic capital o
    {0x0001D443, "P"},    // mathematical italic capital p
    {0x0001D444, "Q"},    // mathematical italic capital q
    {0x0001D445, "R"},    // mathematical italic capital r
    {0x0001D446, "S"},    // mathematical italic capital s
    {0x0001D447, "T"},    // mathematical italic capital t
    {0x0001D448, "U"},    // mathematical italic capital u
    {0x0001D449, "V"},    // mathematical italic capital v
    {0x0001D44A, "W"},    // mathematical italic capital w
    {0x0001D44B, "X"},    // mathematical italic capital x
    {0x0001D44C, "Y"},    // mathematical italic capital y
    {0x0001D44D, "Z"},    // mathematical italic capital z
    {0x0001D44E, "a"},    // mathematical italic small a
    {0x0001D44F, "b"},    // mathematical italic small b
    {0x0001D450, "c"},    // mathematical italic small c
    {0x0001D451, "d"},    // mathematical italic small d
    {0x0001D452, "e"},    // mathematical italic small e
    {0x0001D453, "f"},    // mathematical italic small f
    {0x0001D454, "g"},    // mathematical italic small g
    {0x0001D456, "i"},    // mathematical italic small i
    {0x0001D457, "j"},    // mathematical italic small j
    {0x0001D458, "k"},    // mathematical italic small k
    {0x0001D459, "l"},    // mathematical italic small l
    {0x0001D45A, "m"},    // mathematical italic small m
    {0x0001D45B, "n"},    // mathematical italic small n
    {0x0001D45C, "o"},    // mathematical italic small o
    {0x0001D45D, "p"},    // mathematical italic small p
    {0x0001D45E, "q"},    // mathematical italic small q
    {0x0001D45F, "r"},    // mathematical italic small r
    {0x0001D460, "s"},    // mathematical italic small s
    {0x0001D461, "t"},    // mathematical italic small t
    {0x0001D462, "u"},    // mathematical italic small u
    {0x0001D463, "v"},    // mathematical italic small v
    {0x0001D464, "w"},    // mathematical italic small w
    {0x0001D465, "x"},    // mathematical italic small x
    {0x0001D466, "y"},    // mathematical italic small y
    {0x0001D467, "z"},    // mathematical italic small z
    {0x0001D468, "A"},    // mathematical bold italic capital a
    {0x0001D469, "B"},    // mathematical bold italic capital b
    {0x0001D46A, "C"},    // mathematical bold italic capital c
    {0x0001D46B, "D"},    // mathematical bold italic capital d
    {0x0001D46C, "E"},    // mathematical bold italic capital e
    {0x0001D46D, "F"},    // mathematical bold italic capital f
    {0x0001D46E, "G"},    // mathematical bold italic capital g
    {0x0001D46F, "H"},    // mathematical bold italic capital h
    {0x0001D470, "I"},    // mathematical bold italic capital i
    {0x0001D471, "J"},    // mathematical bold italic capital j
    {0x0001D472, "K"},    // mathematical bold italic capital k
    {0x0001D473, "L"},    // mathematical bold italic capital l
    {0x0001D474, "M"},    // mathematical bold italic capital m
    {0x0001D475, "N"},    // mathematical bold italic capital n
    {0x0001D476, "O"},    // mathematical bold italic capital o
    {0x0001D477, "P"},    // mathematical bold italic capital p
    {0x0001D478, "Q"},    // mathematical bold italic capital q
    {0x0001D479, "R"},    // mathematical bold italic capital r
    {0x0001D47A, "S"},    // mathematical bold italic capital s
    {0x0001D47B, "T"},    // mathematical bold italic capital t
    {0x0001D47C, "U"},    // mathematical bold italic capital u
    {0x0001D47D, "V"},    // mathematical bold italic capital v
    {0x0001D47E, "W"},    // mathematical bold italic capital w
    {0x0001D47F, "X"},    // mathematical bold italic capital x
    {0x0001D480, "Y"},    // mathematical bold italic capital y
    {0x0001D481, "Z"},    // mathematical bold italic capital z
    {0x0001D482, "a"},    // mathematical bold italic small a
    {0x0001D483, "b"},    // mathematical bold italic small b
    {0x0001D484, "c"},    // mathematical bold italic small c
    {0x0001D485, "d"},    // mathematical bold italic small d
    {0x0001D486, "e"},    // mathematical bold italic small e
    {0x0001D487, "f"},    // mathematical bold italic small f
    {0x0001D488, "g"},    // mathematical bold italic small g
    {0x0001D489, "h"},    // mathematical bold italic small h
    {0x0001D48A, "i"},    // mathematical bold italic small i
    {0x0001D48B, "j"},    // mathematical bold italic small j
    {0x0001D48C, "k"},    // mathematical bold italic small k
    {0x0001D48D, "l"},    // mathematical bold italic small l
    {0x0001D48E, "m"},    // mathematical bold italic small m
    {0x0001D48F, "n"},    // mathematical bold italic small n
    {0x0001D490, "o"},    // mathematical bold italic small o
    {0x0001D491, "p"},    // mathematical bold italic small p
    {0x0001D492, "q"},    // mathematical bold italic small q
    {0x0001D493, "r"},    // mathematical bold italic small r
    {0x0001D494, "s"},    // mathematical bold italic small s
    {0x0001D495, "t"},    // mathematical bold italic small t
    {0x0001D496, "u"},    // mathematical bold italic small u
    {0x0001D497, "v"},    // mathematical bold italic small v
    {0x0001D498, "w"},    // mathematical bold italic small w
    {0x0001D499, "x"},    // mathematical bold italic small x
    {0x0001D49A, "y"},    // mathematical bold italic small y
    {0x0001D49B, "z"},    // mathematical bold italic small z
    {0x0001D49C, "A"},    // mathematical script capital a
    {0x0001D49E, "C"},    // mathematical script capital c
    {0x0001D49F, "D"},    // mathematical script capital d
    {0x0001D4A2, "G"},    // mathematical script capital g
    {0x0001D4A5, "J"},    // mathematical script capital j
    {0x0001D4A6, "K"},    // mathematical script capital k
    {0x0001D4A9, "N"},    // mathematical script capital n
    {0x0001D4AA, "O"},    // mathematical script capital o
    {0x0001D4AB, "P"},    // mathematical script capital p
    {0x0001D4AC, "Q"},    // mathematical script capital q
    {0x0001D4AE, "S"},    // mathematical script capital s
    {0x0001D4AF, "T"},    // mathematical script capital t
    {0x0001D4B0, "U"},    // mathematical script capital u
    {0x0001D4B1, "V"},    // mathematical script capital v
    {0x0001D4B2, "W"},    // mathematical script capital w
    {0x0001D4B3, "X"},    // mathematical script capital x
    {0x0001D4B4, "Y"},    // mathematical script capital y
    {0x0001D4B5, "Z"},    // mathematical script capital z
    {0x0001D4B6, "a"},    // mathematical script small a
    {0x0001D4B7, "b"},    // mathematical script small b
    {0x0001D4B8, "c"},    // mathematical script small c
    {0x0001D4B9, "d"},    // mathematical script small d
    {0x0001D4BB, "f"},    // mathematical script small f
    {0x0001D4BD, "h"},    // mathematical script small h
    {0x0001D4BE, "i"},    // mathematical script small i
    {0x0001D4BF, "j"},    // mathematical script small j
    {0x0001D4C0, "k"},    // mathematical script small k
    {0x0001D4C1, "l"},    // mathematical script small l
    {0x0001D4C2, "m"},    // mathematical script small m
    {0x0001D4C3, "n"},    // mathematical script small n
    {0x0001D4C5, "p"},    // mathematical script small p
    {0x0001D4C6, "q"},    // mathematical script small q
    {0x0001D4C7, "r"},    // mathematical script small r
    {0x0001D4C8, "s"},    // mathematical script small s
    {0x0001D4C9, "t"},    // mathematical script small t
    {0x0001D4CA, "u"},    // mathematical script small u
    {0x0001D4CB, "v"},    // mathematical script small v
    {0x0001D4CC, "w"},    // mathematical script small w
    {0x0001D4CD, "x"},    // mathematical script small x
    {0x0001D4CE, "y"},    // mathematical script small y
    {0x0001D4CF, "z"},    // mathematical script small z
    {0x0001D4D0, "A"},    // mathematical bold script capital a
    {0x0001D4D1, "B"},    // mathematical bold script capital b
    {0x0001D4D2, "C"},    // mathematical bold script capital c
    {0x0001D4D3, "D"},    // mathematical bold script capital d
    {0x0001D4D4, "E"},    // mathematical bold script capital e
    {0x0001D4D5, "F"},    // mathematical bold script capital f
    {0x0001D4D6, "G"},    // mathematical bold script capital g
    {0x0001D4D7, "H"},    // mathematical bold script capital h
    {0x0001D4D8, "I"},    // mathematical bold script capital i
    {0x0001D4D9, "J"},    // mathematical bold script capital j
    {0x0001D4DA, "K"},    // mathematical bold script capital k
    {0x0001D4DB, "L"},    // mathematical bold script capital l
    {0x0001D4DC, "M"},    // mathematical bold script capital m
    {0x0001D4DD, "N"},    // mathematical bold script capital n
    {0x0001D4DE, "O"},    // mathematical bold script capital o
    {0x0001D4DF, "P"},    // mathematical bold script capital p
    {0x0001D4E0, "Q"},    // mathematical bold script capital q
    {0x0001D4E1, "R"},    // mathematical bold script capital r
    {0x0001D4E2, "S"},    // mathematical bold script capital s
    {0x0001D4E3, "T"},    // mathematical bold script capital t
    {0x0001D4E4, "U"},    // mathematical bold script capital u
    {0x0001D4E5, "V"},    // mathematical bold script capital v
    {0x0001D4E6, "W"},    // mathematical bold script capital w
    {0x0001D4E7, "X"},    // mathematical bold script capital x
    {0x0001D4E8, "Y"},    // mathematical bold script capital y
    {0x0001D4E9, "Z"},    // mathematical bold script capital z
    {0x0001D4EA, "a"},    // mathematical bold script small a
    {0x0001D4EB, "b"},    // mathematical bold script small b
    {0x0001D4EC, "c"},    // mathematical bold script small c
    {0x0001D4ED, "d"},    // mathematical bold script small d
    {0x0001D4EE, "e"},    // mathematical bold script small e
    {0x0001D4EF, "f"},    // mathematical bold script small f
    {0x0001D4F0, "g"},    // mathematical bold script small g
    {0x0001D4F1, "h"},    // mathematical bold script small h
    {0x0001D4F2, "i"},    // mathematical bold script small i
    {0x0001D4F3, "j"},    // mathematical bold script small j
    {0x0001D4F4, "k"},    // mathematical bold script small k
    {0x0001D4F5, "l"},    // mathematical bold script small l
    {0x0001D4F6, "m"},    // mathematical bold script small m
    {0x0001D4F7, "n"},    // mathematical bold script small n
    {0x0001D4F8, "o"},    // mathematical bold script small o
    {0x0001D4F9, "p"},    // mathematical bold script small p
    {0x0001D4FA, "q"},    // mathematical bold script small q
    {0x0001D4FB, "r"},    // mathematical bold script small r
    {0x0001D4FC, "s"},    // mathematical bold script small s
    {0x0001D4FD, "t"},    // mathematical bold script small t
    {0x0001D4FE, "u"},    // mathematical bold script small u
    {0x0001D4FF, "v"},    // mathematical bold script small v
    {0x0001D500, "w"},    // mathematical bold script small w
    {0x0001D501, "x"},    // mathematical bold script small x
    {0x0001D502, "y"},    // mathematical bold script small y
    {0x0001D503, "z"},    // mathematical bold script small z
    {0x0001D504, "A"},    // mathematical fraktur capital a
    {0x0001D505, "B"},    // mathematical fraktur capital b
    {0x0001D507, "D"},    // mathematical fraktur capital d
    {0x0001D508, "E"},    // mathematical fraktur capital e
    {0x0001D509, "F"},    // mathematical fraktur capital f
    {0x0001D50A, "G"},    // mathematical fraktur capital g
    {0x0001D50D, "J"},    // mathematical fraktur capital j
    {0x0001D50E, "K"},    // mathematical fraktur capital k
    {0x0001D50F, "L"},    // mathematical fraktur capital l
    {0x0001D510, "M"},    // mathematical fraktur capital m
    {0x0001D511, "N"},    // mathematical fraktur capital n
    {0x0001D512, "O"},    // mathematical fraktur capital o
    {0x0001D513, "P"},    // mathematical fraktur capital p
    {0x0001D514, "Q"},    // mathematical fraktur capital q
    {0x0001D516, "S"},    // mathematical fraktur capital s
    {0x0001D517, "T"},    // mathematical fraktur capital t
    {0x0001D518, "U"},    // mathematical fraktur capital u
    {0x0001D519, "V"},    // mathematical fraktur capital v
    {0x0001D51A, "W"},    // mathematical fraktur capital w
    {0x0001D51B, "X"},    // mathematical fraktur capital x
    {0x0001D51C, "Y"},    // mathematical fraktur capital y
    {0x0001D51E, "a"},    // mathematical fraktur small a
    {0x0001D51F, "b"},    // mathematical fraktur small b
    {0x0001D520, "c"},    // mathematical fraktur small c
    {0x0001D521, "d"},    // mathematical fraktur small d
    {0x0001D522, "e"},    // mathematical fraktur small e
    {0x0001D523, "f"},    // mathematical fraktur small f
    {0x0001D524, "g"},    // mathematical fraktur small g
    {0x0001D525, "h"},    // mathematical fraktur small h
    {0x0001D526, "i"},    // mathematical fraktur small i
    {0x0001D527, "j"},    // mathematical fraktur small j
    {0x0001D528, "k"},    // mathematical fraktur small k
    {0x0001D529, "l"},    // mathematical fraktur small l
    {0x0001D52A, "m"},    // mathematical fraktur small m
    {0x0001D52B, "n"},    // mathematical fraktur small n
    {0x0001D52C, "o"},    // mathematical fraktur small o
    {0x0001D52D, "p"},    // mathematical fraktur small p
    {0x0001D52E, "q"},    // mathematical fraktur small q
    {0x0001D52F, "r"},    // mathematical fraktur small r
    {0x0001D530, "s"},    // mathematical fraktur small s
    {0x0001D531, "t"},    // mathematical fraktur small t
    {0x0001D532, "u"},    // mathematical fraktur small u
    {0x0001D533, "v"},    // mathematical fraktur small v
    {0x0001D534, "w"},    // mathematical fraktur small w
    {0x0001D535, "x"},    // mathematical fraktur small x
    {0x0001D536, "y"},    // mathematical fraktur small y
    {0x0001D537, "z"},    // mathematical fraktur small z
    {0x0001D538, "A"},    // mathematical double-struck capital a
    {0x0001D539, "B"},    // mathematical double-struck capital b
    {0x0001D53B, "D"},    // mathematical double-struck capital d
    {0x0001D53C, "E"},    // mathematical double-struck capital e
    {0x0001D53D, "F"},    // mathematical double-struck capital f
    {0x0001D53E, "G"},    // mathematical double-struck capital g
    {0x0001D540, "I"},    // mathematical double-struck capital i
    {0x0001D541, "J"},    // mathematical double-struck capital j
    {0x0001D542, "K"},    // mathematical double-struck capital k
    {0x0001D543, "L"},    // mathematical double-struck capital l
    {0x0001D544, "M"},    // mathematical double-struck capital m
    {0x0001D546, "O"},    // mathematical double-struck capital o
    {0x0001D54A, "S"},    // mathematical double-struck capital s
    {0x0001D54B, "T"},    // mathematical double-struck capital t
    {0x0001D54C, "U"},    // mathematical double-struck capital u
    {0x0001D54D, "V"},    // mathematical double-struck capital v
    {0x0001D54E, "W"},    // mathematical double-struck capital w
    {0x0001D54F, "X"},    // mathematical double-struck capital x
    {0x0001D550, "Y"},    // mathematical double-struck capital y
    {0x0001D552, "a"},    // mathematical double-struck small a
    {0x0001D553, "b"},    // mathematical double-struck small b
    {0x0001D554, "c"},    // mathematical double-struck small c
    {0x0001D555, "d"},    // mathematical double-struck small d
    {0x0001D556, "e"},    // mathematical double-struck small e
    {0x0001D557, "f"},    // mathematical double-struck small f
    {0x0001D558, "g"},    // mathematical double-struck small g
    {0x0001D559, "h"},    // mathematical double-struck small h
    {0x0001D55A, "i"},    // mathematical double-struck small i
    {0x0001D55B, "j"},    // mathematical double-struck small j
    {0x0001D55C, "k"},    // mathematical double-struck small k
    {0x0001D55D, "l"},    // mathematical double-struck small l
    {0x0001D55E, "m"},    // mathematical double-struck small m
    {0x0001D55F, "n"},    // mathematical double-struck small n
    {0x0001D560, "o"},    // mathematical double-struck small o
    {0x0001D561, "p"},    // mathematical double-struck small p
    {0x0001D562, "q"},    // mathematical double-struck small q
    {0x0001D563, "r"},    // mathematical double-struck small r
    {0x0001D564, "s"},    // mathematical double-struck small s
    {0x0001D565, "t"},    // mathematical double-struck small t
    {0x0001D566, "u"},    // mathematical double-struck small u
    {0x0001D567, "v"},    // mathematical double-struck small v
    {0x0001D568, "w"},    // mathematical double-struck small w
    {0x0001D569, "x"},    // mathematical double-struck small x
    {0x0001D56A, "y"},    // mathematical double-struck small y
    {0x0001D56B, "z"},    // mathematical double-struck small z
    {0x0001D56C, "A"},    // mathematical bold fraktur capital a
    {0x0001D56D, "B"},    // mathematical bold fraktur capital b
    {0x0001D56E, "C"},    // mathematical bold fraktur capital c
    {0x0001D56F, "D"},    // mathematical bold fraktur capital d
    {0x0001D570, "E"},    // mathematical bold fraktur capital e
    {0x0001D571, "F"},    // mathematical bold fraktur capital f
    {0x0001D572, "G"},    // mathematical bold fraktur capital g
    {0x0001D573, "H"},    // mathematical bold fraktur capital h
    {0x0001D574, "I"},    // mathematical bold fraktur capital i
    {0x0001D575, "J"},    // mathematical bold fraktur capital j
    {0x0001D576, "K"},    // mathematical bold fraktur capital k
    {0x0001D577, "L"},    // mathematical bold fraktur capital l
    {0x0001D578, "M"},    // mathematical bold fraktur capital m
    {0x0001D579, "N"},    // mathematical bold fraktur capital n
    {0x0001D57A, "O"},    // mathematical bold fraktur capital o
    {0x0001D57B, "P"},    // mathematical bold fraktur capital p
    {0x0001D57C, "Q"},    // mathematical bold fraktur capital q
    {0x0001D57D, "R"},    // mathematical bold fraktur capital r
    {0x0001D57E, "S"},    // mathematical bold fraktur capital s
    {0x0001D57F, "T"},    // mathematical bold fraktur capital t
    {0x0001D580, "U"},    // mathematical bold fraktur capital u
    {0x0001D581, "V"},    // mathematical bold fraktur capital v
    {0x0001D582, "W"},    // mathematical bold fraktur capital w
    {0x0001D583, "X"},    // mathematical bold fraktur capital x
    {0x0001D584, "Y"},    // mathematical bold fraktur capital y
    {0x0001D585, "Z"},    // mathematical bold fraktur capital z
    {0x0001D586, "a"},    // mathematical bold fraktur small a
    {0x0001D587, "b"},    // mathematical bold fraktur small b
    {0x0001D588, "c"},    // mathematical bold fraktur small c
    {0x0001D589, "d"},    // mathematical bold fraktur small d
    {0x0001D58A, "e"},    // mathematical bold fraktur small e
    {0x0001D58B, "f"},    // mathematical bold fraktur small f
    {0x0001D58C, "g"},    // mathematical bold fraktur small g
    {0x0001D58D, "h"},    // mathematical bold fraktur small h
    {0x0001D58E, "i"},    // mathematical bold fraktur small i
    {0x0001D58F, "j"},    // mathematical bold fraktur small j
    {0x0001D590, "k"},    // mathematical bold fraktur small k
    {0x0001D591, "l"},    // mathematical bold fraktur small l
    {0x0001D592, "m"},    // mathematical bold fraktur small m
    {0x0001D593, "n"},    // mathematical bold fraktur small n
    {0x0001D594, "o"},    // mathematical bold fraktur small o
    {0x0001D595, "p"},    // mathematical bold fraktur small p
    {0x0001D596, "q"},    // mathematical bold fraktur small q
    {0x0001D597, "r"},    // mathematical bold fraktur small r
    {0x0001D598, "s"},    // mathematical bold fraktur small s
    {0x0001D599, "t"},    // mathematical bold fraktur small t
    {0x0001D59A, "u"},    // mathematical bold fraktur small u
    {0x0001D59B, "v"},    // mathematical bold fraktur small v
    {0x0001D59C, "w"},    // mathematical bold fraktur small w
    {0x0001D59D, "x"},    // mathematical bold fraktur small x
    {0x0001D59E, "y"},    // mathematical bold fraktur small y
    {0x0001D59F, "z"},    // mathematical bold fraktur small z
    {0x0001D5A0, "A"},    // mathematical sans-serif capital a
    {0x0001D5A1, "B"},    // mathematical sans-serif capital b
    {0x0001D5A2, "C"},    // mathematical sans-serif capital c
    {0x0001D5A3, "D"},    // mathematical sans-serif capital d
    {0x0001D5A4, "E"},    // mathematical sans-serif capital e
    {0x0001D5A5, "F"},    // mathematical sans-serif capital f
    {0x0001D5A6, "G"},    // mathematical sans-serif capital g
    {0x0001D5A7, "H"},    // mathematical sans-serif capital h
    {0x0001D5A8, "I"},    // mathematical sans-serif capital i
    {0x0001D5A9, "J"},    // mathematical sans-serif capital j
    {0x0001D5AA, "K"},    // mathematical sans-serif capital k
    {0x0001D5AB, "L"},    // mathematical sans-serif capital l
    {0x0001D5AC, "M"},    // mathematical sans-serif capital m
    {0x0001D5AD, "N"},    // mathematical sans-serif capital n
    {0x0001D5AE, "O"},    // mathematical sans-serif capital o
    {0x0001D5AF, "P"},    // mathematical sans-serif capital p
    {0x0001D5B0, "Q"},    // mathematical sans-serif capital q
    {0x0001D5B1, "R"},    // mathematical sans-serif capital r
    {0x0001D5B2, "S"},    // mathematical sans-serif capital s
    {0x0001D5B3, "T"},    // mathematical sans-serif capital t
    {0x0001D5B4, "U"},    // mathematical sans-serif capital u
    {0x0001D5B5, "V"},    // mathematical sans-serif capital v
    {0x0001D5B6, "W"},    // mathematical sans-serif capital w
    {0x0001D5B7, "X"},    // mathematical sans-serif capital x
    {0x0001D5B8, "Y"},    // mathematical sans-serif capital y
    {0x0001D5B9, "Z"},    // mathematical sans-serif capital z
    {0x0001D5BA, "a"},    // mathematical sans-serif small a
    {0x0001D5BB, "b"},    // mathematical sans-serif small b
    {0x0001D5BC, "c"},    // mathematical sans-serif small c
    {0x0001D5BD, "d"},    // mathematical sans-serif small d
    {0x0001D5BE, "e"},    // mathematical sans-serif small e
    {0x0001D5BF, "f"},    // mathematical sans-serif small f
    {0x0001D5C0, "g"},    // mathematical sans-serif small g
    {0x0001D5C1, "h"},    // mathematical sans-serif small h
    {0x0001D5C2, "i"},    // mathematical sans-serif small i
    {0x0001D5C3, "j"},    // mathematical sans-serif small j
    {0x0001D5C4, "k"},    // mathematical sans-serif small k
    {0x0001D5C5, "l"},    // mathematical sans-serif small l
    {0x0001D5C6, "m"},    // mathematical sans-serif small m
    {0x0001D5C7, "n"},    // mathematical sans-serif small n
    {0x0001D5C8, "o"},    // mathematical sans-serif small o
    {0x0001D5C9, "p"},    // mathematical sans-serif small p
    {0x0001D5CA, "q"},    // mathematical sans-serif small q
    {0x0001D5CB, "r"},    // mathematical sans-serif small r
    {0x0001D5CC, "s"},    // mathematical sans-serif small s
    {0x0001D5CD, "t"},    // mathematical sans-serif small t
    {0x0001D5CE, "u"},    // mathematical sans-serif small u
    {0x0001D5CF, "v"},    // mathematical sans-serif small v
    {0x0001D5D0, "w"},    // mathematical sans-serif small w
    {0x0001D5D1, "x"},    // mathematical sans-serif small x
    {0x0001D5D2, "y"},    // mathematical sans-serif small y
    {0x0001D5D3, "z"},    // mathematical sans-serif small z
    {0x0001D5D4, "A"},    // mathematical sans-serif bold capital a
    {0x0001D5D5, "B"},    // mathematical sans-serif bold capital b
    {0x0001D5D6, "C"},    // mathematical sans-serif bold capital c
    {0x0001D5D7, "D"},    // mathematical sans-serif bold capital d
    {0x0001D5D8, "E"},    // mathematical sans-serif bold capital e
    {0x0001D5D9, "F"},    // mathematical sans-serif bold capital f
    {0x0001D5DA, "G"},    // mathematical sans-serif bold capital g
    {0x0001D5DB, "H"},    // mathematical sans-serif bold capital h
    {0x0001D5DC, "I"},    // mathematical sans-serif bold capital i
    {0x0001D5DD, "J"},    // mathematical sans-serif bold capital j
    {0x0001D5DE, "K"},    // mathematical sans-serif bold capital k
    {0x0001D5DF, "L"},    // mathematical sans-serif bold capital l
    {0x0001D5E0, "M"},    // mathematical sans-serif bold capital m
    {0x0001D5E1, "N"},    // mathematical sans-serif bold capital n
    {0x0001D5E2, "O"},    // mathematical sans-serif bold capital o
    {0x0001D5E3, "P"},    // mathematical sans-serif bold capital p
    {0x0001D5E4, "Q"},    // mathematical sans-serif bold capital q
    {0x0001D5E5, "R"},    // mathematical sans-serif bold capital r
    {0x0001D5E6, "S"},    // mathematical sans-serif bold capital s
    {0x0001D5E7, "T"},    // mathematical sans-serif bold capital t
    {0x0001D5E8, "U"},    // mathematical sans-serif bold capital u
    {0x0001D5E9, "V"},    // mathematical sans-serif bold capital v
    {0x0001D5EA, "W"},    // mathematical sans-serif bold capital w
    {0x0001D5EB, "X"},    // mathematical sans-serif bold capital x
    {0x0001D5EC, "Y"},    // mathematical sans-serif bold capital y
    {0x0001D5ED, "Z"},    // mathematical sans-serif bold capital z
    {0x0001D5EE, "a"},    // mathematical sans-serif bold small a
    {0x0001D5EF, "b"},    // mathematical sans-serif bold small b
    {0x0001D5F0, "c"},    // mathematical sans-serif bold small c
    {0x0001D5F1, "d"},    // mathematical sans-serif bold small d
    {0x0001D5F2, "e"},    // mathematical sans-serif bold small e
    {0x0001D5F3, "f"},    // mathematical sans-serif bold small f
    {0x0001D5F4, "g"},    // mathematical sans-serif bold small g
    {0x0001D5F5, "h"},    // mathematical sans-serif bold small h
    {0x0001D5F6, "i"},    // mathematical sans-serif bold small i
    {0x0001D5F7, "j"},    // mathematical sans-serif bold small j
    {0x0001D5F8, "k"},    // mathematical sans-serif bold small k
    {0x0001D5F9, "l"},    // mathematical sans-serif bold small l
    {0x0001D5FA, "m"},    // mathematical sans-serif bold small m
    {0x0001D5FB, "n"},    // mathematical sans-serif bold small n
    {0x0001D5FC, "o"},    // mathematical sans-serif bold small o
    {0x0001D5FD, "p"},    // mathematical sans-serif bold small p
    {0x0001D5FE, "q"},    // mathematical sans-serif bold small q
    {0x0001D5FF, "r"},    // mathematical sans-serif bold small r
    {0x0001D600, "s"},    // mathematical sans-serif bold small s
    {0x0001D601, "t"},    // mathematical sans-serif bold small t
    {0x0001D602, "u"},    // mathematical sans-serif bold small u
    {0x0001D603, "v"},    // mathematical sans-serif bold small v
    {0x0001D604, "w"},    // mathematical sans-serif bold small w
    {0x0001D605, "x"},    // mathematical sans-serif bold small x
    {0x0001D606, "y"},    // mathematical sans-serif bold small y
    {0x0001D607, "z"},    // mathematical sans-serif bold small z
    {0x0001D608, "A"},    // mathematical sans-serif italic capital a
    {0x0001D609, "B"},    // mathematical sans-serif italic capital b
    {0x0001D60A, "C"},    // mathematical sans-serif italic capital c
    {0x0001D60B, "D"},    // mathematical sans-serif italic capital d
    {0x0001D60C, "E"},    // mathematical sans-serif italic capital e
    {0x0001D60D, "F"},    // mathematical sans-serif italic capital f
    {0x0001D60E, "G"},    // mathematical sans-serif italic capital g
    {0x0001D60F, "H"},    // mathematical sans-serif italic capital h
    {0x0001D610, "I"},    // mathematical sans-serif italic capital i
    {0x0001D611, "J"},    // mathematical sans-serif italic capital j
    {0x0001D612, "K"},    // mathematical sans-serif italic capital k
    {0x0001D613, "L"},    // mathematical sans-serif italic capital l
    {0x0001D614, "M"},    // mathematical sans-serif italic capital m
    {0x0001D615, "N"},    // mathematical sans-serif italic capital n
    {0x0001D616, "O"},    // mathematical sans-serif italic capital o
    {0x0001D617, "P"},    // mathematical sans-serif italic capital p
    {0x0001D618, "Q"},    // mathematical sans-serif italic capital q
    {0x0001D619, "R"},    // mathematical sans-serif italic capital r
    {0x0001D61A, "S"},    // mathematical sans-serif italic capital s
    {0x0001D61B, "T"},    // mathematical sans-serif italic capital t
    {0x0001D61C, "U"},    // mathematical sans-serif italic capital u
    {0x0001D61D, "V"},    // mathematical sans-serif italic capital v
    {0x0001D61E, "W"},    // mathematical sans-serif italic capital w
    {0x0001D61F, "X"},    // mathematical sans-serif italic capital x
    {0x0001D620, "Y"},    // mathematical sans-serif italic capital y
    {0x0001D621, "Z"},    // mathematical sans-serif italic capital z
    {0x0001D622, "a"},    // mathematical sans-serif italic small a
    {0x0001D623, "b"},    // mathematical sans-serif italic small b
    {0x0001D624, "c"},    // mathematical sans-serif italic small c
    {0x0001D625, "d"},    // mathematical sans-serif italic small d
    {0x0001D626, "e"},    // mathematical sans-serif italic small e
    {0x0001D627, "f"},    // mathematical sans-serif italic small f
    {0x0001D628, "g"},    // mathematical sans-serif italic small g
    {0x0001D629, "h"},    // mathematical sans-serif italic small h
    {0x0001D62A, "i"},    // mathematical sans-serif italic small i
    {0x0001D62B, "j"},    // mathematical sans-serif italic small j
    {0x0001D62C, "k"},    // mathematical sans-serif italic small k
    {0x0001D62D, "l"},    // mathematical sans-serif italic small l
    {0x0001D62E, "m"},    // mathematical sans-serif italic small m
    {0x0001D62F, "n"},    // mathematical sans-serif italic small n
    {0x0001D630, "o"},    // mathematical sans-serif italic small o
    {0x0001D631, "p"},    // mathematical sans-serif italic small p
    {0x0001D632, "q"},    // mathematical sans-serif italic small q
    {0x0001D633, "r"},    // mathematical sans-serif italic small r
    {0x0001D634, "s"},    // mathematical sans-serif italic small s
    {0x0001D635, "t"},    // mathematical sans-serif italic small t
    {0x0001D636, "u"},    // mathematical sans-serif italic small u
    {0x0001D637, "v"},    // mathematical sans-serif italic small v
    {0x0001D638, "w"},    // mathematical sans-serif italic small w
    {0x0001D639, "x"},    // mathematical sans-serif italic small x
    {0x0001D63A, "y"},    // mathematical sans-serif italic small y
    {0x0001D63B, "z"},    // mathematical sans-serif italic small z
    {0x0001D63C, "A"},    // mathematical sans-serif bold italic capital a
    {0x0001D63D, "B"},    // mathematical sans-serif bold italic capital b
    {0x0001D63E, "C"},    // mathematical sans-serif bold italic capital c
    {0x0001D63F, "D"},    // mathematical sans-serif bold italic capital d
    {0x0001D640, "E"},    // mathematical sans-serif bold italic capital e
    {0x0001D641, "F"},    // mathematical sans-serif bold italic capital f
    {0x0001D642, "G"},    // mathematical sans-serif bold italic capital g
    {0x0001D643, "H"},    // mathematical sans-serif bold italic capital h
    {0x0001D644, "I"},    // mathematical sans-serif bold italic capital i
    {0x0001D645, "J"},    // mathematical sans-serif bold italic capital j
    {0x0001D646, "K"},    // mathematical sans-serif bold italic capital k
    {0x0001D647, "L"},    // mathematical sans-serif bold italic capital l
    {0x0001D648, "M"},    // mathematical sans-serif bold italic capital m
    {0x0001D649, "N"},    // mathematical sans-serif bold italic capital n
    {0x0001D64A, "O"},    // mathematical sans-serif bold italic capital o
    {0x0001D64B, "P"},    // mathematical sans-serif bold italic capital p
    {0x0001D64C, "Q"},    // mathematical sans-serif bold italic capital q
    {0x0001D64D, "R"},    // mathematical sans-serif bold italic capital r
    {0x0001D64E, "S"},    // mathematical sans-serif bold italic capital s
    {0x0001D64F, "T"},    // mathematical sans-serif bold italic capital t
    {0x0001D650, "U"},    // mathematical sans-serif bold italic capital u
    {0x0001D651, "V"},    // mathematical sans-serif bold italic capital v
    {0x0001D652, "W"},    // mathematical sans-serif bold italic capital w
    {0x0001D653, "X"},    // mathematical sans-serif bold italic capital x
    {0x0001D654, "Y"},    // mathematical sans-serif bold italic capital y
    {0x0001D655, "Z"},    // mathematical sans-serif bold italic capital z
    {0x0001D656, "a"},    // mathematical sans-serif bold italic small a
    {0x0001D657, "b"},    // mathematical sans-serif bold italic small b
    {0x0001D658, "c"},    // mathematical sans-serif bold italic small c
    {0x0001D659, "d"},    // mathematical sans-serif bold italic small d
    {0x0001D65A, "e"},    // mathematical sans-serif bold italic small e
    {0x0001D65B, "f"},    // mathematical sans-serif bold italic small f
    {0x0001D65C, "g"},    // mathematical sans-serif bold italic small g
    {0x0001D65D, "h"},    // mathematical sans-serif bold italic small h
    {0x0001D65E, "i"},    // mathematical sans-serif bold italic small i
    {0x0001D65F, "j"},    // mathematical sans-serif bold italic small j
    {0x0001D660, "k"},    // mathematical sans-serif bold italic small k
    {0x0001D661, "l"},    // mathematical sans-serif bold italic small l
    {0x0001D662, "m"},    // mathematical sans-serif bold italic small m
    {0x0001D663, "n"},    // mathematical sans-serif bold italic small n
    {0x0001D664, "o"},    // mathematical sans-serif bold italic small o
    {0x0001D665, "p"},    // mathematical sans-serif bold italic small p
    {0x0001D666, "q"},    // mathematical sans-serif bold italic small q
    {0x0001D667, "r"},    // mathematical sans-serif bold italic small r
    {0x0001D668, "s"},    // mathematical sans-serif bold italic small s
    {0x0001D669, "t"},    // mathematical sans-serif bold italic small t
    {0x0001D66A, "u"},    // mathematical sans-serif bold italic small u
    {0x0001D66B, "v"},    // mathematical sans-serif bold italic small v
    {0x0001D66C, "w"},    // mathematical sans-serif bold italic small w
    {0x0001D66D, "x"},    // mathematical sans-serif bold italic small x
    {0x0001D66E, "y"},    // mathematical sans-serif bold italic small y
    {0x0001D66F, "z"},    // mathematical sans-serif bold italic small z
    {0x0001D670, "A"},    // mathematical monospace capital a
    {0x0001D671, "B"},    // mathematical monospace capital b
    {0x0001D672, "C"},    // mathematical monospace capital c
    {0x0001D673, "D"},    // mathematical monospace capital d
    {0x0001D674, "E"},    // mathematical monospace capital e
    {0x0001D675, "F"},    // mathematical monospace capital f
    {0x0001D676, "G"},    // mathematical monospace capital g
    {0x0001D677, "H"},    // mathematical monospace capital h
    {0x0001D678, "I"},    // mathematical monospace capital i
    {0x0001D679, "J"},    // mathematical monospace capital j
    {0x0001D67A, "K"},    // mathematical monospace capital k
    {0x0001D67B, "L"},    // mathematical monospace capital l
    {0x0001D67C, "M"},    // mathematical monospace capital m
    {0x0001D67D, "N"},    // mathematical monospace capital n
    {0x0001D67E, "O"},    // mathematical monospace capital o
    {0x0001D67F, "P"},    // mathematical monospace capital p
    {0x0001D680, "Q"},    // mathematical monospace capital q
    {0x0001D681, "R"},    // mathematical monospace capital r
    {0x0001D682, "S"},    // mathematical monospace capital s
    {0x0001D683, "T"},    // mathematical monospace capital t
    {0x0001D684, "U"},    // mathematical monospace capital u
    {0x0001D685, "V"},    // mathematical monospace capital v
    {0x0001D686, "W"},    // mathematical monospace capital w
    {0x0001D687, "X"},    // mathematical monospace capital x
    {0x0001D688, "Y"},    // mathematical monospace capital y
    {0x0001D689, "Z"},    // mathematical monospace capital z
    {0x0001D68A, "a"},    // mathematical monospace small a
    {0x0001D68B, "b"},    // mathematical monospace small b
    {0x0001D68C, "c"},    // mathematical monospace small c
    {0x0001D68D, "d"},    // mathematical monospace small d
    {0x0001D68E, "e"},    // mathematical monospace small e
    {0x0001D68F, "f"},    // mathematical monospace small f
    {0x0001D690, "g"},    // mathematical monospace small g
    {0x0001D691, "h"},    // mathematical monospace small h
    {0x0001D692, "i"},    // mathematical monospace small i
    {0x0001D693, "j"},    // mathematical monospace small j
    {0x0001D694, "k"},    // mathematical monospace small k
    {0x0001D695, "l"},    // mathematical monospace small l
    {0x0001D696, "m"},    // mathematical monospace small m
    {0x0001D697, "n"},    // mathematical monospace small n
    {0x0001D698, "o"},    // mathematical monospace small o
    {0x0001D699, "p"},    // mathematical monospace small p
    {0x0001D69A, "q"},    // mathematical monospace small q
    {0x0001D69B, "r"},    // mathematical monospace small r
    {0x0001D69C, "s"},    // mathematical monospace small s
    {0x0001D69D, "t"},    // mathematical monospace small t
    {0x0001D69E, "u"},    // mathematical monospace small u
    {0x0001D69F, "v"},    // mathematical monospace small v
    {0x0001D6A0, "w"},    // mathematical monospace small w
    {0x0001D6A1, "x"},    // mathematical monospace small x
    {0x0001D6A2, "y"},    // mathematical monospace small y
    {0x0001D6A3, "z"},    // mathematical monospace small z
    {0x0001D7CE, "0"},    // mathematical bold digit zero
    {0x0001D7CF, "1"},    // mathematical bold digit one
    {0x0001D7D0, "2"},    // mathematical bold digit two
    {0x0001D7D1, "3"},    // mathematical bold digit three
    {0x0001D7D2, "4"},    // mathematical bold digit four
    {0x0001D7D3, "5"},    // mathematical bold digit five
    {0x0001D7D4, "6"},    // mathematical bold digit six
    {0x0001D7D5, "7"},    // mathematical bold digit seven
    {0x0001D7D6, "8"},    // mathematical bold digit eight
    {0x0001D7D7, "9"},    // mathematical bold digit nine
    {0x0001D7D8, "0"},    // mathematical double-struck digit zero
    {0x0001D7D9, "1"},    // mathematical double-struck digit one
    {0x0001D7DA, "2"},    // mathematical double-struck digit two
    {0x0001D7DB, "3"},    // mathematical double-struck digit three
    {0x0001D7DC, "4"},    // mathematical double-struck digit four
    {0x0001D7DD, "5"},    // mathematical double-struck digit five
    {0x0001D7DE, "6"},    // mathematical double-struck digit six
    {0x0001D7DF, "7"},    // mathematical double-struck digit seven
    {0x0001D7E0, "8"},    // mathematical double-struck digit eight
    {0x0001D7E1, "9"},    // mathematical double-struck digit nine
    {0x0001D7E2, "0"},    // mathematical sans-serif digit zero
    {0x0001D7E3, "1"},    // mathematical sans-serif digit one
    {0x0001D7E4, "2"},    // mathematical sans-serif digit two
    {0x0001D7E5, "3"},    // mathematical sans-serif digit three
    {0x0001D7E6, "4"},    // mathematical sans-serif digit four
    {0x0001D7E7, "5"},    // mathematical sans-serif digit five
    {0x0001D7E8, "6"},    // mathematical sans-serif digit six
    {0x0001D7E9, "7"},    // mathematical sans-serif digit seven
    {0x0001D7EA, "8"},    // mathematical sans-serif digit eight
    {0x0001D7EB, "9"},    // mathematical sans-serif digit nine
    {0x0001D7EC, "0"},    // mathematical sans-serif bold digit zero
    {0x0001D7ED, "1"},    // mathematical sans-serif bold digit one
    {0x0001D7EE, "2"},    // mathematical sans-serif bold digit two
    {0x0001D7EF, "3"},    // mathematical sans-serif bold digit three
    {0x0001D7F0, "4"},    // mathematical sans-serif bold digit four
    {0x0001D7F1, "5"},    // mathematical sans-serif bold digit five
    {0x0001D7F2, "6"},    // mathematical sans-serif bold digit six
    {0x0001D7F3, "7"},    // mathematical sans-serif bold digit seven
    {0x0001D7F4, "8"},    // mathematical sans-serif bold digit eight
    {0x0001D7F5, "9"},    // mathematical sans-serif bold digit nine
    {0x0001D7F6, "0"},    // mathematical monospace digit zero
    {0x0001D7F7, "1"},    // mathematical monospace digit one
    {0x0001D7F8, "2"},    // mathematical monospace digit two
    {0x0001D7F9, "3"},    // mathematical monospace digit three
    {0x0001D7FA, "4"},    // mathematical monospace digit four
    {0x0001D7FB, "5"},    // mathematical monospace digit five
    {0x0001D7FC, "6"},    // mathematical monospace digit six
    {0x0001D7FD, "7"},    // mathematical monospace digit seven
    {0x0001D7FE, "8"},    // mathematical monospace digit eight
    {0x0001D7FF, "9"}     // mathematical monospace digit nine
};
