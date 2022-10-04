#ifndef CARGO_H_INCLUDED
#define CARGO_H_INCLUDED
#include <string>
using namespace std;

class Cargo{
  private:
    string nome;
  public:
    Cargo();
    Cargo(string valNome);
    virtual ~Cargo();
    string getNome();
    void setNome(string valNome);
};

#endif