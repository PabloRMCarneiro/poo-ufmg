#include "../include/Turno.h"
#include "../include/UsuarioLogado.h"
Turno::Turno(string valPeriodo, Data valEntradaHora, Data valSaidaHora, double valJornada)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.Turno"))
    {
        throw "Acesso negado a Turno.Turno";
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
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.Turno"))
    {
        throw "Acesso negado a Turno.Turno";
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
    this->entradaHora = valEntradaHora;
}

void Turno::setSaidaHora(Data valSaidaHora)
{
    this->saidaHora = valSaidaHora;
}

void Turno::setPeriodo(string valPeriodo)
{
    this->periodo = valPeriodo;
}

void Turno::setJornada(double valJornada)
{
    this->jornada = valJornada;
}

string Turno::getPeriodo()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.getPeriodo"))
    {
        throw "Acesso negado a Turno.getPeriodo";
    }
    else
    {
        return this->periodo;
    }
}

Data Turno::getEntradaHora()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.getEntradaHora"))
    {
        throw "Acesso negado a Turno.getEntradaHora";
    }
    else
    {
        return this->entradaHora;
    }
}

Data Turno::getSaidaHora()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.getSaidaHora"))
    {
        throw "Acesso negado a Turno.getSaidaHora";
    }
    else
    {
        return this->saidaHora;
    }
}

double Turno::getJornada()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Turno.getJornada"))
    {
        throw "Acesso negado a Turno.getJornada";
    }
    else
    {
        return this->jornada;
    }
}