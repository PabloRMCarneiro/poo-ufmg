#include "../include/Log.h"
#include "../include/LogEscrita.h"
#include <string>
#include <map>

using namespace std;

LogEscrita::LogEscrita(map<string, string> valAtributosAntes, map<string, string> valAtributosDepois, Usuario* valUsuario, Data valDataAcesso, string valEntidade) : Log(valUsuario, valDataAcesso, valEntidade)
{
  this->atributosAntes = valAtributosAntes;
  this->atributosDepois = valAtributosDepois;
}

map<string, string> LogEscrita::getAtributosAntes()
{
  return this->atributosAntes;
}

map<string, string> LogEscrita::getAtributosDepois()
{
  return this->atributosDepois;
}

void LogEscrita::setAtributosAntes(string valAtributo, string valValor)
{
  this->atributosAntes[valAtributo] = valValor;
}

void LogEscrita::setAtributosDepois(string valAtributo, string valValor)
{
  this->atributosDepois[valAtributo] = valValor;
}
