#pragma once

#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>

class file {
private:
    std::ifstream fs;
public:
    explicit file(const std::string& fn);
    ~file();
    std::vector<uint8_t> get_bytes(int l);
};

//void dump_to_file(const std::string &fn, uint8_t *content, int len);
//uint8_t *read_from_file(std::ifstream& fs, uint8_t *content, int offset, int len);
//size_t find_in_file(std::ifstream& fs, const std::string& k);