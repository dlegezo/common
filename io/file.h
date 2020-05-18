#pragma once

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <filesystem>
#include "../base/base.h"
#include "../converter/converter.h"

class file {
private:
    std::ifstream fs;
    uintmax_t size;
    storage_p mapping;
public:
    explicit file(const std::string& name);
    ~file();

    // memory mapping
    void map_file();
    storage_p get_mapping();

    // moving back and forward
    uintmax_t get_size();
    void set_offset(int offset, int mode); // 0 - beg, 1 - end, other - cur

    // obtain content
    storage_p get_bytes(int len);
    uint8_t get_byte();
    uint16_t get_word();
    uint32_t get_dword();

    // save to disk
    void dump_to_file(const std::string& name, storage_p content);
    void dump_stream_to_file(const std::string& name, int offset, int len);
    void dump_mapped_to_file(const std::string& name, int offset, int len);
};

//size_t find_in_file(std::ifstream& fs, const std::string& k);