#pragma once

#include <fstream>
#include <iterator>
#include <vector>
#include "../base/base.h"
#include "../io/printer.h"

class converter {
private:
public:
    explicit converter();
    ~converter();
//  type conversions
    uint32_t storage_to_dword(storage_it);
    void dword_to_storage(uint32_t, storage_it);
//  decryption algs
    void dexor(storage_it enc_it, int e_len, storage_it key, int k_len);
    void dexor_key_change(storage_it enc_it, int e_len, storage_it key_it, int k_len);
};
