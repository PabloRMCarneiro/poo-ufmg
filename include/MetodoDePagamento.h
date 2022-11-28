#ifndef METODODEPAGAMENTO_H_INCLUDED
#define METODODEPAGAMENTO_H_INCLUDED
#include "data.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class MetodoDePagamento {
private:
  int quantidadeDeParcelas;
  float quantiaPorParcelas;
public:
  MetodoDePagamento();
  MetodoDePagamento(int valQuantidadeDeParcelas, float valQuantiaPorParcela);

  int getQuantidadeDeParcelas();
  float getQuantiaPorParcelas();

  void setQuantidadeDeParcelas(int quantidadeDeParcelas);
  void setQuantiaPorParcelas(float quantiaPorParcelas);
};
 

#endif