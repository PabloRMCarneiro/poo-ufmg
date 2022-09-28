#ifndef CATEGORIA_H_INCLUDED
#define CATEGORIA_H_INCLUDED
#include <string>
#include <vector>

using namespace std;

class Categoria
{
  private:
    string tipo;


  public:
    Categoria();
    Categoria(string tipo);
    ~Categoria();

    string getTipo();
    void setTipo(string tipo);
    
};


#endif