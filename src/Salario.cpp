//#include "../include/Salario.h"
#include <string>
#include <vector>
#include "../include/Empresa.h"

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
void Salario::setDissidio(Data valData, float valDissidio)
{
  this->dissidio = valDissidio;
  for(auto it : Empresa::getEmpresa()->getFuncionario()){
    it->getSalario().reajuste(valData, dissidio);
  }
}
/**
 * This function increases the value of the salary by the percentage of the parameter valPercentual
 * 
 * @param valPercentual
 */
void Salario::promocao(Data valData, float valPercentual)
{
  this->valor = this->valor + (this->valor * valPercentual);
  this->atualizaRegistro(valData);

}
/**
 * This function increases the value of the salary by the value of the parameter valDissidio
 * 
 * @param valDissidio
 */
void Salario::reajuste(Data valData, float valDissidio)
{
  this->valor = this->valor + (this->valor * valDissidio);
  this->atualizaRegistro(valData);
}
/**
 * This function sets the value of the private variable registro to the value of the parameter valRegistro
 * 
 * @param valRegistro
 */
void Salario::atualizaRegistro(Data valData)
{
  this->registro.push_back(make_pair(valData, this->valor));
}
