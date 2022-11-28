#ifndef CARTAODECREDITO_H_INCLUDED
#define CARTAODECREDITO_H_INCLUDED
#include "MetodoDePagamento.h"
#include "data.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CartaoDeCredito : public MetodoDePagamento {
private:
  string numeroDoCartao;
  string nomeDoTitular;
  string codigoDeSeguranca;
  Data dataDeValidade;

public:
  CartaoDeCredito();
  CartaoDeCredito(string numeroDoCartao, string nomeDoTitular,
                  string codigoDeSeguranca, Data dataDeValidade);

  string getNumeroDoCartao();
  string getNomeDoTitular();
  string getCodigoDeSeguranca();
  Data getDataDeValidade();

  void setNumeroDoCartao(string numeroDoCartao);
  void setNomeDoTitular(string nomeDoTitular);
  void setCodigoDeSeguranca(string codigoDeSeguranca);
  void setDataDeValidade(Data dataDeValidade);
};

#endif