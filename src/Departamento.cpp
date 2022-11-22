#include "../include/Departamento.h"
#include "../include/Empresa.h"
#include <string>

using namespace std;

Departamento::Departamento()
{
  this->nome = "";
}

Departamento::Departamento(string valNome)
{
  this->nome = valNome;
}

Departamento::~Departamento()
{
}

string Departamento::getNome()
{
  return this->nome;
}

void Departamento::setNome(string valNome)
{
  this->nome = valNome;
}
