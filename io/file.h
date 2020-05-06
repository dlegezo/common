#pragma once

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <filesystem>

class file {
private:
    std::ifstream fs;
    uintmax_t size;
    std::vector<uint8_t> mapped;
public:
    explicit file(const std::string& name);
    ~file();
    uintmax_t get_size();
    std::vector<uint8_t>::iterator get_mapped_it();
    void set_offset(int offset);
    void map_file();
    std::vector<uint8_t> get_bytes(int len);
    void dump_stream_to_file(const std::string& name, int offset, int len);
    void dump_mapped_to_file(const std::string& name, int offset, int len);
};

//size_t find_in_file(std::ifstream& fs, const std::string& k);