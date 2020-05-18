Common custom decryption C++ libraries

Usage sample:

#include "./malware/microcin/microcin.h"

using namespace std;

int main() {
    try {
        parse_microcin_config("<microcin config path here>");
        parse_microcin_stegano("<microcin .bmp file here>");
        return 0;
    } catch (runtime_error e) {
        cout << e.what();
        return 1;
    }
}
