#ifndef PERMISSAO_H_INCLUDED
#define PERMISSAO_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;
class Permissao{
    private:
        string metodo;
    public:
        Permissao();
        Permissao(string valMetodo);
        void setMetodo(string valMetodo);
        string getMetodo();
};
#endif //PERMISSAO_H_INCLUDED