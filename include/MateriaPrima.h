#ifndef MATERIAPRIMA_H_INCLUDED
#define MATERIAPRIMA_H_INCLUDED
#include <string>
#include "data.h"
using namespace std;

class MateriaPrima {
    private:
        string nome;
        double estoque;
        string unidadeDeMedida;
        double estoqueMinimo;
    public:
        MateriaPrima();
        MateriaPrima(string valNome, string valUnidadeDeMedida, double valEstoqueMinimo);
        void geraOrdemDeCompra(Data valData); 
        
        double getEstoque();
        string getUnidadeMedida();
        double getEstoqueMinimo();
        string getNome();

        void setEstoqueMin(double valEstoqueMinimo);
        void setEstoque(double valEstoque, Data valData);
        void setNome(string valNome);
        void setUnidadeDeMedida(string valUnidadeDeMedida);
};

#endif