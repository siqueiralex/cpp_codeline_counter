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

bool only_comments(std::string s) {
    std::string end_comm("*/");
    if (s.find("/") != s.npos &&
        s[0] == '/' && (s[1]=='/' || s[1]=='*')) {
        if ( s.find(end_comm) != s.npos && s.find(end_comm) < (s.size()-2)) {
            return false;
        }
        return true;
    }
    return false;
}

bool ends_comment(std::string s) {
    return (s.find("/") != s.npos &&
        (s[s.find("/")+1] == '/' || s[s.find_last_of("/")-1] == '*'));
}

bool initiates_comment(std::string s) {
    return (s.find("/") != s.npos &&
        (s[s.find("/")+1] == '/' || s[s.find("/")+1] == '*'));
}

bool next_line_is_comment(std::string s) {
    std::string double_slash("//");
    return (initiates_comment(s) && !ends_comment(s)) || 
        (s.find(double_slash) != s.npos &&  s.find_last_of('\\') == (s.size()-1));
}