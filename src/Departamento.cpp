#include "Departamento.h"
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

//Metodos get:

string Departamento::getNome()
{
  return this->nome;
}

//Metodos set:

void Departamento::setNome(string valNome)
{
  this->nome = valNome;
}
