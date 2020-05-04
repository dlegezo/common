
#include "profiler.h"

using namespace std::chrono;

profiler::profiler(const std::string &init_msg) {
    start = steady_clock::now();
    msg = init_msg;
}

profiler::~profiler() {
    stop = steady_clock::now();
    auto d = duration_cast<milliseconds>(stop - start);
    std::cout << msg << ": " << d.count() << " ms" << std::endl;
}