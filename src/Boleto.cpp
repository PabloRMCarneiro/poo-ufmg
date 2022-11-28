#include "../include/Boleto.h"
#include "../include/PermissaoNegada.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"
#include "../include/LogLeitura.h"

using namespace std;

Boleto::Boleto():MetodoDePagamento() 
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Boleto.Boleto"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("Boleto", "Boleto");
        string mensagem = "Acesso negado a Boleto.Boleto";
        throw mensagem;
    }
    else
    {
        this->dataDeVencimento = Data();
    }
}

Boleto::Boleto(int quantidadeDeParcelas, Data valDataDeVencimento, double valValor):MetodoDePagamento(quantidadeDeParcelas, valValor){
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Boleto.Boleto"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("Boleto", "Boleto");
        string mensagem = "Acesso negado a Boleto.Boleto";
        throw mensagem;
    }
    else
    {
        this->dataDeVencimento = valDataDeVencimento;
        LogEscrita *a = new LogEscrita("dataDeVencimento", "indefinido", valDataDeVencimento.getData(), "Boleto");
    }
}

Data Boleto::getDataDeVencimento()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Boleto.getDataDeVencimento"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("getDataDeVencimento", "Boleto");
        string mensagem = "Acesso negado a Boleto.getDataDeVencimento";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("dataDeVencimento", "Boleto");
        return this->dataDeVencimento;
    }
}

void Boleto::setDataDeVencimento(Data valDataDeVencimento)
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Boleto.setDataDeVencimento"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("setDataDeVencimento", "Boleto");
        string mensagem = "Acesso negado a Boleto.setDataDeVencimento";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("dataDeVencimento", this->dataDeVencimento.getData(), valDataDeVencimento.getData(), "Boleto");
        this->dataDeVencimento = valDataDeVencimento;
    }
}