#include "../include/Log.h"
#include "../include/LogEscrita.h"

#include <string>
#include <map>

using namespace std;

/**
 * LogEscrita::LogEscrita(map<string, string> valAtributosAntes, map<string, string> valAtributosDepois, Usuario* valUsuario, Data valDataAcesso, string valEntidade)
 * 
 * @param valAtributosAntes
 * @param valAtributosDepois
 * @param valUsuario
 * @param valDataAcesso
 * @param valEntidade
 */

LogEscrita::LogEscrita(map<string, string> valAtributosAntes, map<string, string> valAtributosDepois, Usuario* valUsuario, Data valDataAcesso, string valEntidade) : Log(valUsuario, valDataAcesso, valEntidade)
{
  this->atributosAntes = valAtributosAntes;
  this->atributosDepois = valAtributosDepois;
}

/**
 * LogEscrita::getAtributosAntes()
 * 
 * @return map<string, string>
 */

map<string, string> LogEscrita::getAtributosAntes()
{
  return this->atributosAntes;
}

/**
 * LogEscrita::getAtributosDepois()
 * 
 * @return map<string, string>
 */

map<string, string> LogEscrita::getAtributosDepois()
{
  return this->atributosDepois;
}

/**
 * LogEscrita::setAtributosAntes(string valAtributo, string valValor)
 * 
 * @param valAtributo
 * @param valValor
 */

void LogEscrita::setAtributosAntes(string valAtributo, string valValor)
{
  this->atributosAntes[valAtributo] = valValor;
}

/**
 * LogEscrita::setAtributosDepois(string valAtributo, string valValor)
 * 
 * @param valAtributo
 * @param valValor
 */

void LogEscrita::setAtributosDepois(string valAtributo, string valValor)
{
  this->atributosDepois[valAtributo] = valValor;
}
