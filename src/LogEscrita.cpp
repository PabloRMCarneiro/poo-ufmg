#include "../include/Log.h"
#include "../include/LogEscrita.h"
#include "../include/UsuarioLogado.h"
#include <string>
#include <map>

using namespace std;

LogEscrita::LogEscrita(map<string, string> valAtributosAntes, map<string, string> valAtributosDepois, string valEntidade) : Log(valEntidade)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("LogEscrita.LogEscrita"))
  {
    throw "Acesso negado a LogEscrita.LogEscrita";
  }
  else
  {
    this->atributosAntes = valAtributosAntes;
    this->atributosDepois = valAtributosDepois;
  }
}

map<string, string> LogEscrita::getAtributosAntes()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("LogEscrita.getAtributosAntes"))
  {
    throw "Acesso negado a LogEscrita.getAtributosAntes";
  }
  else
  {
    return this->atributosAntes;
  }
}

map<string, string> LogEscrita::getAtributosDepois()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("LogEscrita.getAtributosDepois"))
  {
    throw "Acesso negado a LogEscrita.getAtributosDepois";
  }
  else
  {
    return this->atributosDepois;
  }
}

void LogEscrita::setAtributosAntes(string valAtributo, string valValor)
{
  this->atributosAntes[valAtributo] = valValor;
}

void LogEscrita::setAtributosDepois(string valAtributo, string valValor)
{
  this->atributosDepois[valAtributo] = valValor;
}
