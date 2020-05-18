#include "printer.h"

using namespace std;

void print_storage_hex(const storage_p ps) {
    for (auto e : *ps) {
        cout << setw(2) << setfill('0') << hex << static_cast<int>(e) << " ";
    }
    cout << endl;
}

void print_storage_ascii(const storage_p ps) {
    for (auto e : *ps) {
        cout << e;
    }
    cout << endl;
}
