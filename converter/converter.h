#pragma once

#include <fstream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "../base/base.h"
#include "../io/printer.h"

//  type conversions
uint8_t storage_to_byte(storage_p ps);
uint16_t storage_to_word(storage_p ps);
uint32_t storage_to_dword(storage_p ps);
void dword_to_storage(uint32_t dw, storage_p ps);
storage_p hex_to_bin(storage_p hex);

//  decryption algorithms
void dexor(storage_p enc, storage_p key, int k_len);
void dexor_key_change(storage_p enc, storage_p key);
