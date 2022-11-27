#include "../include/Orcamento.h"
#include "../include/Empresa.h"
#include "../include/PermissaoNegada.h"

void Orcamento::auxiliarMateriaPrima(){
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.auxiliarMateriaPrima"))
  {
    PermissaoNegada *a = new PermissaoNegada("auxiliarMateriaPrima", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.auxiliarMateriaPrima";
    throw mensagem;
  }
  else
  {
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
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.auxiliarProduto"))
  {
    PermissaoNegada *a = new PermissaoNegada("auxiliarProduto", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.auxiliarProduto";
    throw mensagem;
  }
  else
  {
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
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.Orcamento"))
  {
    PermissaoNegada *a = new PermissaoNegada("Orcamento", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.Orcamento";
    throw mensagem;
  }
  else
  {
    this->dataOrcamento = Data();
    this->cliente = nullptr;
    this->fornecedor = nullptr;
    this->compraDeProduto = false;
    this->valorTotal = 0.0;
    LogEscrita *a = new LogEscrita("valorTotal", "indefinido", to_string(valorTotal), "Orcamento");
  }
}

Orcamento::Orcamento(bool isCompraDeProduto, vector<pair<string, double>> valItens, Data valData, Cliente* valCliente){
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.Orcamento"))
  {
    PermissaoNegada *a = new PermissaoNegada("Orcamento", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.Orcamento";
    throw mensagem;
  }
  else
  {
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
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.Orcamento"))
  {
    PermissaoNegada *a = new PermissaoNegada("Orcamento", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.Orcamento";
    throw mensagem;
  }
  else
  {
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
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.setTotal"))
  {
    PermissaoNegada *a = new PermissaoNegada("setTotal", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.setTotal";
    throw mensagem;
  }
  else
  {
    double valor = 0.0;
    for (auto it : this->precos){
        valor = valor + it.second;
    }
    this->valorTotal = valor;
    LogEscrita *c = new LogEscrita("valorTotal", "indefinido", to_string(valorTotal), "Orcamento");
  } 
}

vector<pair<string, double>> Orcamento::getPrecos() {

  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getPrecos"))
  {
    PermissaoNegada *a = new PermissaoNegada("getPrecos", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.getPrecos";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("precos", "Orcamento");
    return this->precos;
  }
}

void Orcamento::setCompraDeProduto(bool compraDeProduto){
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.setCompraDeProduto"))
  {
    PermissaoNegada *a = new PermissaoNegada("setCompraDeProduto", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.setCompraDeProduto";
    throw mensagem;
  }
  else
  {
    this->compraDeProduto = compraDeProduto;
    LogEscrita *c = new LogEscrita("compraDeProduto", "indefinido", to_string(compraDeProduto), "Orcamento");
  }
}

bool Orcamento::isCompraDeProduto() {
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.isCompraDeProduto"))
  {
    PermissaoNegada *a = new PermissaoNegada("isCompraDeProduto", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.isCompraDeProduto";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("compraDeProduto", "Orcamento");
    return this->compraDeProduto;
  }
}

double Orcamento::getPreco(string valItem) {
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getPreco"))
  {
    PermissaoNegada *a = new PermissaoNegada("getPreco", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.getPreco";
    throw mensagem;
  }
  else
  {
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
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.setDataOrcamento"))
  {
    PermissaoNegada *a = new PermissaoNegada("setDataOrcamento", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.setDataOrcamento";
    throw mensagem;
  }
  else
  {
    LogEscrita *c = new LogEscrita("dataOrcamento", "indefinido", valData.getData(), "Orcamento");
    this->dataOrcamento = valData;
  }
}

Data Orcamento::getDataOrcamento() {
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getDataOrcamento"))
  {
    PermissaoNegada *a = new PermissaoNegada("getDataOrcamento", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.getDataOrcamento";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("dataOrcamento", "Orcamento");
    return this->dataOrcamento;
  }
}

Fornecedor* Orcamento::getFornecedor() {
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getFornecedor"))
  {
    PermissaoNegada *a = new PermissaoNegada("getFornecedor", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.getFornecedor";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("fornecedor", "Orcamento");
    return this->fornecedor;
  }
}

void Orcamento::setCliente(Cliente* valCliente) {

  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.setCliente"))
  {
    PermissaoNegada *a = new PermissaoNegada("setCliente", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.setCliente";
    throw mensagem;
  }
  else
  {
    this->cliente = valCliente;
    LogEscrita *c = new LogEscrita("cliente", "indefinido", valCliente->getNome(), "Orcamento");
  }
}

Cliente* Orcamento::getCliente() {
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getCliente"))
  {
    PermissaoNegada *a = new PermissaoNegada("getCliente", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.getCliente";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("cliente", "Orcamento");
    return this->cliente;
  }
}

double Orcamento::getValorTotal() {
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getValorTotal"))
  {
    PermissaoNegada *a = new PermissaoNegada("getValorTotal", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.getValorTotal";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("valorTotal", "Orcamento");
    return this->valorTotal;
  }
}

vector<pair<string, double>> Orcamento::getItens(){
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.getItens"))
  {
    PermissaoNegada *a = new PermissaoNegada("getItens", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.getItens";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("itens", "Orcamento");
    return this->itens;
  }
}

void Orcamento::setFornecedor(Fornecedor * valFornecedor){
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.setFornecedor"))
  {
    PermissaoNegada *a = new PermissaoNegada("setFornecedor", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.setFornecedor";
    throw mensagem;
  }
  else
  {
    this->fornecedor = valFornecedor;
    LogEscrita *c = new LogEscrita("fornecedor", "indefinido", fornecedor->getNome(), "Orcamento");
  }
}

void Orcamento::setItens(vector<pair<string, double>> valItens){
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Orcamento.setItens"))
  {
    PermissaoNegada *a = new PermissaoNegada("setItens", "Orcamento");
    string mensagem = "Acesso negado a Orcamento.setItens";
    throw mensagem;
  }
  else
  {
    this->itens = valItens;
  }
}