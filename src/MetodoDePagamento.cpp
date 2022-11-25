#include "../include/MetodoDePagamento.h"
#include "../include/UsuarioLogado.h"

MetodoDePagamento::MetodoDePagamento()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.MetodoDePagamento"))
    {
        throw "Acesso negado a MetodoDePagamento.MetodoDePagamento";
    }
    else
    {
        this->tipoDePagamento = "";
        this->quantidadeDeParcelas = 0;
        this->quantiaPorParcelas = 0.0;
        this->data = Data();
    }
}

MetodoDePagamento::MetodoDePagamento(string valTipoDePagamento, int valQuantidadeDeParcelas, float valQuantiaPorParcela, Data valData)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.MetodoDePagamento"))
    {
        throw "Acesso negado a MetodoDePagamento.MetodoDePagamento";
    }
    else
    {
        this->tipoDePagamento = valTipoDePagamento;
        this->quantidadeDeParcelas = valQuantidadeDeParcelas;
        this->quantiaPorParcelas = valQuantiaPorParcela;
        this->data = valData;
    }
}

string MetodoDePagamento::getTipoDePagamento()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.getTipoDePagamento"))
    {
        throw "Acesso negado a MetodoDePagamento.getTipoDePagamento";
    }
    else
    {
        return tipoDePagamento;
    }
}

int MetodoDePagamento::getQuantidadeDeParcelas()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.getQuantidadeDeParcelas"))
    {
        throw "Acesso negado a MetodoDePagamento.getQuantidadeDeParcelas";
    }
    else
    {
        return quantidadeDeParcelas;
    }
}

float MetodoDePagamento::getQuantiaPorParcelas()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.getQuantiaPorParcelas"))
    {
        throw "Acesso negado a MetodoDePagamento.getQuantiaPorParcelas";
    }
    else
    {
        return quantiaPorParcelas;
    }
}

Data MetodoDePagamento::getData()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MetodoDePagamento.getData"))
    {
        throw "Acesso negado a MetodoDePagamento.getData";
    }
    else
    {
        return data;
    }
}

void MetodoDePagamento::setTipoDePagamento(string valTipoDePagamento)
{
    this->tipoDePagamento = valTipoDePagamento;
}

void MetodoDePagamento::setQuantidadeDeParcelas(int valQuantidadeDeParcelas)
{
    this->quantidadeDeParcelas = valQuantidadeDeParcelas;
}

void MetodoDePagamento::setQuantiaPorParcelas(float valParcelamento)
{
    this->quantiaPorParcelas = valParcelamento;
}

void MetodoDePagamento::setData(Data valData)
{
    this->data = valData;
}
MetodoDePagamento::~MetodoDePagamento(){
    
}