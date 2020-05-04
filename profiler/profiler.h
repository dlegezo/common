
#pragma once

#include <chrono>
#include <iostream>
#include <string>

class profiler {
private:
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point stop;
    std::string msg;
public:
    explicit profiler(const std::string &init_msg);
    ~profiler();
};