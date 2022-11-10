#include "../include/Log.h"
#include "../include/LogLeitura.h"
#include <string>

using namespace std;


LogLeitura::LogLeitura(string valAtributo, Usuario* valUsuario, Data valDataAcesso, string valEntidade) : Log(valUsuario, valDataAcesso, valEntidade)
{
  this->atributo = valAtributo;
}

string LogLeitura::getAtributo()
{
  return this->atributo;
}

void LogLeitura::setAtributo(string valAtributo)
{
  this->atributo = valAtributo;
}

