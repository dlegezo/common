#include "file.h"

using namespace std;

// TODO check if string_view is possible through all the code
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

uintmax_t file::get_size() const {
    return size;
}

storage_p file::get_mapping() {
  return mapping;
}

void file::map_file() {
    storage s;
    s.reserve(size);
    mapping = make_shared<storage>(s);
    mapping = get_bytes(size);
}

void file::patch_mapping(storage_p dec, int offset) {
    int i = 0;
    for (auto e : *dec) {
        mapping->at(offset+i) = e;
        ++i;
    }
}

void file::set_offset(int offset, int mode = 0) {
    if (!mode) {
        fs.seekg(offset, std::ios_base::beg);
    } else if (mode == 1) {
        fs.seekg(offset, std::ios_base::end);
    } else {
        fs.seekg(offset, std::ios_base::cur);
    }
}

storage_it file::find_in_mapping(const storage_p k) {
	return search(mapping->begin(), mapping->end(), k->begin(), k->end());
}

storage_p file::get_bytes(int len) {
    uint8_t b[len];
  	fs.read(reinterpret_cast<char *>(b), len);
  	if (fs.gcount()) {
	  storage r(b, b+len);
	  return make_shared<storage>(r);
  	} else {
  	  runtime_error e("End of input file");
  	  throw e;
  	}
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

void file::dump_region_to_file(const string &name, int offset, int len) {
    ofstream of(name, ofstream::binary | ofstream::out);
    set_offset(offset);
    of.write(reinterpret_cast<const char *>(get_bytes(len)->data()), len);
    of.close();
}

// check connection
void file::dump_mapping_to_file(const string& name) {
    ofstream of(name, ofstream::binary | ofstream::out);
    of.write(reinterpret_cast<const char *>(mapping->data()), size);
    of.close();
}