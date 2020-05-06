#include "file.h"

using namespace std;

file::file(const string& name) {
    if (name.c_str()) {
        fs.open(name, ifstream::binary | ifstream::in);
        if (!fs.good()) {
            throw runtime_error("Please provide existing file name");
        }
        size = filesystem::file_size(name);
    } else {
        throw runtime_error("File name couldn't be empty");
    }
}

file::~file() {
    fs.close();
}

uintmax_t file::get_size() {
    return size;
}

vector<uint8_t>::iterator file::get_mapped_it() {
    return mapped.begin();
}

//TODO check if not end of file
void file::set_offset(int offset) {
    fs.seekg(offset);
}

void file::map_file() {
    mapped.reserve(size);
    mapped = get_bytes(size);
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

//TODO check if enough bytes are available
void file::dump_stream_to_file(const std::string& name, int offset, int len) {
    ofstream of(name, ofstream::binary | ofstream::out);
    set_offset(offset);
    of << get_bytes(len).data();
    of.close();
}

//TODO check if enough bytes are available
void file::dump_mapped_to_file(const std::string& name, int offset, int len) {
    ofstream of(name, ofstream::binary | ofstream::out);
    auto m_it = mapped.begin() + offset;
    vector<uint8_t> r(m_it, m_it + len);
    of.write(reinterpret_cast<const char *>(r.data()), len - offset);
    of.close();
}

//size_t find_in_file(ifstream& fs, const string& k) {
//    stringstream ss;
//    auto a = fs.tellg();
//    ss << fs.rdbuf();
//    fs.seekg(a);
//    return ss.str().find(k);
//}