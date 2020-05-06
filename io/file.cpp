#include "file.h"
#include "../profiler/profiler.h"

using namespace std;

file::file(const string& fn) {
    if (fn.c_str()) {
        fs.open(fn);
        if (!fs.is_open()) {
            throw runtime_error("Please provide existing file name");
        }
    } else {
        throw runtime_error("File name couldn't be empty");
    }
}

file::~file() {
    fs.close();
}

uint8_t file::get_byte() {
    uint8_t b;
    fs >> b;
    return b;
}

array<uint8_t, 2> file::get_word() {
    uint8_t b[2];
    array<uint8_t, 2> r;
    fs >> b;
    r[0] = b[0];
    r[1] = b[1];
    return r;
}

array<uint8_t, 4> file::get_dword() {
    uint8_t b[4];
    array<uint8_t, 4> r;
    fs >> b;
    r[0] = b[0];
    r[1] = b[1];
    r[2] = b[2];
    r[3] = b[3];
    return r;
}

//void dump_to_file(const string &fn, uint8_t *content, int len) {
//    ofstream fs(fn, ofstream::binary | ofstream::out);
//    fs.write(reinterpret_cast<const char *>(content), len);
//    fs.close();
//}
//
//uint8_t *read_from_file(ifstream& fs, uint8_t *content, int offset, int len) {
//    fs.seekg(offset);
//    fs.read((char *)content, len);
//    return content;
//}
//
//size_t find_in_file(ifstream& fs, const string& k) {
//    stringstream ss;
//    auto a = fs.tellg();
//    ss << fs.rdbuf();
//    fs.seekg(a);
//    return ss.str().find(k);
//}