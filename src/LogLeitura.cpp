#include "../include/Log.h"
#include "../include/LogLeitura.h"

#include <string>

using namespace std;

/**
 * LogLeitura::LogLeitura(string valAtributo, Usuario* valUsuario, Data valDataAcesso, string valEntidade)
 * 
 * @param valAtributo
 * @param valUsuario
 * @param valDataAcesso
 * @param valEntidade
 */

LogLeitura::LogLeitura(string valAtributo, Usuario* valUsuario, Data valDataAcesso, string valEntidade) : Log(valUsuario, valDataAcesso, valEntidade)
{
  this->atributo = valAtributo;
}

/**
 * LogLeitura::getAtributo()
 * 
 * @return string
 */

string LogLeitura::getAtributo()
{
  return this->atributo;
}

/**
 * LogLeitura::setAtributo(string valAtributo)
 * 
 * @param valAtributo
 */

void LogLeitura::setAtributo(string valAtributo)
{
  this->atributo = valAtributo;
}

