#include "converter.h"

using namespace std;

converter::converter(ifstream init_fs) : fs{move(init_fs)} {}

converter::~converter() {};

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
