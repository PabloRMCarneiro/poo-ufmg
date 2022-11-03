#include "./include/CartaoDeCredito.h"
#include "./MetodoDePagamento.h"

using namespace std;

CartaoDeCredito::CartaoDeCredito() : MetodoDePagamento() {
  this->numeroDoCartao = "";
  this->nomeDoTitular = "";
  this->codigoDeSeguranca = "";
  this->dataDeValidade = Data();
}

CartaoDeCredito::CartaoDeCredito(string numeroDoCartao, string nomeDoTitular,
                                 string codigoDeSeguranca, Data dataDeValidade)
    : MetodoDePagamento() {
  this->numeroDoCartao = numeroDoCartao;
  this->nomeDoTitular = nomeDoTitular;
  this->codigoDeSeguranca = codigoDeSeguranca;
  this->dataDeValidade = dataDeValidade;
}

CartaoDeCredito::~CartaoDeCredito() {}

string CartaoDeCredito::getNumeroDoCartao() { return this->numeroDoCartao; }

string CartaoDeCredito::getNomeDoTitular() { return this->nomeDoTitular; }

string CartaoDeCredito::getCodigoDeSeguranca() {
  return this->codigoDeSeguranca;
}

Data CartaoDeCredito::getDataDeValidade() { return this->dataDeValidade; }

void CartaoDeCredito::setNumeroDoCartao(string numeroDoCartao) {
  this->numeroDoCartao = numeroDoCartao;
}

void CartaoDeCredito::setNomeDoTitular(string nomeDoTitular) {
  this->nomeDoTitular = nomeDoTitular;
}

void CartaoDeCredito::setCodigoDeSeguranca(string codigoDeSeguranca) {
  this->codigoDeSeguranca = codigoDeSeguranca;
}

void CartaoDeCredito::setDataDeValidade(Data dataDeValidade) {
  this->dataDeValidade = dataDeValidade;
}
