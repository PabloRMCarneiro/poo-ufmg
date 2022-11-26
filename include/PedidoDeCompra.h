#ifndef E6F900AC_81D9_430B_B639_840D874D80B7
#define E6F900AC_81D9_430B_B639_840D874D80B7
#include "MetodoDePagamento.h"
#include "data.h"
#include "Orcamento.h"
#include "Boleto.h"
#include "CartaoDeCredito.h"

class PedidoDeCompra
{
    public:
        PedidoDeCompra();
        PedidoDeCompra(Orcamento *valOrcamento);
        PedidoDeCompra(Orcamento *valOrcamento, CartaoDeCredito *valCartaoDeCredito);
        ~PedidoDeCompra();
        void setOrcamento(Orcamento *valOrcamento);
        void setBoleto();
        void setCartaoDeCredito(CartaoDeCredito *valCartaoDeCredito);
        Orcamento *getOrcamento();
        Boleto *getBoleto();
        CartaoDeCredito *getCartaoDeCredito();
    private:
      Orcamento *orcamento;
      Boleto *boleto;
      CartaoDeCredito *cartaoDeCredito;
      Data data;

};

#endif 
