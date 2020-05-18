#include "converter.h"

using namespace std;

uint8_t storage_to_byte(storage_p ps) {
    return ps->at(0);
}

uint16_t storage_to_word(storage_p ps) {
    return (ps->at(1) << 8) | ps->at(0);
};

uint32_t storage_to_dword(storage_p ps) {
    return (ps->at(3) << 24) | ps->at(2) << 16 | (ps->at(1) << 8) | ps->at(0);
};

void dword_to_storage(uint32_t dw, storage_p ps) {
    for (int i = 0; i<4; ++i) {
        ps->at(i) = dw & 0xFF;
        dw = dw >> 8;
    }
};

// for microcin - take nearby hex bytes and keep only two digits in resulting bin byte
storage_p hex_to_bin(storage_p hex) {
    storage r;
    storage_it it = hex->begin();
    while (it != hex->end()) {
        r.push_back(((0x10 * (*it)) & 0xFF) | ((*next(it)) & 0x0F));
        if (it != hex->end()) {
            it = next(it);
        }
        if (it != hex->end()) {
            it = next(it);
        }
    }
    return make_shared<storage>(r);
}

void dexor(storage_p enc, storage_p key_it, int k_len) {
    for (int i=0; i < enc->size(); ++i) {
        enc->at(i) = enc->at(i) ^ key_it->at(i % k_len);
    }
}

//void dexor_key_change(storage_it enc_it, int e_len, storage_it key_it, int k_len) {
//    for (auto i=0; i < e_len; ++i) {
//        *enc_it = *enc_it ^ key_it[i % k_len];
//        ++enc_it;
//        if (i != 0 && (i+1) % k_len == 0) {
//            auto dw_vec = storage_to_dword(key_it);
//            auto dw_dec = storage_to_dword(prev(enc_it,4));
//            auto t = dw_dec + dw_vec;
//            dword_to_storage(t, key_it);
//            print_storage_ascii(key_it, 4);
//        }
//    }
//};
