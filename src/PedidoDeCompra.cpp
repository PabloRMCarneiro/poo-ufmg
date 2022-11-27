#include "../include/PedidoDeCompra.h"
#include "../include/PermissaoNegada.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"
// LogEscrita *a = new LogEscrita("tipoCliente", "indefinido", this->tipoCliente, "Lote");
// LogLeitura *a = new LogLeitura("tipoCliente", "Lote");
int PedidoDeCompra::contPedidos = 0;

PedidoDeCompra::PedidoDeCompra() {}

PedidoDeCompra::PedidoDeCompra(Orcamento *valOrcamento, Data valDataVencimento){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("PedidoDeCompra.PedidoDeCompra"))
  {
    PermissaoNegada *a = new PermissaoNegada("PedidoDeCompra", "PedidoDeCompra");
    string mensagem = "Acesso negado a PedidoDeCompra.PedidoDeCompra";
    throw mensagem;
  }
  else
  {
    PedidoDeCompra::contPedidos++;
    this->codigo = contPedidos;
    setOrcamento(valOrcamento);
    setBoleto(valDataVencimento);
    this->cartaoDeCredito = nullptr;
    this->setVenda();
  }
}

PedidoDeCompra::PedidoDeCompra(Orcamento *valOrcamento, CartaoDeCredito *valCartaoDeCredito, int parcelas){
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("PedidoDeCompra.PedidoDeCompra"))
    {
        PermissaoNegada *a = new PermissaoNegada("PedidoDeCompra", "PedidoDeCompra");
        string mensagem = "Acesso negado a PedidoDeCompra.PedidoDeCompra";
        throw mensagem;
    }
    else
    {
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
  
}
int PedidoDeCompra::getCodigo(){

    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("PedidoDeCompra.getCodigo"))
    {
        PermissaoNegada *a = new PermissaoNegada("getCodigo", "PedidoDeCompra");
        string mensagem = "Acesso negado a PedidoDeCompra.getCodigo";
        throw mensagem;
    }
    else
    {
        return this->codigo;
    }
}
PedidoDeCompra::~PedidoDeCompra() {
}

void PedidoDeCompra::setOrcamento(Orcamento *valOrcamento){
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("PedidoDeCompra.setOrcamento"))
    {
        PermissaoNegada *a = new PermissaoNegada("setOrcamento", "PedidoDeCompra");
        string mensagem = "Acesso negado a PedidoDeCompra.setOrcamento";
        throw mensagem;
    }
    else
    {
        this->orcamento = valOrcamento;
    }
}

void PedidoDeCompra::setBoleto(Data valDataVencimento){
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("PedidoDeCompra.setBoleto"))
    {
        PermissaoNegada *a = new PermissaoNegada("setBoleto", "PedidoDeCompra");
        string mensagem = "Acesso negado a PedidoDeCompra.setBoleto";
        throw mensagem;
    }
    else
    {
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
}

void PedidoDeCompra::setCartaoDeCredito(CartaoDeCredito *valCartaoDeCredito){
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("PedidoDeCompra.setCartaoDeCredito"))
    {
        PermissaoNegada *a = new PermissaoNegada("setCartaoDeCredito", "PedidoDeCompra");
        string mensagem = "Acesso negado a PedidoDeCompra.setCartaoDeCredito";
        throw mensagem;
    }
    else
    {
        cartaoDeCredito = valCartaoDeCredito;
    }
}

Orcamento* PedidoDeCompra::getOrcamento(){
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("PedidoDeCompra.getOrcamento"))
    {
        PermissaoNegada *a = new PermissaoNegada("getOrcamento", "PedidoDeCompra");
        string mensagem = "Acesso negado a PedidoDeCompra.getOrcamento";
        throw mensagem;
    }
    else
    {
        return orcamento;
    }
}

Boleto* PedidoDeCompra::getBoleto(){
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("PedidoDeCompra.getBoleto"))
    {
        PermissaoNegada *a = new PermissaoNegada("getBoleto", "PedidoDeCompra");
        string mensagem = "Acesso negado a PedidoDeCompra.getBoleto";
        throw mensagem;
    }
    else
    {
        return boleto;
    }
}

CartaoDeCredito* PedidoDeCompra::getCartaoDeCredito(){
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("PedidoDeCompra.getCartaoDeCredito"))
    {
        PermissaoNegada *a = new PermissaoNegada("getCartaoDeCredito", "PedidoDeCompra");
        string mensagem = "Acesso negado a PedidoDeCompra.getCartaoDeCredito";
        throw mensagem;
    }
    else
    {
        return cartaoDeCredito;
    }
}

void PedidoDeCompra::setVenda(){
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("PedidoDeCompra.setVenda"))
    {
        PermissaoNegada *a = new PermissaoNegada("setVenda", "PedidoDeCompra");
        string mensagem = "Acesso negado a PedidoDeCompra.setVenda";
        throw mensagem;
    }
    else
    {
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
}