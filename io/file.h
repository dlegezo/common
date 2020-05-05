#pragma once

#include <iostream>
#include <fstream>
#include <iterator>

class file {
private:
    std::ifstream fs;
public:
    explicit file(const std::string& fn);
    ~file();
    std::ifstream get_fs();
};

//void dump_to_file(const std::string &fn, uint8_t *content, int len);
//uint8_t *read_from_file(std::ifstream& fs, uint8_t *content, int offset, int len);
//size_t find_in_file(std::ifstream& fs, const std::string& k);