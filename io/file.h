#pragma once

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <filesystem>
#include "../base/base.h"

class file {
private:
    std::ifstream fs;
    uintmax_t size;
    storage mapped;
public:
    explicit file(const std::string& name);
    ~file();
    uintmax_t get_size();
    storage_it get_mapped_it();
    void set_offset(int offset);
    void map_file();
    storage get_bytes(int len);
    void dump_stream_to_file(const std::string& name, int offset, int len);
    void dump_mapped_to_file(const std::string& name, int offset, int len);
};

//size_t find_in_file(std::ifstream& fs, const std::string& k);