#include "converter.h"

using namespace std;

converter::converter() = default;

converter::~converter() = default;

// TODO check if key_it caching is the best way
void converter::dexor(storage_it enc_it, int e_len, storage_it key_it, int k_len) {
    for (int i=0; i<e_len; ++i) {
        *enc_it = *enc_it ^ key_it[i % k_len];
        ++enc_it;
    }
}

uint32_t converter::vector_to_dword(storage_it v_it) {
    uint32_t r = 0;
    for (uint8_t i = 3; i>=0; --i) {
        r = (r << 8) | v_it[i];
    }
    return r;
};

void converter::dexor_key_change(storage_it enc_it, int e_len, storage_it key_it, int k_len) {
    for (int i=0; i<e_len; ++i) {
        auto curr_key_it = key_it;
        *enc_it = *enc_it ^ curr_key_it[i % k_len];
        ++enc_it;
        if (i != 0 && (i+1) % k_len == 0) {
            auto d = vector_to_dword(curr_key_it);

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
