#pragma once

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

class file {
private:
    std::ifstream fs;
public:
    explicit file(const std::string& name);
    ~file();
    std::vector<uint8_t> get_bytes(int len);
    void set_offset(int offset);
    void dump_to_file(const std::string& name, int len);
};

//size_t find_in_file(std::ifstream& fs, const std::string& k);