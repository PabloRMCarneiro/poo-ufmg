#include "../include/Log.h"
#include "../include/data.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"
#include <string>

using namespace std;

Log::Log()
{

  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Log.Log"))
  {
    throw "Acesso negado a Log.Log";
  }
  else
  {
    this->usuario = UsuarioLogado::getUsuarioLogado()->getUsuario();
    this->dataAcesso = Data();
    this->entidade = "";
  }

}

Log::Log(Usuario* valUsuario, Data valDataAcesso, string valEntidade)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Log.Log"))
  {
    throw "Acesso negado a Log.Log";
  }
  else
  {
  this->usuario = valUsuario;
  this->dataAcesso = valDataAcesso;
  this->entidade = valEntidade;
  }
}

Log::~Log()
{

}

void Log::setUsuario(Usuario* valUsuario)
{
  this->usuario = valUsuario;
}

void Log::setDataAcesso(Data valDataAcesso)
{
  this->dataAcesso = valDataAcesso;
}

void Log::setEntidade(string valEntidade)
{
  this->entidade = valEntidade;
}

Usuario* Log::getUsuario()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Log.getUsuario"))
  {
    throw "Acesso negado a Log.getUsuario";
  }
  else
  {
    return this->usuario;
  }
}

Data Log::getData()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Log.getData"))
  {
    throw "Acesso negado a Log.getData";
  }
  else
  {
    return this->dataAcesso;
  }
}

string Log::getEntidade()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Log.getEntidade"))
  {
    throw "Acesso negado a Log.getEntidade";
  }
  else
  {
    return this->entidade;
  }
}

