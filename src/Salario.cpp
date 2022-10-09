#include "../include/Salario.h"
#include <string>
#include <vector>


using namespace std;
/**
 * A constructor for the class Salario.
 */
Salario::Salario()
{
  this->valor = 0.0;
  this->dissidio = 0.0;
  this->registro.push_back(make_pair(Data(), 0.0));
}
/**
 * The constructor for the Salario class
 * 
 * @param valValor
 */
Salario::Salario(float valValor)
{
  this->valor = valValor;
  this->dissidio = 0.0;
}
/**
 * The destructor for the Salario class
 */
Salario::~Salario()
{
}
/**
 * It returns the value of the salary.
 * 
 * @return The value of the salary.
 */
float Salario::getValor()
{
  return this->valor;
}
/**
 * It returns the value of the dissidio.
 * 
 * @return The value of the dissidio.
 */
vector<pair<Data, float>> Salario::getRegistro()
{
  return this->registro;
}
/**
 * It returns the value of the dissidio.
 * 
 * @return The value of the dissidio.
 */
float Salario::getDissidio()
{
  return this->dissidio;
}
/**
 * This function sets the value of the private variable valor to the value of the parameter valValor
 * 
 * @param valValor
 */
void Salario::setValor(float valValor)
{
  this->valor = valValor;
}
/**
 * This function sets the value of the private variable dissidio to the value of the parameter valDissidio
 * 
 * @param valDissidio
 */
void Salario::setDissidio(float valDissidio)
{
  this->dissidio = valDissidio;
}
/**
 * This function increases the value of the salary by the percentage of the parameter valPercentual
 * 
 * @param valPercentual
 */
void Salario::promocao(float valPercentual)
{
  this->valor = this->valor + (this->valor * valPercentual);
}
/**
 * This function increases the value of the salary by the value of the parameter valDissidio
 * 
 * @param valDissidio
 */
void Salario::reajuste(float valDissidio)
{
  this->valor = this->valor + (this->valor * valDissidio);
}
/**
 * This function sets the value of the private variable registro to the value of the parameter valRegistro
 * 
 * @param valRegistro
 */
void Salario::alteraRegistro(Data valData, float valValor)
{
  for(auto it: registro){
    if(it.first==valData){
      it.second=valValor;
    }
  }
}
