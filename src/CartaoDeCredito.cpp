#include "../include/CartaoDeCredito.h"
#include "../include/MetodoDePagamento.h"
#include "../include/UsuarioLogado.h"

using namespace std;

CartaoDeCredito::CartaoDeCredito() : MetodoDePagamento()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("CartaoDeCredito.CartaoDeCredito"))
  {
    throw "Acesso negado a CartaoDeCredito.CartaoDeCredito";
  }
  else
  {
    this->numeroDoCartao = "";
    this->nomeDoTitular = "";
    this->codigoDeSeguranca = "";
    this->dataDeValidade = Data();
  }
}

CartaoDeCredito::CartaoDeCredito(string numeroDoCartao, string nomeDoTitular,
                  string codigoDeSeguranca, Data dataDeValidade)
    : MetodoDePagamento(0, 0)
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("CartaoDeCredito.CartaoDeCredito"))
  {
    throw "Acesso negado a CartaoDeCredito.CartaoDeCredito";
  }
  else
  {
    this->numeroDoCartao = numeroDoCartao;
    this->nomeDoTitular = nomeDoTitular;
    this->codigoDeSeguranca = codigoDeSeguranca;
    this->dataDeValidade = dataDeValidade;
  }
}

string CartaoDeCredito::getNumeroDoCartao()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("CartaoDeCredito.getNumeroDoCartao"))
  {
    throw "Acesso negado a CartaoDeCredito.getNumeroDoCartao";
  }
  else
  {
    return this->numeroDoCartao;
  }
}

string CartaoDeCredito::getNomeDoTitular()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("CartaoDeCredito.getNomeDoTitular"))
  {
    throw "Acesso negado a CartaoDeCredito.getNomeDoTitular";
  }
  else
  {
    return this->nomeDoTitular;
  }
}

string CartaoDeCredito::getCodigoDeSeguranca()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("CartaoDeCredito.getCodigoDeSeguranca"))
  {
    throw "Acesso negado a CartaoDeCredito.getCodigoDeSeguranca";
  }
  else
  {
    return this->codigoDeSeguranca;
  }
}

Data CartaoDeCredito::getDataDeValidade() 
{ 
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("CartaoDeCredito.getDataDeValidade"))
  {
    throw "Acesso negado a CartaoDeCredito.getDataDeValidade";
  }
  else
  {
    return this->dataDeValidade;
  }
}

void CartaoDeCredito::setNumeroDoCartao(string numeroDoCartao)
{
  this->numeroDoCartao = numeroDoCartao;
}

void CartaoDeCredito::setNomeDoTitular(string nomeDoTitular)
{
  this->nomeDoTitular = nomeDoTitular;
}

void CartaoDeCredito::setCodigoDeSeguranca(string codigoDeSeguranca)
{
  this->codigoDeSeguranca = codigoDeSeguranca;
}

void CartaoDeCredito::setDataDeValidade(Data dataDeValidade)
{
  this->dataDeValidade = dataDeValidade;
}
