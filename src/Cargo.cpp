#include "../include/Cargo.h"
#include "../include/Empresa.h"
#include <string>

using namespace std;

/**
 * Cargo::Cargo()
 * 
 * This is a constructor. It is a special function that is called when an object is created. It is used
 * to initialize the object
 */
Cargo::Cargo()
{
  
  if(!Empresa::getEmpresa()->getAcesso("Cargo.Cargo"))
  {
    throw "Acesso negado";
  }
  
  else
    nome = "";
  
}
/**
 * The function `Cargo::Cargo(string valNome)` is a constructor for the class `Cargo`
 * 
 * @param valNome The name of the cargo
 */
Cargo::Cargo(string valNome)
{
  if(!Empresa::getEmpresa()->getAcesso("Cargo.Cargo"))
  {
    throw "Acesso negado";
  } 
  
  else
    this->nome = valNome;
  
 
}
/**
 * The destructor is called when the object is destroyed
 */
Cargo::~Cargo()
{
}
/**
 * It returns the name of the cargo.
 * 
 * @return The name of the cargo.
 */

string Cargo::getNome()
{
  return this->nome;
}
/**
 * This function sets the value of the private variable nome to the value of the parameter valNome
 * 
 * @param valNome
 */
void Cargo::setNome(string valNome)
{
  this->nome = valNome;
}
 