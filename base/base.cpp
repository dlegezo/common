#include "base.h"

using namespace std;

// TODO add template to build from any container, not only strings
storage_p build_storage_string(const string &val) {
  storage r;
  for (auto e : val) {
    r.push_back(e);
  }
  return make_shared<storage>(r);
}

storage_p build_storage_bin(unsigned char *val, int len) {
  storage r;
  int i;
  for (i=0; i<len; ++i) {
      r.push_back(val[i]);
    }
  return make_shared<storage>(r);
}