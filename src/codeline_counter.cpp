// Copyright Alex Siqueira
#include "../include/codeline_counter.hpp"


/*
* Função que verifica se a string contém apenas espaços
* (descrição mais completa no arquivo de headers 'codeline_counter.hpp')
*/
bool only_spaces(std::string s) {
    return s.find_first_not_of(' ') == s.npos;
}


/*
* Função que elimina os espaços no início e final da string
* (descrição mais completa no arquivo de headers 'codeline_counter.hpp')
*/
void elim_spaces(std::string *s) {
    int begin = (*s).find_first_not_of(' ');
    int end = (*s).find_last_not_of(' ');
    if (begin != -1  && end != -1) {
        int size = end-begin+1;
        *s = (*s).substr(begin, size);
    } else {
        std::string empty("");
        (*s) = empty;
    }
}


/*
* Função que verifica se a string não-vazia contém apenas comentários 
* (descrição mais completa no arquivo de headers 'codeline_counter.hpp')
*/
bool only_comments(std::string s) {
    std::string end_comm("*/");
    if (s.find("/") != s.npos &&
        s[0] == '/' && (s[1] == '/' || s[1] == '*')) {
        if (s.find(end_comm) != s.npos && s.find(end_comm) < (s.size()-2)) {
            return false;
        }
        return true;
    }
    return false;
}


/*
* Função que verifica se a string contém delimitador de final de comentário
* (descrição mais completa no arquivo de headers 'codeline_counter.hpp')
*/
bool ends_comment(std::string s) {
    return (s.find("/") != s.npos &&
        (s[s.find("/")+1] == '/' || s[s.find_last_of("/")-1] == '*'));
}


/*
* Função que verifica se a string contém delimitador de início de comentário
* (descrição mais completa no arquivo de headers 'codeline_counter.hpp')
*/
bool initiates_comment(std::string s) {
    return (s.find("/") != s.npos &&
        (s[s.find("/")+1] == '/' || s[s.find("/")+1] == '*'));
}


/*
* Função que verifica se a string indica que a próxima linha é de comentário
* (descrição mais completa no arquivo de header 'codeline_counter.hpp')
*/
bool next_line_is_comment(std::string s) {
    std::string double_slash("//");
    return (initiates_comment(s) && !ends_comment(s)) ||
        (s.find(double_slash) != s.npos &&
            s.find_last_of('\\') == (s.size()-1));
}


/*
* Função que verifica conta a quantidade de linhas de código em uma string
* que representa um código corretamente desenvolvido em C++.
* (descrição mais completa no arquivo de header 'codeline_counter.hpp')
*/
int count_code_lines(std::string s) {
    int count = 0;
    bool inside_comment = false;
    std::istringstream f(s.c_str());
    std::string line;
    while (getline(f, line)) {
        if (!only_spaces(line)) {
            elim_spaces(&line);
            if (!inside_comment) {
                if (initiates_comment(line)) {
                    if (ends_comment(line)) {
                        if (next_line_is_comment(line))
                            count--;
                    } else {
                        inside_comment = true;
                    }
                    if (!only_comments(line)) count++;
                } else {
                    count++;
                }
            } else if (ends_comment(line)) {
                inside_comment = false;
                if (!only_comments(line)) count++;
            }
        }
    }
    if (count < 0) return 0;
    return count;
}
