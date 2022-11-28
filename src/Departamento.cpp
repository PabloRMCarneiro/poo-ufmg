#include "../include/Departamento.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"
#include "../include/PermissaoNegada.h"
#include <string>

using namespace std;

Departamento::Departamento()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Departamento.Departamento"))
  {
    PermissaoNegada *a = new PermissaoNegada("Departamento", "Departamento");
    string mensagem = "Acesso negado a Departamento.Departamento";
    throw mensagem;
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
    PermissaoNegada *a = new PermissaoNegada("Departamento", "Departamento");
    string mensagem = "Acesso negado a Departamento.Departamento";
    throw mensagem;
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
    PermissaoNegada *a = new PermissaoNegada("getNome", "Departamento");
    string mensagem = "Acesso negado a Departamento.getNome";
    throw mensagem;
  }
  else
  { 
    LogLeitura *a = new LogLeitura("nome", "Departamento");
    return this->nome;
  }
}

void Departamento::setNome(string valNome)
{ 
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Departamento.setNome"))
  {
    PermissaoNegada *a = new PermissaoNegada("setNome", "Departamento");
    string mensagem = "Acesso negado a Departamento.setNome";
    throw mensagem;
  }
  else
  {
    this->nome = valNome;
    LogEscrita *a = new LogEscrita("nome", "indefinido", valNome, "Departamento");
  }
}