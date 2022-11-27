#include "../include/Departamento.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"
#include <string>

using namespace std;

Departamento::Departamento()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Departamento.Departamento"))
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
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Departamento.Departamento"))
  {
    PermissaoNegada *a = new PermissaoNegada("Departamento", "Departamento");
    throw "Acesso negado a Departamento.Departamento";
  }
  else
  {
    this->setNome(valNome);
  }
}

Departamento::~Departamento()
{
}

string Departamento::getNome()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Departamento.getNome"))
  {
    PermissaoNegada *a = new PermissaoNegada("getNome", "Departamento");
    throw "Acesso negado a Departamento.getNome";
  }
  else
  { 
    return this->nome;
    LogLeitura *a = new LogLeitura("nome", "Departamento");
  }
}

void Departamento::setNome(string valNome)
{ 
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Departamento.getNome"))
  {
    PermissaoNegada *a = new PermissaoNegada("setNome", "Departamento");
    throw "Acesso negado a Departamento.setNome";
  }
  else
  {
    this->nome = valNome;
    LogEscrita *a = new LogEscrita("nome", "indefinido", valNome, "Departamento");
  }
}
