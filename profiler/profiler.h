#pragma once

#include <chrono>
#include <iostream>
#include <string>

class profiler {
private:
    const std::string msg;
    const std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point stop;
public:
    explicit profiler(const std::string& init_msg);
    ~profiler();
};