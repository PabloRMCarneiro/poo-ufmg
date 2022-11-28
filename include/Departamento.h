#ifndef DEPARTAMENTO_H_INCLUDED
#define DEPARTAMENTO_H_INCLUDED
#include <string>

using namespace std;

class Departamento
{
  private:
    string nome;
    
  public:
    Departamento();
    Departamento(string valNome);
    virtual ~Departamento();
    
    string getNome();
    
    void setNome(string valNome);
};

#endif