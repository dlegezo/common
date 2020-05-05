#pragma once

#include <fstream>
#include <iterator>

class converter {
private:
    std::istream_iterator<uint8_t> fit;
public:
    explicit converter(std::istream_iterator<uint8_t> init_fit);
    ~converter();
    uint16_t make_word();
    uint32_t make_dword();
};

//uint8_t get_byte(std::ifstream& fs);
//uint16_t get_word(std::ifstream& fs);
//uint32_t get_dword(std::ifstream& fs);
//uint8_t combine_bytes(std::ifstream &fs);
//uint8_t *combine_bytes_len(std::ifstream& fs, uint8_t *b, uint32_t l);
//void dexor(uint8_t *b, int b_len, uint8_t *k, int k_len);
