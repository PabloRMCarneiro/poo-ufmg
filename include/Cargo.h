#ifndef CARGO_H_INCLUDED
#define CARGO_H_INCLUDED
#include <string>

using namespace std;

class Cargo
{
  private:
    string nome;
    
  public:
    Cargo();
    Cargo(string valNome);
    virtual ~Cargo();
    
    //Metodos get:
    string getNome();
    
    //Metodos set:
    void setNome(string valNome);
};

#endif