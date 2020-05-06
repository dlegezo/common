#pragma once

#include <fstream>
#include <iterator>
#include <vector>

class converter {
private:
public:
    explicit converter();
    ~converter();
    void dexor(std::vector<uint8_t>::iterator enc_it, int e_len, std::vector<uint8_t>::iterator key, int k_len);
};

//uint8_t combine_bytes(std::ifstream &fs);
//uint8_t *combine_bytes_len(std::ifstream& fs, uint8_t *b, uint32_t l);
