#include "file.h"

using namespace std;

file::file(const string& fn) {
    fs.open(fn);
}

file::~file() {
    fs.close();
}

ifstream file::get_fs() {
    return move(fs);
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