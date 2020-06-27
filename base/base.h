#pragma once

#include <vector>
#include <iostream>
#include <memory>
#include <z3.h>

typedef std::vector<uint8_t> storage;
typedef std::shared_ptr<storage> storage_p;
typedef storage::iterator storage_it;

storage_p build_storage_string(const std::string &val);
storage_p build_storage_bin(unsigned char *val, int len);