#ifndef LOGESCRITA_H_INCLUDED
#define LOGESCRITA_H_INCLUDED
#include "Log.h"

#include <string>
#include <map>

using namespace std;

class LogEscrita : public Log
{
  private:
    map<string, string> atributosAntes;
    map<string, string> atributosDepois;

  public:
    //<atributo, valAntes> <atributo, valDepois>
    LogEscrita(map<string, string>, map<string, string>, Usuario*, Data, string);
    map<string, string> getAtributosAntes();
    map<string, string> getAtributosDepois();
    void setAtributosAntes(string, string);
    void setAtributosDepois(string, string);
};

#endif