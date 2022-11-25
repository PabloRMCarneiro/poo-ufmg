#ifndef FORNECEDOR_H_INCLUDED
#define FORNECEDOR_H_INCLUDED
#include "Produto.h"
#include "MateriaPrima.h"
#include "Pessoa.h"
#include <string>
#include <utility>
#include <vector>

using namespace std;

class Fornecedor : public Pessoa{
    private:
        string tipoFornecedor;
        vector <pair<MateriaPrima*, double>> precos;
    public:
    //construtor
        Fornecedor();
        Fornecedor(string valNome, Endereco valEndereco, string valEmail, string valDocumento, long int valTelefone);
    //metodos set
        void setPrecos(vector<pair<MateriaPrima*, double>> valPrecos);
        void setPreco(pair<MateriaPrima*, double> valMateriaPrima);
        void setTipoFornecedor(string valTipoFornecedor);
    //metodos get
        string getTipoFornecedor(string valTipoFornecedor);
        double getPreco(MateriaPrima* valMateriaPrima);
        vector <pair<MateriaPrima*, double>> getPrecos();
        static vector <Fornecedor*> fornecedorList;
        bool vende(MateriaPrima* valMateriaPrima, double valQuantidade, Data valData);
};

#endif