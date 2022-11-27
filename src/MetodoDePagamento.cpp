#include "../include/MetodoDePagamento.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"

MetodoDePagamento::MetodoDePagamento()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.MetodoDePagamento"))
    {
        PermissaoNegada *a = new PermissaoNegada("MetodoDePagamento", "MetodoDePagamento");
        string mensagem = "Acesso negado a MetodoDePagamento.MetodoDePagamento";
        throw mensagem;
    }
    else
    {
        this->quantidadeDeParcelas = 0;
        this->quantiaPorParcelas = 0.0;
    }
}

MetodoDePagamento::MetodoDePagamento(int valQuantidadeDeParcelas, float valQuantiaPorParcela)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.MetodoDePagamento"))
    {
        PermissaoNegada *a = new PermissaoNegada("MetodoDePagamento", "MetodoDePagamento");
        string mensagem = "Acesso negado a MetodoDePagamento.MetodoDePagamento";    
        throw mensagem;
    }
    else
    {
        this->setQuantidadeDeParcelas(valQuantidadeDeParcelas);
        this->setQuantiaPorParcelas(valQuantiaPorParcela);
    }
}

int MetodoDePagamento::getQuantidadeDeParcelas()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.getQuantidadeDeParcelas"))
    {
        PermissaoNegada *a = new PermissaoNegada("getQuantidadeDeParcelas", "MetodoDePagamento");
        string mensagem = "Acesso negado a MetodoDePagamento.getQuantidadeDeParcelas";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("quantidadeDeParcelas", "MetodoDePagamento");
        return quantidadeDeParcelas;
    }
}

float MetodoDePagamento::getQuantiaPorParcelas()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.getQuantiaPorParcelas"))
    {
        PermissaoNegada *a = new PermissaoNegada("getQuantiaPorParcelas", "MetodoDePagamento");
        string mensagem = "Acesso negado a MetodoDePagamento.getQuantiaPorParcelas";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("quantiaPorParcelas", "MetodoDePagamento");
        return quantiaPorParcelas;
    }
}

void MetodoDePagamento::setQuantidadeDeParcelas(int valQuantidadeDeParcelas)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.setQuantidadeDeParcelas"))
    {
        PermissaoNegada *a = new PermissaoNegada("setQuantidadeDeParcelas", "MetodoDePagamento");
        string mensagem = "Acesso negado a MetodoDePagamento.setQuantidadeDeParcelas";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("quantidadeDeParcelas", "indefinido", to_string(valQuantidadeDeParcelas), "MetodoDePagamento");
        this->quantidadeDeParcelas = valQuantidadeDeParcelas;
    }
}

void MetodoDePagamento::setQuantiaPorParcelas(float valParcelamento)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.setQuantiaPorParcelas"))
    {
        PermissaoNegada *a = new PermissaoNegada("setQuantiaPorParcelas", "MetodoDePagamento");
        string mensagem = "Acesso negado a MetodoDePagamento.setQuantiaPorParcelas";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("quantiaPorParcelas", "indefinido", to_string(valParcelamento), "MetodoDePagamento");
        this->quantiaPorParcelas = valParcelamento;
    }
}