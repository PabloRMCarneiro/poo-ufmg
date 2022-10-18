#ifndef LOGLEITURA_H_INCLUDED
#define LOGLEITURA_H_INCLUDED
#include "Log.h"

using namespace std;

class LogLeitura : public Log
{
  private:
    string atributo;

  public:
    LogLeitura(string, Usuario*, Data, string);
    string getAtributo();
    void setAtributo(string);
};

#endif