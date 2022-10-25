#ifndef BOLETO_H_INCLUDED
#define BOLETO_H_INCLUDED
#include "MetodoDePagamento.h"
#include "data.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Boleto : public MetodoDePagamento {
private:
  string codigoDeBarras;
  Data dataDeVencimento;
  float valor;

public:
  Boleto();
  Boleto(string codigoDeBarras, Data dataDeVencimento, float valor);
  virtual ~Boleto();

  string getCodigoDeBarras();
  Data getDataDeVencimento();
  float getValor();

  void setCodigoDeBarras(string codigoDeBarras);
  void setDataDeVencimento(Data dataDeVencimento);
  void setValor(float valor);
};

#endif
