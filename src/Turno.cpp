#include "../include/Turno.h"
#include "../include/UsuarioLogado.h"
#include "../include/PermissaoNegada.h"

#include <string>

Turno::Turno(string valPeriodo, Data valEntradaHora, Data valSaidaHora, double valJornada)
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.Turno"))
    {
        PermissaoNegada *a = new PermissaoNegada("Turno", "Turno");
        string mensagem = "Acesso negado a Turno.Turno";
        throw mensagem;
    }
    else
    {
        this->setEntradaHora(valEntradaHora);
        this->setJornada(valJornada);
        this->setPeriodo(valPeriodo);
        this->setSaidaHora(valSaidaHora);
    }
}

Turno::Turno()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.Turno"))
    {
        PermissaoNegada *a = new PermissaoNegada("Turno", "Turno");
        string mensagem = "Acesso negado a Turno.Turno";
        throw mensagem;
    }
    else
    {
        this->setEntradaHora(Data());
        this->setJornada(0.0);
        this->setPeriodo("");
        this->setSaidaHora(Data());
    }
}

void Turno::setEntradaHora(Data valEntradaHora)
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.setEntradaHora"))
    {
        PermissaoNegada *a = new PermissaoNegada("setEntradaHora", "Turno");
        string mensagem = "Acesso negado a Turno.setEntradaHora";
        throw mensagem;
    }
    else
    {
        this->entradaHora = valEntradaHora;
    }
}

void Turno::setSaidaHora(Data valSaidaHora)
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.setSaidaHora"))
    {
        PermissaoNegada *a = new PermissaoNegada("setSaidaHora", "Turno");
        string mensagem = "Acesso negado a Turno.setSaidaHora";
        throw mensagem;
    }
    else
    {
        this->saidaHora = valSaidaHora;
    }
}

void Turno::setPeriodo(string valPeriodo)
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.setPeriodo"))
    {
        PermissaoNegada *a = new PermissaoNegada("setPeriodo", "Turno");
        string mensagem = "Acesso negado a Turno.setPeriodo";
        throw mensagem;
    }
    else
    {
        this->periodo = valPeriodo;
    }
}

void Turno::setJornada(double valJornada)
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.setJornada"))
    {
        PermissaoNegada *a = new PermissaoNegada("setJornada", "Turno");
        string mensagem = "Acesso negado a Turno.setJornada";
        throw mensagem;
    }
    else
    {
        this->jornada = valJornada;
    }
}

string Turno::getPeriodo()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.getPeriodo"))
    {
        PermissaoNegada *a = new PermissaoNegada("getPeriodo", "Turno");
        string mensagem = "Acesso negado a Turno.getPeriodo";
        throw mensagem;
    }
    else
    
    {
        return this->periodo;
    }
}

Data Turno::getEntradaHora()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.getEntradaHora"))
    {
        PermissaoNegada *a = new PermissaoNegada("getEntradaHora", "Turno");
        string mensagem = "Acesso negado a Turno.getEntradaHora";
        throw mensagem;
    }
    else
    {
        return this->entradaHora;
    }
}

Data Turno::getSaidaHora()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.getSaidaHora"))
    {
        PermissaoNegada *a = new PermissaoNegada("getSaidaHora", "Turno");
        string mensagem = "Acesso negado a Turno.getSaidaHora";
        throw mensagem;
    }
    else
    {
        return this->saidaHora;
    }
}

double Turno::getJornada()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.getJornada"))
    {
        PermissaoNegada *a = new PermissaoNegada("getJornada", "Turno");
        string mensagem = "Acesso negado a Turno.getJornada";
        throw mensagem;
    }
    else
    {
        return this->jornada;
    }
}