#include <iostream>

using namespace std;

const int HAMZE = 0;
const int AA = 1;
const int ALEF = 2;
const int BE = 3;
const int PE = 4;
const int TE = 5;
const int SE = 6;
const int JIM = 7;
const int CHE = 8;
const int HE = 9;
const int KHE = 10;
const int DAL = 11;
const int ZAL = 12;
const int RE = 13;
const int ZE = 14;
const int JE = 15;
const int SIN = 16;
const int SHIN = 17;
const int SAD = 18;
const int ZAD = 19;
const int TA = 20;
const int ZA = 21;
const int EIN = 22;
const int GHEIN = 23;
const int FA = 24;
const int GHAF = 25;
const int KAF = 26;
const int GAF = 27;
const int LAM = 28;
const int MIM = 29;
const int NOON = 30;
const int VAV = 31;
const int H = 32;
const int YE = 33;
const int ZERO = 34;
const int ONE = 35;
const int TWO = 36;
const int THREE = 37;
const int FOUR = 38;
const int FIVE = 39;
const int SIX = 40;
const int SEVEN = 41;
const int EIGHT = 42;
const int NINE = 43;
const int QM = 44;
const int SPACE = 45;
const int LA = 46;
const int VIRGOOL = 47;

const int JLA = 0;
const int JLR = 1;
const int JLM = 2;
const int JLL = 3;
const unsigned char join_map[][4] = {
    {0x8f, 0x8f, 0x8e, 0x8e}, // HAMZE
    {0x8d, 0x8d, 0x8d, 0x8d}, // AA
    {0x90, 0x91, 0x90, 0x90}, // ALEF
    {0x92, 0x92, 0x93, 0x93}, // BE
    {0x94, 0x94, 0x95, 0x95}, // PE
    {0x96, 0x96, 0x97, 0x97}, // TE
    {0x98, 0x98, 0x99, 0x99}, // SE
    {0x9a, 0x9a, 0x9b, 0x9b}, // JIM
    {0x9c, 0x9c, 0x9d, 0x9d}, // CHE
    {0x9e, 0x9e, 0x9f, 0x9f}, // HE
    {0xa0, 0xa0, 0xa1, 0xa1}, // KHE
    {0xa2, 0xa2, 0xa2, 0xa2}, // DAL
    {0xa3, 0xa3, 0xa3, 0xa3}, // ZAL
    {0xa4, 0xa4, 0xa4, 0xa4}, // RE
    {0xa5, 0xa5, 0xa5, 0xa5}, // ZE
    {0xa6, 0xa6, 0xa6, 0xa6}, // JE
    {0xa7, 0xa7, 0xa8, 0xa8}, // SIN
    {0xa9, 0xa9, 0xaa, 0xaa}, // SHIN
    {0xab, 0xab, 0xac, 0xac}, // SAD
    {0xad, 0xad, 0xae, 0xae}, // ZAD
    {0xaf, 0xaf, 0xaf, 0xaf}, // TA
    {0xe0, 0xe0, 0xe0, 0xe0}, // ZA
    {0xe1, 0xe2, 0xe3, 0xe4}, // EIN
    {0xe5, 0xe6, 0xe7, 0xe8}, // GHEIN
    {0xe9, 0xe9, 0xea, 0xea}, // FA
    {0xeb, 0xeb, 0xec, 0xec}, // GHAF
    {0xed, 0xed, 0xee, 0xee}, // KAF
    {0xef, 0xef, 0xf0, 0xf0}, // GAF
    {0xf1, 0xf1, 0xf3, 0xf3}, // LAM
    {0xf4, 0xf4, 0xf5, 0xf5}, // MIM
    {0xf6, 0xf6, 0xf7, 0xf7}, // NOON
    {0xf8, 0xf8, 0xf8, 0xf8}, // VAV
    {0xf9, 0xf9, 0xfa, 0xfb}, // H
    {0xfd, 0xfc, 0xfe, 0xfe}, // YE
    {0x80, 0x80, 0x80, 0x80}, // ZERO
    {0x81, 0x81, 0x81, 0x81}, // ONE
    {0x82, 0x82, 0x82, 0x82}, // TWO
    {0x83, 0x83, 0x83, 0x83}, // THREE
    {0x84, 0x84, 0x84, 0x84}, // FOUR
    {0x85, 0x85, 0x85, 0x85}, // FIVE
    {0x86, 0x86, 0x86, 0x86}, // SIX
    {0x87, 0x87, 0x87, 0x87}, // SEVEN
    {0x88, 0x88, 0x88, 0x88}, // EIGHT
    {0x89, 0x89, 0x89, 0x89}, // NINE
    {0x8c, 0x8c, 0x8c, 0x8c}, // QM
    {0xff, 0xff, 0xff, 0xff}, // SPACE
    {0xf2, 0xf2, 0xf2, 0xf2}, // LA
    {0x8a, 0x8a, 0x8a, 0x8a}, // VIRGOOL
};

