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
        vector<MateriaPrima*> materiaPrimaLista;
        Data dataOrdem;
        double valorTotal;
        vector <pair<Fornecedor*, MateriaPrima*>> melhoresPrecos;
        vector <Orcamento*> orcamento;
        bool compra;
    public:
        OrdemDeCompra();
        OrdemDeCompra(Data valData, MateriaPrima* valMateriaPrima);
        void gerarPedidos(Data valData);
        void setData(Data valData);
        void setMateriaPrima(MateriaPrima* valMateriaPrima);
        void setMateriaPrimaLista(vector<MateriaPrima*> valMateriaPrima);
        void setMelhoresPrecos();
        void setValorTotal(double valValorTotal);
        void setCompra(bool valCompra);
        void setOrcamento();

        Data getDatOrdem();
        double getValorTotal();
        vector <Orcamento*> getOrcamento();
        vector<MateriaPrima*> getMateriaPrimaLista();
        vector <pair<Fornecedor*, MateriaPrima*>> getMelhoresPrecos();
        bool getComprou();
};

#endif