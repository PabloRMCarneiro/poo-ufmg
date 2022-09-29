#ifndef REGISTROVENDAS_H_INCLUDED
#define REGISTROVENDAS_H_INCLUDED
#include "../include/Produto.h"

class RegistroVendas{
    private:
        Data dataDeVenda;
        vector<int> lote;
        Produto* produto;
        int quantidadeVenda;
        bool vendido = false;
        //Cliente* cliente //////////////////
    public:
        //construtor
        RegistroVendas(Data dv, string p, int q);
        RegistroVendas(Data dv, Produto* p, int q);
        //metodos get
        Data getDataDeVenda();
        vector<int> getNumeroDoLote();
        Produto* getProduto();
        int getQuantidadeVenda();
        //metodos set
        void setDataDeVenda(Data v);
        void setNumeroDoLote(int nl);
        void setProduto(string p);
        void setProduto(Produto* p);
        void setQuantidadeVenda(int qvenda);
        bool validaVenda(int q);
};

#endif //REGISTROVENDAS_H_INCLUDED