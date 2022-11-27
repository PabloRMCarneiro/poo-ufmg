#include "../include/PedidoDeCompra.h"

int PedidoDeCompra::contPedidos = 0;
PedidoDeCompra::PedidoDeCompra() {
}

PedidoDeCompra::PedidoDeCompra(Orcamento *valOrcamento, Data valDataVencimento){
  PedidoDeCompra::contPedidos++;
  this->codigo = contPedidos;
  setOrcamento(valOrcamento);
  setBoleto(valDataVencimento);
  this->cartaoDeCredito = nullptr;
  this->setVenda();
}

PedidoDeCompra::PedidoDeCompra(Orcamento *valOrcamento, CartaoDeCredito *valCartaoDeCredito, int parcelas){
  setOrcamento(valOrcamento);
  double valorTotal = 0.0, precoDoProduto = 0.0;
  for(auto it : this->orcamento->getItens()){
        for(auto it2 : Produto::produtolist){
            if(it.first == it2->getNome()){
                precoDoProduto = it2->getValorDeVenda();
                break;
            }
        }
        valorTotal += valorTotal + it.second*precoDoProduto;
    }
    double valorParcela = valorTotal/parcelas;
    valCartaoDeCredito->setQuantidadeDeParcelas(parcelas);
    valCartaoDeCredito->setQuantiaPorParcelas(valorParcela);
    this->boleto = nullptr;
    setCartaoDeCredito(valCartaoDeCredito);
    PedidoDeCompra::contPedidos++;
    this->codigo = contPedidos;
    this->setVenda();
}
int PedidoDeCompra::getCodigo(){
    return this->codigo;
}
PedidoDeCompra::~PedidoDeCompra() {
}

void PedidoDeCompra::setOrcamento(Orcamento *valOrcamento){
    orcamento = valOrcamento;
}

void PedidoDeCompra::setBoleto(Data valDataVencimento){
    double valorTotal = 0.0, precoDoProduto = 0.0;
    for(auto it : this->orcamento->getItens()){
        for(auto it2 : Produto::produtolist){
            if(it.first == it2->getNome()){
                precoDoProduto = it2->getValorDeVenda();
                break;
            }
        }
        valorTotal += valorTotal + it.second*precoDoProduto;
    }
    Boleto *novoBoleto = new Boleto(1, valDataVencimento, valorTotal);
}

void PedidoDeCompra::setCartaoDeCredito(CartaoDeCredito *valCartaoDeCredito){
    cartaoDeCredito = valCartaoDeCredito;
}

Orcamento* PedidoDeCompra::getOrcamento(){
    return orcamento;
}

Boleto* PedidoDeCompra::getBoleto(){
    return boleto;
}

CartaoDeCredito* PedidoDeCompra::getCartaoDeCredito(){
    return cartaoDeCredito;
}

void PedidoDeCompra::setVenda(){
    for(auto it : orcamento->getItens()){
        for(auto it2 : Produto::produtolist){
            if(it.first == it2->getNome()){
                this->vendaRealizada = it2->temEstoque(int(it.second));
                if(vendaRealizada){
                    RegistroVendas *venda = new RegistroVendas(Data::dataDeHoje, it2, int(it.second), orcamento->getCliente());
                    venda->setCodigoPedido(this->codigo);
                }
            }
        }
    }
}