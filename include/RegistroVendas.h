#ifndef REGISTROVENDAS_H_INCLUDED
#define REGISTROVENDAS_H_INCLUDED
#include "../include/Produto.h"
#include "../include/Cliente.h"

class RegistroVendas{
    private:
        Data dataDeVenda;
        vector<int> lote;
        Produto* produto;
        int quantidadeVenda;
        bool vendido = false;
        Cliente* cliente;
    public:
        RegistroVendas(Data dv, string p, int q, Cliente* cl);
        RegistroVendas(Data dv, Produto* p, int q, Cliente* cl);
        Data getDataDeVenda();
        vector<int> getNumeroDoLote();
        Produto* getProduto();
        int getQuantidadeVenda();
        Cliente* getCliente();
        void setCliente(Cliente* cl);
        void setDataDeVenda(Data v);
        void setNumeroDoLote(int nl);
        void setProduto(string p);
        void setProduto(Produto* p);
        void setQuantidadeVenda(int qvenda);
        bool validaVenda(int q);
};

#endif 