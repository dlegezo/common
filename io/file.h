#pragma once

#include <iostream>
#include <fstream>

class file {
private:
    std::ifstream f;
public:
    explicit file(const std::string& fn);
    ~file();
    std::ifstream* get();
};