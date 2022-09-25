#include "../include/Salario.h"
#include <string>
#include <vector>


using namespace std;

Salario::Salario()
{
  this->valor = 0.0;
  this->dissidio = 0.0;
  this->registro.push_back(make_pair(Data(), 0.0));
}

Salario::Salario(float valValor)
{
  this->valor = valValor;
  this->dissidio = 0.0;
}

Salario::~Salario()
{
}

//Metodos get:

float Salario::getValor()
{
  return this->valor;
}

vector<pair<Data, float>> Salario::getRegistro()
{
  return this->registro;
}

float Salario::getDissidio()
{
  return this->dissidio;
}

//Metodos set:

void Salario::setValor(float valValor)
{
  this->valor = valValor;
}

void Salario::setDissidio(float valDissidio)
{
  this->dissidio = valDissidio;
}

//Metodos:

void Salario::promocao(float valPercentual)
{
  this->valor = this->valor + (this->valor * valPercentual);
}

void Salario::reajuste(float valDissidio)
{
  this->valor = this->valor + valDissidio;
}

void Salario::alteraRegistro(Data valData, float valValor)
{
  for(auto it: registro){
    if(it.first==valData){
      it.second=valValor;
    }
  }
}
