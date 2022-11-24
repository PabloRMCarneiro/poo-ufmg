#include "../include/Boleto.h"
#include "../include/PermissaoNegada.h"
#include "../include/UsuarioLogado.h"

using namespace std;

Boleto::Boleto():MetodoDePagamento() 
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Boleto.Boleto"))
    {
        throw "Acesso negado a Boleto.Boleto";
    }
    else
    {
        this->codigoDeBarras = "";
        this->dataDeVencimento = Data();
        valor = 0;

    }
}

Boleto::Boleto(string tipoDePagamento, int quantidadeDeParcelas, Data data, float quantiaPorParcela, string valcodigoDeBarras, Data valDataDeVencimento, float valValor):MetodoDePagamento(tipoDePagamento, quantidadeDeParcelas, quantiaPorParcela, data){
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Boleto.Boleto"))
    {
        throw "Acesso negado a Boleto.Boleto";
    }
    else
    {
        this->codigoDeBarras = valcodigoDeBarras;
        this->dataDeVencimento = valDataDeVencimento;
        valor = valValor;
    }
}

Boleto::~Boleto()
{

}

string Boleto::getCodigoDeBarras()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Boleto.getCodigoDeBarras"))
    {
        throw "Acesso negado a Boleto.getCodigoDeBarras";
    }
    else
    {
        return this->codigoDeBarras;
    }
    return this->codigoDeBarras;
}

Data Boleto::getDataDeVencimento()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Boleto.getDataDeVencimento"))
    {
        throw "Acesso negado a Boleto.getDataDeVencimento";
    }
    else
    {
        return this->dataDeVencimento;
    }
}

float Boleto::getValor()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Boleto.getValor"))
    {
        throw "Acesso negado a Boleto.getValor";
    }
    else
    {
        return this->valor;
    }
}

void Boleto::setCodigoDeBarras(string valCodigoDeBarras)
{
    codigoDeBarras = valCodigoDeBarras;
}

void Boleto::setDataDeVencimento(Data valDataDeVencimento)
{
    dataDeVencimento = valDataDeVencimento;
}

void Boleto::setValor(float valValor)
{
    valor = valValor;
}
