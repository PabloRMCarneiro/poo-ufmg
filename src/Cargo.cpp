#include "../include/Cargo.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"

using namespace std;

Cargo::Cargo()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cargo.Cargo"))
  { 
    PermissaoNegada *a = new PermissaoNegada("Cargo", "Cargo");
    string messagem = "Acesso negado a Cargo.Cargo";
    throw messagem;
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
    PermissaoNegada *a = new PermissaoNegada("Cargo", "Cargo");
    string messagem = "Acesso negado a Cargo.Cargo";
    throw messagem;
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cargo.getNome"))
  {
    PermissaoNegada *a = new PermissaoNegada("getNome", "Cargo");
    string messagem = "Acessa negado a Cargo.getNome";
    throw messagem;
  }
  else
  {
    return this->nome;
    LogLeitura *a = new LogLeitura("nome", "Cargo");
  }
}

void Cargo::setNome(string valNome)
{ 
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cargo.getNome"))
  {
    PermissaoNegada *a = new PermissaoNegada("setNome", "Cargo");
    string messagem = "Acessa negado a Cargo.setNome";
    throw messagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("valNome", this->nome, valNome, "Cargo");
    this->nome = valNome;
  }
}