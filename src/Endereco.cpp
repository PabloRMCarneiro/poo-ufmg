#include "../include/Endereco.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"
#include <math.h>

Endereco::Endereco()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.Endereco"))
    {
        PermissaoNegada *a = new PermissaoNegada("Endereco", "Endereco");
        throw "Acesso negado a Endereco.Endereco";
    }
    else
    {

    }
}

Endereco::Endereco(string valEndereco, double valX, double valY)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.Endereco"))
    {   
        PermissaoNegada *a = new PermissaoNegada("Endereco", "Endereco");
        throw "Acesso negado a Endereco.Endereco";
    }
    else
    {
        this->setEndereco(valEndereco);
        this->setX(valX);
        this->setY(valY);
    }
}

void Endereco::setEndereco(string valEndereco)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.Endereco"))
    {   
        PermissaoNegada *a = new PermissaoNegada("setEndereco", "Endereco");
        throw "Acesso negado a Endereco.Endereco";
    }
    else
    {
        this->endereco = valEndereco;
        LogEscrita *a = new LogEscrita("endereco", "indefinido", valEndereco, "Endereco");
    }
}

void Endereco::setX(double valX)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.Endereco"))
    {   
        PermissaoNegada *a = new PermissaoNegada("setX", "Endereco");
        throw "Acesso negado a Endereco.Endereco";
    }
    else
    {
        this->x = valX;
        LogEscrita *a = new LogEscrita("x", "indefinido", to_string(valX), "Endereco");
    }
}

void Endereco::setY(double valY)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.Endereco"))
    {   
        PermissaoNegada *a = new PermissaoNegada("setY", "Endereco");
        throw "Acesso negado a Endereco.Endereco";
    }
    else
    {
        this->y = valY;
        LogEscrita *a = new LogEscrita("y", "indefinido", to_string(valY), "Endereco");
    }
}

string Endereco::getEndereco()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.getEndereco"))
    {
        PermissaoNegada *a = new PermissaoNegada("getEndereco", "Endereco");
        throw "Acesso negado a Endereco.getEndereco";
    }
    else
    {
        return this->endereco;
        LogLeitura *a = new LogLeitura("endereco", "Endereco");
    }
}

double Endereco::getX()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.getX"))
    {
        PermissaoNegada *a = new PermissaoNegada("getX", "Endereco");
        throw "Acesso negado a Endereco.getX";
    }
    else
    {
        return this->x;
        LogLeitura *a = new LogLeitura("x", "Endereco");
    }
}

double Endereco::getY()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.getY"))
    {
        PermissaoNegada *a = new PermissaoNegada("getY", "Endereco");
        throw "Acesso negado a Endereco.getY";
    }
    else
    {
        return this->y;
        LogLeitura *a = new LogLeitura("y", "Endereco");
    }
}

double Endereco::getDistancia(double x2, double y2)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.getDistancia"))
    {
        PermissaoNegada *a = new PermissaoNegada("getDistancia", "Endereco");
        throw "Acesso negado a Endereco.getDistancia";
    }
    else
    {
        return 110.57 * sqrt(pow(x2 - this->getX(), 2) + pow(y2 - this->getY(), 2));
    }
}