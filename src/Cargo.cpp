#include "../include/Cargo.h"
#include <string>

using namespace std;

Cargo::Cargo()
{
  this->nome = "";  
}

Cargo::Cargo(string valNome)
{
  this->nome = valNome;
}

Cargo::~Cargo()
{
}

//Metodos get:

string Cargo::getNome()
{
  return this->nome;
}

//Metodos set:

void Cargo::setNome(string valNome)
{
  this->nome = valNome;
}
 