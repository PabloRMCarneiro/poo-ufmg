#include "../include/Cargo.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"

using namespace std;

Cargo::Cargo()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cargo.Cargo"))
  { 
    PermissaoNegada *a = new PermissaoNegada("Cargo", "Cargo");
    throw "Acesso negado a Cargo.Cargo";
  }
  else
  {
    this->nome = "";
  }
}

Cargo::Cargo(string valNome)
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cargo.Cargo"))
  {
    PermissaoNegada *a = new PermissaoNegada("Cargo", "Cargo");
    throw "Acesso negado a Cargo.Cargo";
  }
  else
  {
    this->nome = valNome;
    LogEscrita *a = new LogEscrita("nome", "indefinido", valNome, "Cargo");
  }
}

Cargo::~Cargo()
{
}

string Cargo::getNome()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cargo.getNome"))
  {
    PermissaoNegada *a = new PermissaoNegada("getNome", "Cargo");
    throw "Acesso negado a Cargo.getNome";
  }
  else
  {
    return this->nome;
    LogLeitura *a = new LogLeitura("nome", "Cargo");
  }
}

void Cargo::setNome(string valNome)
{ 
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cargo.getNome"))
  {
    PermissaoNegada *a = new PermissaoNegada("setNome", "Cargo");
    throw "Acesso negado a Cargo.setNome";
  }
  else
  {
    LogEscrita *a = new LogEscrita("valNome", this->nome, valNome, "Cargo");
    this->nome = valNome;
  }
}