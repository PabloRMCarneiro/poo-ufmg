#ifndef LOTE_H_INCLUDED
#define LOTE_H_INCLUDED
#include <iostream>
#include <string>
#include "data.h"
using namespace std;

class Lote{
    private:
        int numLote;
        int quantidadeProduzida;
        int quantidadeAtual;
        string produto;
        Data dataProd;
    public:
        Lote(int nl);
        Lote();
        Lote(Data d, int nl, int qp, string p);
        
        void setNumLote(int nl);
        void setQuantidadeProduzida(int qp);
        void setQuantidadeAtual(int qa);
        void setProduto(string p);
        void setDataProd(Data);

        int getNumLote();
        int getQuantidadeProduzida();
        int getQuantidadeAtual();
        string getProduto();
        Data getDataProd();

        int vende(int q);
        void imprimeRegistro();
};
#endif 