#include "../include/Cargo.h"
#include "../include/PermissaoNegada.h"

using namespace std;

Cargo::Cargo()
{
  nome = "";
}
Cargo::Cargo(string valNome)
{
  nome = valNome;
}
Cargo::~Cargo()
{
}
string Cargo::getNome()
{
  return this->nome;
}
void Cargo::setNome(string valNome)
{
  this->nome = valNome;
}
 