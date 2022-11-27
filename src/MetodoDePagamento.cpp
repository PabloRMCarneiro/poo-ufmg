#include "../include/MetodoDePagamento.h"
#include "../include/UsuarioLogado.h"

MetodoDePagamento::MetodoDePagamento()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.MetodoDePagamento"))
    {
        throw "Acesso negado a MetodoDePagamento.MetodoDePagamento";
    }
    else
    {
        this->quantidadeDeParcelas = 0;
        this->quantiaPorParcelas = 0.0;
    }
}

MetodoDePagamento::MetodoDePagamento(int valQuantidadeDeParcelas, float valQuantiaPorParcela)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.MetodoDePagamento"))
    {
        throw "Acesso negado a MetodoDePagamento.MetodoDePagamento";
    }
    else
    {
        this->quantidadeDeParcelas = valQuantidadeDeParcelas;
        this->quantiaPorParcelas = valQuantiaPorParcela;
    }
}

int MetodoDePagamento::getQuantidadeDeParcelas()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.getQuantidadeDeParcelas"))
    {
        throw "Acesso negado a MetodoDePagamento.getQuantidadeDeParcelas";
    }
    else
    {
        LogLeitura *a = new LogLeitura("quantidadeDeParcelas", "MetodoDePagamento");
        return quantidadeDeParcelas;
    }
}

float MetodoDePagamento::getQuantiaPorParcelas()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.getQuantiaPorParcelas"))
    {
        throw "Acesso negado a MetodoDePagamento.getQuantiaPorParcelas";
    }
    else
    {
        LogLeitura *a = new LogLeitura("quantiaPorParcelas", "MetodoDePagamento");
        return quantiaPorParcelas;
    }
}

void MetodoDePagamento::setQuantidadeDeParcelas(int valQuantidadeDeParcelas)
{
    this->quantidadeDeParcelas = valQuantidadeDeParcelas;
}

void MetodoDePagamento::setQuantiaPorParcelas(float valParcelamento)
{
    this->quantiaPorParcelas = valParcelamento;
}