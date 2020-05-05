#include "logger.h"

using namespace std;

logger::logger(const std::string& init_msg) : msg{init_msg} {}

logger::~logger() {}

void logger::add_msg(const string &new_msg) {
    msg.push_back(new_msg);
}

void logger::print_log() {
    for (auto e : msg) {
        cout << e << endl;
    }
}
