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

vector<uint8_t> file::get_bytes(int l) {
    uint8_t b[l];
    std::vector<uint8_t> r;
    fs >> b;
    for (int i=0; i<l; i++) {
        r.push_back(b[i]);   
    }
    return move(r);
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