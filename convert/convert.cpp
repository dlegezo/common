#include "convert.h"

using namespace std;

converter::converter(istream_iterator<uint8_t> init_fit) : fit{init_fit} {}

converter::~converter() {};

uint16_t converter::make_word() {
    return *fit | (*(++fit) << 8);
}

uint32_t converter::make_dword() {
    return *fit | (*(++fit) << 8) | (*(++fit) << 8) | (*(++fit) << 8);
}

//uint8_t get_byte(ifstream &fs) {
//    char b[1];
//    fs.read(b, 1);
//    return (uint8_t)b[0];
//}
//
//uint16_t get_word(ifstream &fs) {
//    uint8_t b[2];
//    fs.read((char *)b, 2);
//    return make_word(b);
//}
//
//uint32_t get_dword(ifstream &fs) {
//    uint8_t b[4];
//    fs.read((char *)b, 4);
//    return make_dword(b);
//}
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
//
//void dexor(uint8_t *b, int b_len, uint8_t *k, int k_len) {
//    for (int i = 0; i < b_len ; i++) {
//        b[i] ^= k[i % k_len];
//    }
//}
