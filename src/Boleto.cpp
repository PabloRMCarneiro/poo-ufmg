#include "../include/Boleto.h"
#include "../include/Empresa.h"
#include "../include/PermissaoNegada.h"
#include <string>

using namespace std;

Boleto::Boleto():MetodoDePagamento() 
{
  if(!Empresa::getEmpresa()->getAcesso("Boleto.Boleto"))
  {
    throw acessoNegadoBoleto();
  }
  else
    {
       codigoDeBarras = "";
       dataDeVencimento = Data();
       valor = 0; 
    }
}
Boleto::Boleto(string tipoDePagamento, int quantidadeDeParcelas, Data data, string valcodigoDeBarras, Data valDataDeVencimento, float valValor)
:MetodoDePagamento(tipoDePagamento, quantidadeDeParcelas, data)
{
    if(!Empresa::getEmpresa()->getAcesso("Boleto.Boleto"))
    {
        throw acessoNegadoBoleto();
    }
    else
    {
        codigoDeBarras = valcodigoDeBarras;
        dataDeVencimento = valDataDeVencimento;
        valor = valValor; 
    }
}
Boleto::~Boleto()
{

}
string Boleto::getCodigoDeBarras()
{
   
    return this->codigoDeBarras;
}
Data Boleto::getDataDeVencimento()
{
    return this->dataDeVencimento;
}
float Boleto::getValor()
{
    return this->valor;
}
void Boleto::setCodigoDeBarras(string valCodigoDeBarras)
{
    if(!Empresa::getEmpresa()->getAcesso("Boleto.setCodigoDeBarras"))
    {
        throw "Acesso negado a Boleto.setCodigoDeBarras";
    }
    else
    {
        codigoDeBarras = valCodigoDeBarras;
    }
}
void Boleto::setDataDeVencimento(Data valDataDeVencimento)
{
    if(!Empresa::getEmpresa()->getAcesso("Boleto.setDataDeVencimento"))
    {
        throw "Acesso negado a Boleto.setDataDeVencimento";
    }
    else
    {
        dataDeVencimento = valDataDeVencimento;
    }
}
void Boleto::setValor(float valValor)
{
    if(!Empresa::getEmpresa()->getAcesso("Boleto.setValor"))
    {
        throw "Acesso negado a Boleto.setValor";
    }
    else
    {
        valor = valValor;
    }
}
