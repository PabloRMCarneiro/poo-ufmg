#ifndef PERMISSAO_H_INCLUDED
#define PERMISSAO_H_INCLUDED
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
#endif 