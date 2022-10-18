#include "../include/Log.h"
#include "../include/data.h"
#include "../include/Empresa.h"

#include <string>

using namespace std;

/**
 * Log::Log()
 * 
 * @param valUsuario
 * @param valDataAcesso
 * @param valEntidade
 */

Log::Log()
{
  this->usuario = Empresa::getEmpresa()->getUsuario(); //Usuario();
  this->dataAcesso = Data();
  this->entidade = "";
}

/**
 * Log::Log(Usuario* valUsuario, Data valDataAcesso, string valEntidade)
 * 
 * @param valUsuario
 * @param valDataAcesso
 * @param valEntidade
 */

Log::Log(Usuario* valUsuario, Data valDataAcesso, string valEntidade)
{
  this->usuario = valUsuario;
  this->dataAcesso = valDataAcesso;
  this->entidade = valEntidade;
}

/**
 * Log::~Log()
 * 
 * This is a destructor for the class Log. It does nothing.
 */

Log::~Log()
{

}

/**
 * Log::setUsuario(Usuario* valUsuario)
 * 
 * @param valUsuario
 */

void Log::setUsuario(Usuario* valUsuario)
{
  this->usuario = valUsuario;
}

/**
 * Log::setDataAcesso(Data valDataAcesso)
 * 
 * @param valDataAcesso
 */

void Log::setDataAcesso(Data valDataAcesso)
{
  this->dataAcesso = valDataAcesso;
}

/**
 * Log::setEntidade(string valEntidade)
 * 
 * @param valEntidade
 */

void Log::setEntidade(string valEntidade)
{
  this->entidade = valEntidade;
}

/**
 * Log::getUsuario()
 * 
 * @return Usuario*
 */

Usuario* Log::getUsuario()
{
  return this->usuario;
}

/**
 * Log::getData()
 * 
 * @return Data
 */

Data Log::getData()
{
  return this->dataAcesso;
}

/**
 * Log::getEntidade()
 * 
 * @return string
 */

string Log::getEntidade()
{
  return this->entidade;
}

