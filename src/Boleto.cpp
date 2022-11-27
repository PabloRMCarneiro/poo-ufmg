#include "../include/Boleto.h"
#include "../include/PermissaoNegada.h"
#include "../include/UsuarioLogado.h"

using namespace std;

Boleto::Boleto():MetodoDePagamento() 
{
    if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Boleto.Boleto"))
    {
        throw "Acesso negado a Boleto.Boleto";
    }
    else
    {
        this->dataDeVencimento = Data();
    }
}

Boleto::Boleto(int quantidadeDeParcelas, Data valDataDeVencimento, double valValor):MetodoDePagamento(quantidadeDeParcelas, valValor){
    if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Boleto.Boleto"))
    {
        throw "Acesso negado a Boleto.Boleto";
    }
    else
    {
        this->dataDeVencimento = valDataDeVencimento;
    }
}

// Boleto::~Boleto()
// {

// }
Data Boleto::getDataDeVencimento()
{
    if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Boleto.getDataDeVencimento"))
    {
        throw "Acesso negado a Boleto.getDataDeVencimento";
    }
    else
    {
        return this->dataDeVencimento;
    }
}

void Boleto::setDataDeVencimento(Data valDataDeVencimento)
{
    dataDeVencimento = valDataDeVencimento;
}