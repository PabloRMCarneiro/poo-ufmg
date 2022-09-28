#ifndef LISTADECATEGORIAS_H_INCLUDED
#define LISTADECATEGORIAS_H_INCLUDED

#include <vector>
#include <string>
#include "./Categoria.h"

using namespace std;

class ListaDeCategorias{

  private:
    static vector<Categoria*> categorias;

  public:
    ListaDeCategorias();
    ~ListaDeCategorias();

    void adicionarCategoria(Categoria categoria);
    void removerCategoria(Categoria categoria);
    void removerCategoria(string tipo);
    Categoria buscarCategoria(string tipo);
    vector<Categoria> getCategorias();
    void setCategorias(vector<Categoria> categorias);
};

#endif