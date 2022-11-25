#ifndef LOG_H_INCLUDED
#define LOG_H_INCLUDED
#include "data.h"
#include "Usuario.h"
#include <string>

using namespace std;

class Log
{
  private:
    Usuario* usuario;
    Data dataAcesso;
    string entidade;

  public:
    Log();
    Log(string valEntidade);
    virtual ~Log();
    void setUsuario(Usuario*);
    void setDataAcesso(Data);
    void setEntidade(string);
    Usuario* getUsuario();
    Data getData();
    string getEntidade();
};

#endif