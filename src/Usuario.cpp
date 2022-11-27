#include "../include/Usuario.h"
#include "../include/Empresa.h"

Usuario::Usuario()
{
    email = "";
    senha = "";
}

Usuario::Usuario(string email, string senha)
{
    this->email = email;
    this->senha = senha;
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
    for (auto it : this->permissoes)
    {
        if (it == valFuncoes) return true;
    }
    return false;
}

void Usuario::setEmail(string email)
{
    this->email = email;
}

void Usuario::setSenha(string senha)
{
    this->senha = senha;
}

void Usuario::setPermissoes(vector<string> permissoes)
{
    this->permissoes = permissoes;
}