#ifndef ORDEMDECOMPRA_H_INCLUDED
#define ORDEMDECOMPRA_H_INCLUDED
#include "../include/Orcamento.h"
#include "../include/Fornecedor.h"
#include "../include/MateriaPrima.h"
#include "../include/data.h"
#include <string>
#include <vector>
#include <utility>

using namespace std;

class OrdemDeCompra{
    private:
        vector<MateriaPrima*> materiaPrima;
        Data dataOrdem;
        double valorTotal;
        vector <pair<Fornecedor*, MateriaPrima*>> melhoresPrecos;
        vector <Orcamento*> orcamento;
        bool compra;
    public:
        OrdemDeCompra(Data valData, MateriaPrima*);
        void gerarPedidos(MateriaPrima*, double);
        void setData(Data valData);
        void setMelhoresPrecos(vector <pair<Fornecedor*, MateriaPrima*>> valMelhoresPrecos);
        void setValorTotal(double valValorTotal);
        void setCompra(bool valCompra);

        Data getDatOrdem();
        double getValorTotal();
        vector <Orcamento*> getOrcamento();
};

#endif