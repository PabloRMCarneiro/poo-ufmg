#ifndef SALARIO_H_INCLUDED
#define SALARIO_H_INCLUDED
#include "../ClasseData/data.h"
#include <string>
#include <vector>
using namespace std;

class Salario 
{
  private:
    float valor;
    vector<pair<Data, float>> registro;
  
  protected:
    float dissidio;
  
  public:
    Salario();
    Salario(float valValor);
    virtual ~Salario();

    //Metodos get:
    float getValor();
    vector<pair<Data, float>> getRegistro();
    float getDissidio();

    //Metodos set:
    void setValor(float valValor);
    void setDissidio(float valDissidio);

    //Metodos:

    void promocao(float valPercentual);
    void reajuste(float valDissidio);
    void alteraRegistro(Data valData, float valValor);

}; 

#endif