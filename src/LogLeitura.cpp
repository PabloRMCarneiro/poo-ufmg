#include "../include/Log.h"
#include "../include/LogLeitura.h"
#include "../include/UsuarioLogado.h"
#include <string>

using namespace std;


LogLeitura::LogLeitura(string valAtributo, Usuario* valUsuario, Data valDataAcesso, string valEntidade) : Log(valUsuario, valDataAcesso, valEntidade)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("LogLeitura.LogLeitura"))
  {
    throw "Acesso negado a LogLeitura.LogLeitura";
  }
  else
  {
    this->atributo = valAtributo;
  }
}

string LogLeitura::getAtributo()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("LogLeitura.getAtributo"))
  {
    throw "Acesso negado a LogLeitura.getAtributo";
  }
  else
  {
    return this->atributo;
  }
}

void LogLeitura::setAtributo(string valAtributo)
{
  this->atributo = valAtributo;
}

