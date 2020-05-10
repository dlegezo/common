#include "printer.h"

using namespace std;

void print_vector(storage_it start_it, const storage_it end_it) {
    while (start_it != end_it) {
        cout << setw(2) << setfill('0') << hex << static_cast<int>(*start_it) << " ";
        start_it = next(start_it, 1);
    }
    cout << endl;
}

void print_vector_len(storage_it start_it, const int len) {
    for (int i=0; i<len; ++i) {
        cout << setw(2) << setfill('0') << hex << static_cast<int>(start_it[i]) << " ";
    }
    cout << endl;
}
