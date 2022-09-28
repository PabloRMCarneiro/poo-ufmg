#include <string>
#include <vector>
#include "../include/Categoria.h"

using namespace std;

Categoria::Categoria()
{
  this->tipo = "";
  
}

Categoria::Categoria(string tipo)
{
  this->tipo = tipo;
}

Categoria::~Categoria()
{
}

string Categoria::getTipo()
{
  return this->tipo;
}

void Categoria::setTipo(string tipo)
{
  this->tipo = tipo;
  
}


