#include "../include/Log.h"
#include "../include/LogLeitura.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"
#include <string>

using namespace std;


LogLeitura::LogLeitura(string valAtributo, string valEntidade) : Log(valEntidade)
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("LogLeitura.LogLeitura"))
  {
    throw "Acesso negado a LogLeitura.LogLeitura";
  }
  else
  {
    this->atributo = valAtributo;
    Empresa::getEmpresa()->setlogLeitura(this);
  }
}

string LogLeitura::getAtributo()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("LogLeitura.getAtributo"))
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

void LogLeitura::imprime(){
  cout << "Em "<< this->getData().getData() << " - ";
  cout << "atributo " <<this->atributo << " da classe "<< this->getEntidade() << " foi lido." << endl;
}