#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <string>
#include <vector>
#include "../include/Permissao.h"
using namespace std;

class Usuario{
    private:
        string email;
        string senha;
        vector <Permissao*> permissoes;
    public:
        Usuario();
        Usuario(string email, string senha);
        ~Usuario();
        string getEmail();
        string getSenha();
        bool getPermissoes(string valFuncoes);

        void setEmail(string email);
        void setSenha(string senha);
        void setPermissoes(vector <Permissao*> permissoes);
};

#endif 