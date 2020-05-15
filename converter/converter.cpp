#include "converter.h"

using namespace std;

converter::converter() = default;

converter::~converter() = default;

uint32_t converter::storage_to_dword(storage_it v_it) {
    uint32_t r = 0;
    for (int i = 0; i<4; ++i) {
        r = (r << 8) | v_it[i];
    }
    return r;
};

void converter::dword_to_storage(uint32_t dw, storage_it v_it) {
    for (int i = 0; i<4; ++i) {
        v_it[i] = dw & 0xFF;
        dw = dw>>8;
    }
};

void converter::dexor(storage_it enc_it, int e_len, storage_it key_it, int k_len) {
    for (int i=0; i<e_len; ++i) {
        *enc_it = *enc_it ^ key_it[i % k_len];
        ++enc_it;
    }
}

void converter::dexor_key_change(storage_it enc_it, int e_len, storage_it key_it, int k_len) {
    for (auto i=0; i < e_len; ++i) {
        *enc_it = *enc_it ^ key_it[i % k_len];
        ++enc_it;
        if (i != 0 && (i+1) % k_len == 0) {
            auto dw_vec = storage_to_dword(key_it);
            auto dw_dec = storage_to_dword(prev(enc_it,4));
            auto t = dw_dec + dw_vec;
            dword_to_storage(t, key_it);
            print_vector_len(key_it, 4);
        }
    }
};
