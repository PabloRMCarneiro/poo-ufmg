#include "../include/Cargo.h"
#include "../include/Empresa.h"
#include "../include/PermissaoNegada.h"

using namespace std;

Cargo::Cargo()
{

  if(!Empresa::getEmpresa()->getAcesso("Cargo.Cargo"))
  {
    throw acessoNegadoCargo();
  }
  
  else
    nome = "";
  
}
Cargo::Cargo(string valNome)
{
  if(!Empresa::getEmpresa()->getAcesso("Cargo.Cargo"))
  {
    throw acessoNegadoCargo();
  }
  
  else nome = valNome;
  
}
Cargo::~Cargo()
{
}
string Cargo::getNome()
{
  if(!Empresa::getEmpresa()->getAcesso("Cargo.getNome"))
  {
    throw acessoNegadoNomeCargo();
  }
  
  else return this->nome;
}
void Cargo::setNome(string valNome)
{
  this->nome = valNome;
}
 