const int JMR = 0;
const int JMML = 1;

typedef enum {false, true} bool;

const bool join_modes[][2] = {
    {false, true}, // HAMZE
    {false, false}, // AA
    {true, false}, // ALEF
    {true, true}, // BE
    {true, true}, // PE
    {true, true}, // TE
    {true, true}, // SE
    {true, true}, // JIM
    {true, true}, // CHE
    {true, true}, // HE
    {true, true}, // KHE
    {true, false}, // DAL
    {true, false}, // ZAL
    {true, false}, // RE
    {true, false}, // ZE
    {true, false}, // JE
    {true, true}, // SIN
    {true, true}, // SHIN
    {true, true}, // SAD
    {true, true}, // ZAD
    {true, true}, // TA
    {true, true}, // ZA
    {true, true}, // EIN
    {true, true}, // GHEIN
    {true, true}, // FA
    {true, true}, // GHAF
    {true, true}, // KAF
    {true, true}, // GAF
    {true, true}, // LAM
    {true, true}, // MIM
    {true, true}, // NOON
    {true, false}, // VAV
    {true, true}, // H
    {true, true}, // YE
    {false, false}, // ZERO
    {false, false}, // ONE
    {false, false}, // TWO
    {false, false}, // THREE
    {false, false}, // FOUR
    {false, false}, // FIVE
    {false, false}, // SIX
    {false, false}, // SEVEN
    {false, false}, // EIGHT
    {false, false}, // NINE
    {false, false}, // QM
    {false, false}, // SPACE
    {true, false}, // LA
    {false, false}, // VIRGOOL
};

unsigned char internal_index(unsigned char i) {
    if (i >= 0x30 && i <= 0x39)
        return ZERO + i - 0x30;

    switch (i) {
        case 0x2c:
        case 0x82:
            return VIRGOOL;
        case 0x20:
            return SPACE;
        case 0x3f:
        case 0xbf:
            return QM;
    case 0xc6:
    case 0xec:
    case 0xed:
            return YE;
    case 0xc1:
            return HAMZE;
    case 0xc2:
            return AA;
    case 0xc3:
    case 0xc5:
    case 0xc7:
            return ALEF;
    case 0xc4:
            return VAV;
    case 0xc8:
            return BE;
    case 0xc0:
    case 0xc9:
            return H;
    case 0x8a:
    case 0xca:
            return TE;
    case 0xcb:
            return SE;
    case 0xcc:
            return JIM;
    case 0x8d:
            return CHE;
    case 0xcd:
            return HE;
    case 0xce:
            return KHE;
    case 0x8f:
    case 0xcf:
            return DAL;
    case 0xd0:
            return ZAL;
    case 0x9a:
    case 0xd1:
            return RE;
    case 0x8e:
            return JE;
    case 0xd2:
            return ZE;
    case 0xd3:
            return SIN;
    case 0xd4:
            return SHIN;
    case 0xd5:
            return SAD;
    case 0xd6:
            return ZAD;
    case 0xd7:
            return TA;
    case 0xd8:
            return ZA;
    case 0xd9:
            return EIN;
    case 0xda:
            return GHEIN;
    case 0x98:
            return KAF;
    case 0xdd:
            return FA;
    case 0xde:
            return GHAF;
    case 0x90:
            return GAF;
    case 0xe1:
            return LAM;
    case 0xe3:
            return MIM;
    case 0xe3:
            return NOON;
    case 0x81:
            return PE;
        default:
            return -1;
    }
}

void conver_windows1256_to_iransystem(char * buffer, int length)
{

}


int main()
{

    return 0;
}
