#include "../include/Endereco.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"
#include "../include/PermissaoNegada.h"
#include <math.h>

Endereco::Endereco()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.Endereco"))
    {
        PermissaoNegada *a = new PermissaoNegada("Endereco", "Endereco");
        string mensagem = "Acesso negado a Endereco.Endereco";
    }
    else
    {
        endereco = "";
        x = 0.0;
        y = 0.0;
    }
}

Endereco::Endereco(string valEndereco, double valX, double valY)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.Endereco"))
    {   
        PermissaoNegada *a = new PermissaoNegada("Endereco", "Endereco");
        string mensagem = "Acesso negado a Endereco.Endereco";
        throw mensagem;
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
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.setEndereco"))
    {   
        PermissaoNegada *a = new PermissaoNegada("setEndereco", "Endereco");
        string mensagem = "Acesso negado a Endereco.setEndereco";
        throw mensagem;
    }
    else
    {
        this->endereco = valEndereco;
        LogEscrita *a = new LogEscrita("endereco", "indefinido", valEndereco, "Endereco");
    }
}

void Endereco::setX(double valX)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.setX"))
    {   
        PermissaoNegada *a = new PermissaoNegada("setX", "Endereco");
        string mensagem = "Acesso negado a Endereco.setX";
        throw mensagem;
    }
    else
    {
        this->x = valX;
        LogEscrita *a = new LogEscrita("x", "indefinido", to_string(valX), "Endereco");
    }
}

void Endereco::setY(double valY)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.setY"))
    {   
        PermissaoNegada *a = new PermissaoNegada("setY", "Endereco");
        string mensagem = "Acesso negado a Endereco.setY";
        throw mensagem;
    }
    else
    {
        this->y = valY;
        LogEscrita *a = new LogEscrita("y", "indefinido", to_string(valY), "Endereco");
    }
}

string Endereco::getEndereco()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.getEndereco"))
    {
        PermissaoNegada *a = new PermissaoNegada("getEndereco", "Endereco");
        string mensagem = "Acesso negado a Endereco.getEndereco";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("endereco", "Endereco");
        return this->endereco;
    }
}

double Endereco::getX()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.getX"))
    {
        PermissaoNegada *a = new PermissaoNegada("getX", "Endereco");
        string mensagem = "Acesso negado a Endereco.getX";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("x", "Endereco");
        return this->x;  
    }
}

double Endereco::getY()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.getY"))
    {

        PermissaoNegada *a = new PermissaoNegada("getY", "Endereco");
        string mensagem = "Acesso negado a Endereco.getY";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("y", "Endereco");
        return this->y;
    }
}

double Endereco::getDistancia(double x2, double y2)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Endereco.getDistancia"))
    {
        PermissaoNegada *a = new PermissaoNegada("getDistancia", "Endereco");
        string mensagem = "Acesso negado a Endereco.getDistancia";
        throw mensagem;

    }
    else
    {
        return 110.57 * sqrt(pow(x2 - this->getX(), 2) + pow(y2 - this->getY(), 2));
    }
}