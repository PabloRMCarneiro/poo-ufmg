#ifndef METODODEPAGAMENTO_H_INCLUDED
#define METODODEPAGAMENTO_H_INCLUDED
#include "./data.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class MetodoDePagamento {
private:
  string tipoDePagamento;
  int quantidadeDeParcelas;
  float quantiaPorParcelas;
  Data data;
  
public:
  MetodoDePagamento();
  MetodoDePagamento(string valTipoDePagamento, int valQuantidadeDeParcelas, float valQuantiaPorParcela, Data valData);
  virtual ~MetodoDePagamento();

  string getTipoDePagamento();
  int getQuantidadeDeParcelas();
  vector <float> getParcelamento();
  Data getData();

  void setTipoDePagamento(string tipoDePagamento);
  void setQuantidadeDeParcelas(int quantidadeDeParcelas);
  void setParcelamento(vector <float> parcelamento);
  void setData(Data data);
};
 

#endif