#include "../include/Boleto.h"
#include "../include/PermissaoNegada.h"

using namespace std;

Boleto::Boleto():MetodoDePagamento() 
{
    codigoDeBarras = "";
    dataDeVencimento = Data();
    valor = 0; 
}
Boleto::Boleto(string tipoDePagamento, int quantidadeDeParcelas, Data data, vector<float>parcelamento, string valcodigoDeBarras, Data valDataDeVencimento, float valValor)
:MetodoDePagamento(tipoDePagamento, quantidadeDeParcelas, parcelamento, data)
{
    codigoDeBarras = valcodigoDeBarras;
    dataDeVencimento = valDataDeVencimento;
    valor = valValor; 
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
