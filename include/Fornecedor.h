#ifndef FORNECEDOR_H_INCLUDED
#define FORNECEDOR_H_INCLUDED
#include "../include/Produto.h"
#include "../include/MateriaPrima.h"
#include "../include/Pessoa.h"
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Fornecedor{
    private:
        vector <pair<MateriaPrima*, double>> precos;
    public:
        Fornecedor();
        double getPreco(MateriaPrima*);
        bool vende(MateriaPrima*, double);
        void setPreco(vector<pair<MateriaPrima*, double>>);
};

#endif