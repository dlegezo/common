#include "printer.h"

using namespace std;

void print_vector(const std::vector<uint8_t>& v) {
    for (auto e : v) {
        cout << hex << e << " ";
    }
    cout << endl;
}