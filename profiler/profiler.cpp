#include "profiler.h"

using namespace std::chrono;

profiler::profiler(const std::string& init_msg) : msg{init_msg}, start{steady_clock::now()} {}

profiler::~profiler() {
    stop = steady_clock::now();
    std::cout << msg << ": " << duration_cast<milliseconds>(stop - start).count() << " ms" << std::endl;
}