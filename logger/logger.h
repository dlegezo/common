#pragma once

#include <vector>
#include <string>
#include <iostream>

class logger {
public:
    std::vector<std::string> msg;
private:
    explicit logger(const std::string& init_msg);
    ~logger();
    void add_msg(const std::string& new_msg);
    void print_log();
};