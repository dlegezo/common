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

void file::map_file() {
    mapping->reserve(size);
    mapping = get_bytes(size);
}

storage_p file::get_mapping() {
    return mapping;
}

//TODO check if not end of file
void file::set_offset(int offset, int mode = 0) {
    if (!mode) {
        fs.seekg(offset, std::ios_base::beg);
    } else if (mode == 1) {
        fs.seekg(offset, std::ios_base::end);
    } else {
        fs.seekg(offset, std::ios_base::cur);
    }
}

storage_p file::get_bytes(int len) {
    uint8_t b[len];
    storage r;
    r.reserve(len);
    fs.read(reinterpret_cast<char *>(b), len);
    for (int i=0; i<len; i++) {
        r.push_back(b[i]);   
    }
    return make_shared<storage>(r);
}

uint8_t file::get_byte() {
    return get_bytes(1)->at(0);
}

uint16_t file::get_word() {
    return storage_to_word(get_bytes(2));
}

uint32_t file::get_dword() {
    return storage_to_dword(get_bytes(4));
}

void file::dump_to_file(const string& name, storage_p content) {
    ofstream of(name, ofstream::binary | ofstream::out);
    of.write(reinterpret_cast<const char *>(content->data()), content->size());
    of.close();
}

// TODO check if enough bytes are available
// TODO check if string_view is possible
void file::dump_stream_to_file(const string& name, int offset, int len) {
    ofstream of(name, ofstream::binary | ofstream::out);
    set_offset(offset);
    of.write(reinterpret_cast<const char *>(get_bytes(len)->data()), len);
    of.close();
}

//TODO check if enough bytes are available
void file::dump_mapped_to_file(const string& name, int offset, int len) {
    ofstream of(name, ofstream::binary | ofstream::out);
    auto m_it = mapping->begin() + offset;
    storage r(m_it, m_it + len);
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