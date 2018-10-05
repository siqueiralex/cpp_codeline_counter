// Copyright Alex Siqueira Lacerda
#include <sstream>
#include <iostream>
#include <string>

/*  Função: Contém apenas espaços
*   Descrição: 
*       Verifica se a string contém apenas espaços
*   Parâmetros:
*       s   - tipo std::string a ser anaisado pela função
*   Valor Retornado:
*       bool - true se a string 's' contém apenas espaços, false caso contrário 
*/
bool only_spaces(std::string);



/*  Função: Eliminar espaços
*   Descrição: 
*       Elimina os espaços do início e do final da string passada
*   Parâmetros:
*       *s   - tipo ponteiro para std::string que será alterada 
*   Valor Retornado:
*       função não possui retorno 
*/
void elim_spaces(std::string *);



/*  Função: Contém apenas comentários
*   Descrição: 
*       Verifica se a string passada contém apenas comentários, ou seja, nenhum código.
*       -Assume que a string não possui espaços no início nem no final.
*       -Assume que a string não está no meio de um comentário, ou seja, não possui seus delimitadores.
*   Parâmetros:
*       s   - tipo std::string a ser anaisado pela função
*   Valor Retornado:
*       bool - true se a string 's' contém apenas comentários, false caso contrário 
*/
bool only_comments(std::string);



/*  Função: Termina um comentário
*   Descrição: 
*       Verifica se a string passada contém um delimitador de final de comentário, ou se é comentário do tipo '//'.
*       -Assume que a string não possui espaços no início nem no final.
*       -Assume que a string não está no meio de um comentário, ou seja, é comentário mas não possui delimitadores.
*   Parâmetros:
*       s   - tipo std::string a ser anaisado pela função
*   Valor Retornado:
*       bool - true se a string 's' contém término de comentário, false caso contrário 
*/
bool ends_comment(std::string);



/*  Função: Inicia um comentário
*   Descrição: 
*       Verifica se a string passada contém um delimitador de início de comentário.
*       -Assume que a string não possui espaços no início nem no final.
*       -Assume que a string não está no meio de um comentário, ou seja, é comentário mas não possui delimitadores.
*   Parâmetros:
*       s   - tipo std::string a ser anaisado pela função
*   Valor Retornado:
*       bool - true se a string 's' contém início de comentário, false caso contrário 
*/
bool initiates_comment(std::string);



/*  Função: Próxima linha é comentário
*   Descrição: 
*       Verifica se a string passada indica que a próxima linha é comentário. Basicamente para verificar o caso do comenteario
*       do tipo '//' que possui um '\' ao final.
*       -Assume que a string não possui espaços no início nem no final.
*       -Assume que a string não está no meio de um comentário, ou seja, é comentário mas não possui delimitadores.
*   Parâmetros:
*       s   - tipo std::string a ser anaisado pela função
*   Valor Retornado:
*       bool - true se a string 's' contém início de comentário, false caso contrário 
*/
bool next_line_is_comment(std::string);



/*  Função: Conta linhas de código
*   Descrição: 
*       Conta quantas linhas de código existem na string passada. Não conta comentários nem linhas em branco.
*       -Assume que a string passada é um código em C++ escrito corretamente (compila)
*   Parâmetros:
*       s   - tipo std::string a ser anaisado pela função
*   Valor Retornado:
*       count - inteiro que indica a quantidade de linhas de código na string 
*/
int count_code_lines(std::string);
