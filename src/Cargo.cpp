#include "../include/Cargo.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"

using namespace std;

Cargo::Cargo()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cargo.Cargo"))
  { 
    PermissaoNegada *a = new PermissaoNegada("Cargo", "Cargo");
    string menssagem = "Acesso negado a Cargo.Cargo";
    throw menssagem;
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
    string menssagem = "Acesso negado a Cargo.Cargo";
    throw menssagem;
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
    string menssagem = "Acessa negado a Cargo.getNome";
    throw menssagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("nome", "Cargo");
    return this->nome; 
  }
}

void Cargo::setNome(string valNome)
{ 
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cargo.setNome"))
  {
    PermissaoNegada *a = new PermissaoNegada("setNome", "Cargo");
    string menssagem = "Acessa negado a Cargo.setNome";
    throw menssagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("valNome", this->nome, valNome, "Cargo");
    this->nome = valNome;
  }
}