#include "file.h"

using namespace std;

file::file(const string& fn) {
    f.open(fn);
}

file::~file() {
    f.close();
}

std::ifstream* file::get() {
    return &f;
}
