#ifndef ORDEMDEPRODUCAO_H_INCLUDED
#define ORDEMDEPRODUCAO_H_INCLUDED
#include "data.h"
class OrdemDeProducao{
    private:
        Data dataOrdem;
        string produto;
        int quantidade;
    public:
        OrdemDeProducao();
        OrdemDeProducao(Data dO, string p, int q);
        void setDataOrdem(Data dO);
        void setProduto(string p);
        void setQuantidade(int q);
        
        Data getDataOrdem();
        string getProduto();
        int getQuantidade();
        
        void getOrdem();
};
#endif 