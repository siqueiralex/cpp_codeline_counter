// Copyright Alex Siqueira
#include "../include/codeline_counter.hpp"

bool only_spaces(std::string s) {
    return s.find_first_not_of(' ') == s.npos;
}

void elim_spaces(std::string *s) {
    using namespace std;
    int begin = (*s).find_first_not_of(' ');
    int end = (*s).find_last_not_of(' ');
    if (begin != -1  && end != -1){
        int size = end-begin+1;
        *s = (*s).substr(begin, size);
    } else {
        string empty("");
        (*s) = empty;
    }
}