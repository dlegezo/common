#pragma once

#include <fstream>
#include <iterator>
#include <vector>

typedef std::vector<uint8_t> storage;
typedef std::vector<uint8_t>::iterator storage_it;

class converter {
private:
public:
    explicit converter();
    ~converter();
    uint32_t vector_to_dword(storage_it);
    void dexor(storage_it enc_it, int e_len, storage_it key, int k_len);
    void dexor_key_change(storage_it enc_it, int e_len, storage_it key_it, int k_len);
};

//uint8_t combine_bytes(std::ifstream &fs);
//uint8_t *combine_bytes_len(std::ifstream& fs, uint8_t *b, uint32_t l);
