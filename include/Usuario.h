#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include <string>
#include <vector>
using namespace std;

class Usuario{
    private:
        string email;
        string senha;
        vector <string> permissoes;
    public:
        Usuario();
        Usuario(string email, string senha);
        ~Usuario();
        string getEmail();
        string getSenha();
        bool getPermissoes(string valFuncoes);
        vector <string> getPermissaoLista();

        void setEmail(string email);
        void setSenha(string senha);
        void setPermissoes(vector <string> permissoes);
};

#endif 