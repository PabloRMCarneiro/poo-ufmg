#ifndef ORDEMDECOMPRA_H_INCLUDED
#define ORDEMDECOMPRA_H_INCLUDED
#include "Orcamento.h"
#include "Fornecedor.h"
#include "MateriaPrima.h"
#include "data.h"
#include <string>
#include <vector>
#include <utility>

using namespace std;

class OrdemDeCompra{
    private:
        vector<MateriaPrima*> materiaPrimaLista;
        Data dataOrdem;
        double valorTotal;
        vector <pair<Fornecedor*, MateriaPrima*>> melhoresPrecos;
        vector <Orcamento*> orcamentos;
        bool compra;
    public:
        OrdemDeCompra();
        OrdemDeCompra(MateriaPrima* valMateriaPrima);
        void gerarPedidos();
        void setData(Data valData);
        void setMateriaPrima(MateriaPrima* valMateriaPrima);
        void setMateriaPrimaLista(vector<MateriaPrima*> valMateriaPrima);
        void setMelhoresPrecos();
        void setValorTotal(double valValorTotal);
        void setCompra(bool valCompra);
        void setOrcamento();

        Data getDatOrdem();
        double getValorTotal();
        vector <Orcamento*> getOrcamentos();
        vector<MateriaPrima*> getMateriaPrimaLista();
        vector <pair<Fornecedor*, MateriaPrima*>> getMelhoresPrecos();
        bool getComprou();
};

#endif