#include "../include/Departamento.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"
#include <string>

using namespace std;

Departamento::Departamento()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Departamento.Departamento"))
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
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Departamento.Departamento"))
  {
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
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Departamento.getNome"))
  {
    throw "Acesso negado a Departamento.getNome";
  }
  else
  {
    return this->nome;
  }
}

void Departamento::setNome(string valNome)
{
  this->nome = valNome;
}
