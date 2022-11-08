#ifndef MATERIAPRIMA_H_INCLUDED
#define MATERIAPRIMA_H_INCLUDED
#include "../include/Produto.h"
#include "../include/Orcamento.h"
#include <string>

using namespace std;

class MateriaPrima {
    private:
        string nome;
        double estoque;
        string unidadeDeMedida;
        double estoqueMinimo;
    public:
        void geraOrdemDeCompra(); 
        
        double getEstoque();
        string getUnidadeMedida();
        double getEstoqueMinimo();

        void setEstoqueMin(double valEstoqueMinimo);
        void setEstoque(double valEstoque);
        void setNome(string valNome);
        void setUnidadeDeMedida(string valUnidadeDeMedida);

        MateriaPrima();
};

#endif