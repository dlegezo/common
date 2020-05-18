#pragma once

#include <fstream>
#include <iterator>
#include <vector>
#include "../base/base.h"
#include "../io/printer.h"

//  type conversions
uint32_t storage_to_dword(storage_p ps);
uint16_t storage_to_word(storage_p ps);
void dword_to_storage(uint32_t dw, storage_p ps);

//  decryption algorithms
void dexor(storage_p enc, storage_p key, int k_len);
void dexor_key_change(storage_it enc_it, int e_len, storage_it key_it, int k_len);
