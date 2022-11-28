#ifndef PERMISSAONEGADA_H_INCLUDED
#define PERMISSAONEGADA_H_INCLUDED
#include <iostream>
#include "Log.h"
#include <string>

using namespace std;
class PermissaoNegada : public Log{
    private:
        string metodo;
    public:
        PermissaoNegada();
        PermissaoNegada(string valMetodo, string valEntidade);
        void setMetodo(string valMetodo);
        string getMetodo();
        void imprime();
};
#endif 