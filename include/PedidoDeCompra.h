#ifndef PEDIDODECOMPRA_H_INCLUDED
#define PEDIDODECOMPRA_H_INCLUDED
#include "data.h"
#include "RegistroVendas.h"
#include "Orcamento.h"
#include "Boleto.h"
#include "CartaoDeCredito.h"

class PedidoDeCompra
{
    private:
      static int contPedidos;
      int codigo;
      Orcamento *orcamento;
      Boleto *boleto;
      CartaoDeCredito *cartaoDeCredito;
      Data data;
      bool vendaRealizada;
    public:
        PedidoDeCompra();
        PedidoDeCompra(Orcamento *valOrcamento, Data valDataVencimento);
        PedidoDeCompra(Orcamento *valOrcamento, CartaoDeCredito *valCartaoDeCredito, int parcelas);
        ~PedidoDeCompra();
        void setOrcamento(Orcamento *valOrcamento);
        void setBoleto(Data valDataVencimento);
        void setCartaoDeCredito(CartaoDeCredito *valCartaoDeCredito);
        void setVenda();
        int getCodigo();
        Orcamento *getOrcamento();
        Boleto *getBoleto();
        CartaoDeCredito *getCartaoDeCredito();

};

#endif 