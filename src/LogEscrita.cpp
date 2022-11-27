#include "../include/Log.h"
#include "../include/LogEscrita.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"
#include <string>
#include <map>

using namespace std;

LogEscrita::LogEscrita(){

}
LogEscrita::LogEscrita(string valAtributo, string valAntes, string valDepois, string valEntidade) : Log(valEntidade)
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("LogEscrita.LogEscrita"))
  {
    throw "Acesso negado a LogEscrita.LogEscrita";
  }
  else
  {
    this->atributo = valAtributo;
    this->antes = valAntes;
    this->depois = valDepois;
    Empresa::getEmpresa()->setlogEscrita(this);
  }
}

string LogEscrita::getAtributoAntes()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("LogEscrita.getAtributosAntes"))
  {
    throw "Acesso negado a LogEscrita.getAtributosAntes";
  }
  else
  {
    return this->antes;
  }
}

string LogEscrita::getAtributoDepois()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("LogEscrita.getAtributosDepois"))
  {
    throw "Acesso negado a LogEscrita.getAtributosDepois";
  }
  else
  {
    return this->depois;
  }
}
string LogEscrita::getAtributo(){
  return this->atributo;
}
void LogEscrita::setAtributoAntes(string valAtributoAntes)
{
  this->antes = valAtributoAntes;
}

void LogEscrita::setAtributoDepois(string valAtributoDepois)
{
  this->depois = valAtributoDepois;
}

void LogEscrita::setAtributo(string valAtributo){
  this->atributo = valAtributo;
}
void LogEscrita::imprime(){
  cout << "Em "<< this->getData().getData() << " - ";
  cout << "atributo " <<this->atributo << " da classe "<< this->getEntidade() << " foi alterado: " << this->antes << " -> " << this->depois << "." << endl;
}