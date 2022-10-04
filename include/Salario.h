#ifndef SALARIO_H_INCLUDED
#define SALARIO_H_INCLUDED
#include "data.h"
#include <string>
#include <vector>
using namespace std;

class Salario {
    private:
      float valor;
      vector<pair<Data, float>> registro;
    protected:
      float dissidio;
  public:
      Salario();
      Salario(float valValor);
      virtual ~Salario();
      float getValor();
      vector<pair<Data, float>> getRegistro();
      float getDissidio();
      void setValor(float valValor);
      void setDissidio(float valDissidio);
      void promocao(float valPercentual);
      void reajuste(float valDissidio);
      void alteraRegistro(Data valData, float valValor);
}; 

#endif