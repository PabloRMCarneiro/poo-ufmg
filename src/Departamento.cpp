#include "../include/Departamento.h"
#include "../include/Empresa.h"
#include <string>

using namespace std;

/**
 * A constructor for the class Departamento.
 */
Departamento::Departamento()
{
  if(!Empresa::getEmpresa()->getAcesso("Departamento.Departamento"))
  {
    throw "Acesso negado";
  }
  else
  {
    this->nome = "";
  }
  
}
/**
 * The constructor for the Departamento class
 * 
 * @param valNome
 */
Departamento::Departamento(string valNome)
{
  if(!Empresa::getEmpresa()->getAcesso("Departamento.Departamento"))
  {
    throw "Acesso negado";
  }
  else
  {
    this->nome = valNome;
  }
}
/**
 * The destructor for the Departamento class
 */
Departamento::~Departamento()
{
}
/**
 * It returns the name of the department.
 * 
 * @return The name of the department.
 */
string Departamento::getNome()
{
  return this->nome;
}
/**
 * This function sets the value of the private variable nome to the value of the parameter valNome
 * 
 * @param valNome
 */
void Departamento::setNome(string valNome)
{
  this->nome = valNome;
}
