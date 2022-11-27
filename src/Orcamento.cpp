#include "../include/Orcamento.h"
#include "../include/Empresa.h"

void Orcamento::auxiliarMateriaPrima(){
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.auxiliarMateriaPrima")) {
    throw "Acesso negado a Orcamento.auxiliarMateriaPrima";
  } else {
    double preco = 0.0;
    for(auto itItens : this->getItens()){
        for(auto itMateriaPrima : this->getFornecedor()->getPrecos()){
            if(itMateriaPrima.first->getNome() == itItens.first){
                preco = itMateriaPrima.second*itItens.second;
                this->precos.push_back(make_pair(itItens.first, preco));
            }
        }
    }
  }
  this->setTotal();
}

void Orcamento::auxiliarProduto(){
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.auxiliarProduto")) {
    throw "Acesso negado a Orcamento.auxiliarProduto";
  } else {
    double preco = 0.0;
    for(auto itItens : this->getItens()){
        for(auto itProduto : Produto::produtolist){
            if(itProduto->getNome() == itItens.first){
                preco = itProduto->getValorDeVenda()*itItens.second;
                this->precos.push_back(make_pair(itItens.first, preco));
            }
        }
    }
  }
  LogLeitura *a = new LogLeitura("produtolist", "Produto");
  this->setTotal();
}

Orcamento::Orcamento() {
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.Orcamento")) {
    throw "Acesso negado a Orcamento.Orcamento";
  } else {
    this->dataOrcamento = Data();
    this->cliente = nullptr;
    this->fornecedor = nullptr;
    this->compraDeProduto = false;
    this->valorTotal = 0.0;
    LogEscrita *a = new LogEscrita("valorTotal", "indefinido", to_string(valorTotal), "Orcamento");
  }
}

Orcamento::Orcamento(bool isCompraDeProduto, vector<pair<string, double>> valItens, Data valData, Cliente* valCliente){
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.Orcamento")) {
    throw "Acesso negado a Orcamento.Orcamento";
  } else {
    this->dataOrcamento = valData;
    LogEscrita *a = new LogEscrita("dataOrcamento", "indefinido", valData.getData(), "Orcamento");
    this->itens = valItens;
    this->cliente = valCliente;
    LogEscrita *b = new LogEscrita("cliente", "indefinido", cliente->getNome(), "Orcamento");
    this->fornecedor = nullptr;
    this->compraDeProduto = isCompraDeProduto;
    LogEscrita *c = new LogEscrita("compraDeProduto", "indefinido", to_string(isCompraDeProduto), "Orcamento");
    this->valorTotal = 0.0;
    LogEscrita *d = new LogEscrita("valorTotal", "indefinido", to_string(valorTotal), "Orcamento");
    this->auxiliarProduto();
  }
}


Orcamento::Orcamento(bool isCompraDeProduto, vector<pair<string, double>> valItens, Data valData, Fornecedor* valFornecedor){
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.Orcamento")) {
    throw "Acesso negado a Orcamento.Orcamento";
  } else {
    this->dataOrcamento = valData;
    LogEscrita *a = new LogEscrita("dataOrcamento", "indefinido", valData.getData(), "Orcamento");
    this->itens = valItens;
    this->cliente = nullptr;
    this->fornecedor = valFornecedor;
    LogEscrita *b = new LogEscrita("fornecedor", "indefinido", fornecedor->getNome(), "Orcamento");
    this->compraDeProduto = isCompraDeProduto;
    LogEscrita *c = new LogEscrita("compraDeProduto", "indefinido", to_string(isCompraDeProduto), "Orcamento");
    this->valorTotal = 0.0;
    LogEscrita *d = new LogEscrita("valorTotal", "indefinido", to_string(valorTotal), "Orcamento");
    this->auxiliarMateriaPrima();
  }
}

void Orcamento::setTotal(){
    if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.setTotal")) {
    throw "Acesso negado a Orcamento.setTotal";
  } else {
    double valor = 0.0;
    for (auto it : this->precos){
        valor = valor + it.second;
    }
    this->valorTotal = valor;
    LogEscrita *c = new LogEscrita("valorTotal", "indefinido", to_string(valorTotal), "Orcamento");
  } 
}

