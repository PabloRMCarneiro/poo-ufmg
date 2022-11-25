#ifndef PERMISSAO_NEGADA_H
#define PERMISSAO_NEGADA_H
#include <iostream>
#include <string>
#include "Log.h"

using namespace std;

class PermissaoNegada : public Log {
    private:
        string metodo;
        
    public:
        PermissaoNegada();
        PermissaoNegada(string valMetodo, string entidade);
        void setMetodo(string valMetodo);
        string getMetodo();
      
        
};
#endif PERMISSAO_NEGADA_H