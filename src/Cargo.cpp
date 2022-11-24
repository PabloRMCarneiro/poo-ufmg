#include "../include/Cargo.h"
#include "../include/UsuarioLogado.h"

using namespace std;

Cargo::Cargo()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cargo.Cargo"))
  {
    throw "Acesso negado a Cargo.Cargo";
  }
  else
  {
    this->nome = "";
  }
}

Cargo::Cargo(string valNome)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cargo.Cargo"))
  {
    throw "Acesso negado a Cargo.Cargo";
  }
  else
  {
    this->nome = valNome;
  }
}

Cargo::~Cargo()
{
}

string Cargo::getNome()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cargo.getNome"))
  {
    throw "Acesso negado a Cargo.getNome";
  }
  else
  {
    return this->nome;
  }
}

void Cargo::setNome(string valNome)
{
  this->nome = valNome;
}
 