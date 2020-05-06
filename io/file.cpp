#include "file.h"

using namespace std;

file::file(const string& name) {
    if (name.c_str()) {
        fs.open(name, ifstream::binary | ifstream::in);
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

vector<uint8_t> file::get_bytes(int len) {
    uint8_t b[len];
    std::vector<uint8_t> r;
    r.reserve(len);
    fs.read(reinterpret_cast<char *>(b), len);
    for (int i=0; i<len; i++) {
        r.push_back(b[i]);   
    }
    return move(r);
}

//TODO check if not end of file
void file::set_offset(int offset) {
    fs.seekg(offset);
}

//TODO check if enough bytes are available
void file::dump_to_file(const std::string& name, int len) {
    ofstream of(name, ofstream::binary | ofstream::out);
    of << get_bytes(len).data();
    of.close();
}

//size_t find_in_file(ifstream& fs, const string& k) {
//    stringstream ss;
//    auto a = fs.tellg();
//    ss << fs.rdbuf();
//    fs.seekg(a);
//    return ss.str().find(k);
//}