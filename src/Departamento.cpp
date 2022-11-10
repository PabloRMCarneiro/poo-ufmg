#include "../include/Departamento.h"
#include "../include/Empresa.h"
#include <string>

using namespace std;

Departamento::Departamento()
{
  if(!Empresa::getEmpresa()->getAcesso("Departamento.Departamento"))
  {
    throw "Acesso negado a Departamento.Departamento";
  }
  else
  {
    this->nome = "";
  }
  
}

Departamento::Departamento(string valNome)
{
  if(!Empresa::getEmpresa()->getAcesso("Departamento.Departamento"))
  {
    throw "Acesso negado a Departamento.Departamento";
  }
  else
  {
    this->nome = valNome;
  }
}

Departamento::~Departamento()
{
}

string Departamento::getNome()
{
  if(!Empresa::getEmpresa()->getAcesso("Departamento.getNome"))
  {
    throw "Acesso negado a Departamento.getNome";
  }
  else
  {
    return this->nome;
  }
}

void Departamento::setNome(string valNome)
{
  this->nome = valNome;
}
