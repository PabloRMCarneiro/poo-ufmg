#include "../include/Usuario.h"
#include "../include/Empresa.h"

Usuario::Usuario()
{
    email = "";
    senha = "";
}

Usuario::Usuario(string valEmail, string valSenha)
{
    this->email = valEmail;
    this->senha = valSenha;
}

Usuario::~Usuario()
{
}

string Usuario::getEmail()
{
    LogLeitura *logLeitura = new LogLeitura("email", "Usuario");
    return email;
}

string Usuario::getSenha()
{
    LogLeitura *logLeitura = new LogLeitura("senha", "Usuario");
    return senha;
}

bool Usuario::getPermissoes(string valFuncoes)
{
    for (auto it : this->getPermissaoLista())
    {
        if (it == valFuncoes) return true;
    }
    return false;
}
vector <string>  Usuario::getPermissaoLista(){
    return this->permissoes;
}
void Usuario::setEmail(string valEmail)
{
    this->email = valEmail;
}

void Usuario::setSenha(string valSenha)
{
    this->senha = valSenha;
}

void Usuario::setPermissoes(vector<string> permissoes)
{
    this->permissoes = permissoes;
}