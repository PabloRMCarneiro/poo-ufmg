#ifndef REGISTROVENDAS_H_INCLUDED
#define REGISTROVENDAS_H_INCLUDED
#include "Produto.h"
#include "Cliente.h"
#include "data.h"

#include <vector>
#include <string>
class RegistroVendas{
    private:
        Data dataDeVenda;
        vector<int> lote;
        Produto* produto;
        int quantidadeVenda;
        bool vendido = false;
        Cliente* cliente;
        int codigoPedido;
    public:
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
        void setCodigoPedido(int valCodigoPedido);
        int getCodigoPedido();
        bool validaVenda(int q);
        void imprime();
};

#endif 