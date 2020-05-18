#pragma once

#include <vector>
#include <iostream>
#include <memory>

typedef std::vector<uint8_t> storage;
typedef std::shared_ptr<std::vector<uint8_t>> storage_p;
typedef std::vector<uint8_t>::iterator storage_it;