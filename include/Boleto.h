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
  Data dataDeVencimento;
public:
  Boleto();
  Boleto(int quantidadeDeParcelas, Data valDataDeVencimento, double valValor);

  Data getDataDeVencimento();
  void setDataDeVencimento(Data valDataDeVencimento);
};

#endif