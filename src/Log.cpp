#include "../include/Log.h"
#include "../include/data.h"
#include "../include/Empresa.h"
#include <string>

using namespace std;

Log::Log()
{

  this->usuario = Empresa::getEmpresa()->getUsuario(); //Usuario();
  this->dataAcesso = Data();
  this->entidade = "";
}

Log::Log(Usuario* valUsuario, Data valDataAcesso, string valEntidade)
{
  this->usuario = valUsuario;
  this->dataAcesso = valDataAcesso;
  this->entidade = valEntidade;
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
  return this->usuario;
}

Data Log::getData()
{
  return this->dataAcesso;
}

string Log::getEntidade()
{
  return this->entidade;
}

