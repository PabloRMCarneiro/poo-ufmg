#ifndef LOTE_H_INCLUDED
#define LOTE_H_INCLUDED
#include <iostream>
#include <string>
#include "../include/data.h"
using namespace std;

class Lote{
    private:
        int numLote;
        int quantidadeProduzida;
        int quantidadeAtual;
        string produto;
        Data dataProd;

    public:
        //construtores
        Lote(int nl);
        Lote();
        Lote(Data d, int nl, int qp, string p);
        //metodos set
        void setNumLote(int nl);
        void setQuantidadeProduzida(int qp);
        void setQuantidadeAtual(int qa);
        void setProduto(string p);
        void setDataProd(Data);
        //metodos get
        int getNumLote();
        int getQuantidadeProduzida();
        int getQuantidadeAtual();
        string getProduto();
        Data getDataProd();
        //para realizar venda -> retorna quantidade que não foi possivel vender neste lote
        int vende(int q);
        //para imprimir registro de producao
        void imprimeRegistro();

};
#endif //LOTE_H_INCLUDED