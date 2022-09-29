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
    Categoria(string t);
    ~Categoria();

    string getTipo();
    void setTipo(string t);
    static vector <Categoria*> categorialist;
    static void novaCategoria(Categoria* nova);
    static Categoria* getCategoria(string t);
    
};
// class CategoriaList{
//     public:
//         static vector <Categoria*> categorialist;
//         static void novaCategoria(Categoria* nova);
//         static Categoria* getCategoria(string t);
// };


#endif //CATEGORIA_H_INCLUDED