#include "converter.h"

using namespace std;

converter::converter() = default;

converter::~converter() = default;

void converter::dexor(vector<uint8_t>::iterator enc_it, int e_len, vector<uint8_t>::iterator key_it, int k_len) {
    auto key_it_cached = key_it;
    for (int i=0; i<e_len; ++i) {
        *enc_it = *enc_it ^ *key_it;
        ++enc_it;
        ++key_it;
        if (i != 0 && i % k_len == 0) {
            key_it = key_it_cached;
        }
    }
};

//
//uint8_t combine_bytes(ifstream &fs) {
//    uint8_t u[2];
//    fs.read((char *)u, 2);
//    return ((0x10 * u[0]) & 0xFF) | (u[1] & 0x0F);
//}
//
//uint8_t *combine_bytes_len(ifstream& fs, uint8_t *b, uint32_t l) {
//    uint8_t u[2];
//    for (int i = 0; i < l; ++i) {
//        fs.read((char *)u, 2);
//        b[i] = ((0x10 * u[0]) & 0xFF) | (u[1] & 0x0F);
//    }
//    return b;
//}
