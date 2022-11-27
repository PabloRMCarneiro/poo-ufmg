#include "../include/Categoria.h"
#include "../include/Empresa.h"
#include "../include/PermissaoNegada.h"
#include "../include/UsuarioLogado.h"

Categoria::Categoria()
{
}

Categoria::Categoria(string t)
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Categoria.Categoria"))
  {
    PermissaoNegada *a = new PermissaoNegada("Categoria", "Categoria");
    throw "Acesso negado a Categoria.Categoria";
  }
  else
  { 
    this->tipo = t;
    LogEscrita *a = new LogEscrita("tipo", "indefinido", t, "Categoria");
    Empresa::getEmpresa()->setCategoria(this);
  }
}

Categoria::~Categoria()
{
}

string Categoria::getTipo()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Categoria.getTipo"))
  {
    PermissaoNegada *a = new PermissaoNegada("getTipo", "Categoria");
    throw "Acesso negado a Categoria.getTipo";
  }
  else
  {
    return this->tipo;
    LogLeitura *a = new LogLeitura("tipo", "Categoria");
  }
}

void Categoria::setTipo(string t)
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Categoria.getTipo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setTipo", "Categoria");
    throw "Acesso negado a Categoria.setTipo";
  }
  else
  {
    LogEscrita *a = new LogEscrita("tipo", this->tipo, t, "Categoria");
    this->tipo = t;
  }
}