vector<pair<string, double>> Orcamento::getPrecos() {
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getPrecos")) {
    throw "Acesso negado a Orcamento.getPrecos";
  } else {
    LogLeitura *a = new LogLeitura("precos", "Orcamento");
    return this->precos;
  }
}

void Orcamento::setCompraDeProduto(bool compraDeProduto){
    if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.setCompraDeProduto")) {
    throw "Acesso negado a Orcamento.setCompraDeProduto";
  } else {
    this->compraDeProduto = compraDeProduto;
    LogEscrita *c = new LogEscrita("compraDeProduto", "indefinido", to_string(compraDeProduto), "Orcamento");
  }
}

bool Orcamento::isCompraDeProduto() {
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.isCompraDeProduto")) {
    throw "Acesso negado a Orcamento.isCompraDeProduto";
  } else {
    LogLeitura *a = new LogLeitura("compraDeProduto", "Orcamento");
    return this->compraDeProduto;
  }
}

double Orcamento::getPreco(string valItem) {
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getPreco")) {
    throw "Acesso negado a Orcamento.getPreco";
  } else {
    int a =0;
    for(auto it : this->getPrecos()){
        if(it.first == valItem){
            a = 1;
            return it.second;
        }
    }
    if(a != 1){
        throw "Item nao encontrado.";
    }
    return 0.0;
  }
}

void Orcamento::setDataOrcamento(Data valData) {
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.setDataOrcamento")) {
    throw "Acesso negado a Orcamento.setDataOrcamento";
  } else {
    LogEscrita *c = new LogEscrita("dataOrcamento", "indefinido", valData.getData(), "Orcamento");
    this->dataOrcamento = valData;
  }
}

Data Orcamento::getDataOrcamento() {
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getDataOrcamento")) {
    throw "Acesso negado a Orcamento.getDataOrcamento";
  } else {
    LogLeitura *a = new LogLeitura("dataOrcamento", "Orcamento");
    return this->dataOrcamento;
  }
}

Fornecedor* Orcamento::getFornecedor() {
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getFornecedor")) {
    throw "Acesso negado a Orcamento.getFornecedor";
  } else {
    LogLeitura *a = new LogLeitura("fornecedor", "Orcamento");
    return this->fornecedor;
  }
}

void Orcamento::setCliente(Cliente* valCliente) {
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.setCliente")) {
    throw "Acesso negado a Orcamento.setCliente";
  } else {
    this->cliente = valCliente;
    LogEscrita *c = new LogEscrita("cliente", "indefinido", valCliente->getNome(), "Orcamento");
  }
}

Cliente* Orcamento::getCliente() {
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getCliente")) {
    throw "Acesso negado a Orcamento.getCliente";
  } else {
    LogLeitura *a = new LogLeitura("cliente", "Orcamento");
    return this->cliente;
  }
}

double Orcamento::getValorTotal() {
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getValorTotal")) {
    throw "Acesso negado a Orcamento.getValorTotal";
  } else {
    LogLeitura *a = new LogLeitura("valorTotal", "Orcamento");
    return this->valorTotal;
  }
}

vector<pair<string, double>> Orcamento::getItens(){
  if(false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getItens")) {
    throw "Acesso negado a Orcamento.getItens";
  } else {
    LogLeitura *a = new LogLeitura("itens", "Orcamento");
    return this->itens;
  }
}

void Orcamento::setFornecedor(Fornecedor * valFornecedor){
  if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.setFornecedor")) {
    throw "Acesso negado a Orcamento.setFornecedor";
  } else {
    this->fornecedor = fornecedor;
    LogEscrita *c = new LogEscrita("fornecedor", "indefinido", fornecedor->getNome(), "Orcamento");
  }
}

void Orcamento::setItens(vector<pair<string, double>> valItens){
    if (false){//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.setItens")) {
    throw "Acesso negado a Orcamento.setItens";
  } else {
    this->itens = valItens;
  }
}