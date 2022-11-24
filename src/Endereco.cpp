#include "../include/Endereco.h"
#include "../include/UsuarioLogado.h"
#include <math.h>

Endereco::Endereco()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.Endereco"))
    {
        throw "Acesso negado a Endereco.Endereco";
    }
    else
    {
        this->setEndereco("");
        this->setX(0);
        this->setY(0);
    }
}

Endereco::Endereco(string valEndereco, double valX, double valY)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.Endereco"))
    {
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
    this->endereco = valEndereco;
}

void Endereco::setX(double valX)
{
    this->x = valX;
}

void Endereco::setY(double valY)
{
    this->y = valY;
}

string Endereco::getEndereco()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.getEndereco"))
    {
        throw "Acesso negado a Endereco.getEndereco";
    }
    else
    {
        return this->endereco;
    }
}

double Endereco::getX()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.getX"))
    {
        throw "Acesso negado a Endereco.getX";
    }
    else
    {
        return this->x;
    }
}

double Endereco::getY()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.getY"))
    {
        throw "Acesso negado a Endereco.getY";
    }
    else
    {
        return this->y;
    }
}

double Endereco::getDistancia(double x2, double y2)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.getDistancia"))
    {
        throw "Acesso negado a Endereco.getDistancia";
    }
    else
    {
        return 110.57 * sqrt(pow(x2 - this->x, 2) + pow(y2 - this->y, 2));
    }
}