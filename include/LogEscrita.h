#ifndef LOGESCRITA_H_INCLUDED
#define LOGESCRITA_H_INCLUDED
#include "Log.h"

#include <string>
#include <map>

using namespace std;

class LogEscrita : public Log
{
  private:
    string atributo;
    string antes;
    string depois;

  public:
    LogEscrita();
    LogEscrita(string valAtributo, string valAntes, string valDepois, string valEntidade);
    string getAtributoAntes();
    string getAtributoDepois();
    string getAtributo();
    void setAtributoAntes(string valAtributoAntes);
    void setAtributoDepois(string valAtributoDepois);
    void setAtributo(string valAtributo);
    void imprime();
};

#endif