#include "../include/Categoria.h"
#include "../include/Empresa.h"
#include "../include/PermissaoNegada.h"
#include "../include/UsuarioLogado.h"

Categoria::Categoria()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Categoria.Categoria"))
  {
    PermissaoNegada *permissaoNegada = new PermissaoNegada("Categoria", "Categoria");
    string mensagem = "Acesso negado a Categoria.Categoria";
    throw mensagem;
  }
  else
  {
    this->tipo = "";
  }
}

Categoria::Categoria(string t)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Categoria.Categoria"))
  {
    PermissaoNegada *a = new PermissaoNegada("Categoria", "Categoria");
    string menssagem = "Acesso negado a Categoria.Categoria";
    throw menssagem;
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
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Categoria.getTipo"))
  {
    PermissaoNegada *a = new PermissaoNegada("getTipo", "Categoria");
    string menssagem = "Acesso negado a Categoria.getTipo";
    throw menssagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("tipo", "Categoria");
    return this->tipo;
  }
}

void Categoria::setTipo(string t)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Categoria.setTipo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setTipo", "Categoria");
    string messagem = "Acesso negado a Categoria.setTipo";
    throw messagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("tipo", this->tipo, t, "Categoria");
    this->tipo = t;
  }
}