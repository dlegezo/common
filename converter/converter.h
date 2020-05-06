#pragma once

#include <fstream>
#include <iterator>

class converter {
private:
    std::ifstream fs;
public:
    explicit converter(std::ifstream init_fs);
    ~converter();
};

//uint8_t combine_bytes(std::ifstream &fs);
//uint8_t *combine_bytes_len(std::ifstream& fs, uint8_t *b, uint32_t l);
//void dexor(uint8_t *b, int b_len, uint8_t *k, int k_len);
