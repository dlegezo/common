#include "base.h"

using namespace std;

// TODO add template to build from any container, not only strings
// TODO consider refactor as class with copy constructor
storage_p build_storage(const string &s) {
	storage r;
	for (auto e : s) {
	  r.push_back(e);
	}
	return make_shared<storage>(r);
}