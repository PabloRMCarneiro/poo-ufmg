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
    LogEscrita *a = new LogEscrita("email", "indefinido", email, "Usuario");
    LogEscrita *b = new LogEscrita("jornada", senha, senha, "Usuario");
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

void Usuario::setEmail(string valEmail)
{
    LogEscrita *a = new LogEscrita("email", email, valEmail, "Usuario");
    this->email = valEmail;
}

void Usuario::setSenha(string valSenha)
{
    LogEscrita *a = new LogEscrita("email", senha, valSenha, "Usuario");
    this->senha = valSenha;
}

void Usuario::setPermissoes(vector<string> permissoes)
{
    this->permissoes = permissoes;
}