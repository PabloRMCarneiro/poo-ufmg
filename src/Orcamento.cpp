#include "../include/Orcamento.h"
#include "../include/Empresa.h"

Orcamento::Orcamento() {
  if (!Empresa::getEmpresa()->getAcesso("Orcamento.Orcamento")) {
    throw "Acesso negado a Orcamento.Orcamento";
  } else {
    this->data = Data();
    this->cliente = Cliente();
    this->historico = vector<pair<Produto*, float>>();
  }
}

Orcamento::Orcamento(Cliente cliente, Data data){
  if (!Empresa::getEmpresa()->getAcesso("Orcamento.Orcamento")) {
    throw "Acesso negado a Orcamento.Orcamento";
  } else {
    this->data = data;
    this->cliente = cliente;
    this->valorTotal = 0;
  }
}

vector<Produto*> Orcamento::getProduto() {
  if (!Empresa::getEmpresa()->getAcesso("Orcamento.getProduto")) {
    throw "Acesso negado a Orcamento.getProduto";
  } else {
    return this->produtos;
  }
}

int Orcamento::getQuantidade(string nomeDoProduto) {
  if (!Empresa::getEmpresa()->getAcesso("Orcamento.getQuantidade")) {
    throw "Acesso negado a Orcamento.getQuantidade";
  } else {
    this->listagemDeProdutos();
    for (int i = 0; i < this->historico.size(); i++) {
      if (this->historico[i].first->getNome() == nomeDoProduto) {
        return this->historico[i].second;
      }
    }
    return 0;
  }
}

Data Orcamento::getData() {
  if (!Empresa::getEmpresa()->getAcesso("Orcamento.getData")) {
    throw "Acesso negado a Orcamento.getData";
  } else {
    return this->data;
  }
}

Cliente Orcamento::getCliente() {
  if (!Empresa::getEmpresa()->getAcesso("Orcamento.getCliente")) {
    throw "Acesso negado a Orcamento.getCliente";
  } else {
    return this->cliente;
  }
}

float Orcamento::getValorTotal() {
  if (!Empresa::getEmpresa()->getAcesso("Orcamento.getValorTotal")) {
    throw "Acesso negado a Orcamento.getValorTotal";
  } else {
    return this->valorTotal;
  }
}

void Orcamento::setProduto(Produto* produto) {
  if (!Empresa::getEmpresa()->getAcesso("Orcamento.setProduto")) {
    throw "Acesso negado a Orcamento.setProduto";
  } else {
    this->produtos.push_back(produto);
  }
}

void Orcamento::setData(Data data) {
  if (!Empresa::getEmpresa()->getAcesso("Orcamento.setData")) {
    throw "Acesso negado a Orcamento.setData";
  } else {
    this->data = data;
  }
}

void Orcamento::setCliente(Cliente cliente) {
  if (!Empresa::getEmpresa()->getAcesso("Orcamento.setCliente")) {
    throw "Acesso negado a Orcamento.setCliente";
  } else {
    this->cliente = cliente;
  }
}

/* void Orcamento::listagemDeProdutos(){
    if(!Empresa::getEmpresa()->getAcesso("Orcamento.listagemDeProdutos"))
    {
        throw "Acesso negado a Orcamento.listagemDeProdutos";
    }
    else
    {
        for(int i = 0; i < this->produtos.size(); i++){
            cout << this->produtos[i].getNome() << endl;
        }
    }
} */

void Orcamento::listagemDeProdutos() {
  if (!Empresa::getEmpresa()->getAcesso("Orcamento.listagemDeProdutos")) {
    throw "Acesso negado a Orcamento.listagemDeProdutos";
  } else {
    for (int i = 0; i < this->produtos.size(); i++) {
      int cont = 0;
      for (int j = 0; j < this->produtos.size(); j++) {
        if (this->produtos[i]->getNome() == this->produtos[j]->getNome()) {
          cont++;
        }
      }
      for (int k = 0; k < this->historico.size(); k++) {
        if (this->produtos[i]->getNome() == this->historico[k].first->getNome()) {
          cont = 0;
        }
      }
      if (cont != 0) {
        this->historico.push_back(make_pair(this->produtos[i], cont));
      }
    }
  }
}

void Orcamento::realizaOrcamento(){
  if (!Empresa::getEmpresa()->getAcesso("Orcamento.realizaOrcamento")) {
    throw "Acesso negado a Orcamento.realizaOrcamento";
  } else {
    this->listagemDeProdutos();
    this->valorTotal = 0;
    cout <<"Produto - Quantidade - Valor Unitário" << endl;
    for (int i = 0; i < this->historico.size(); i++) {
      this->valorTotal += this->historico[i].first->getValorDeVenda() * this->historico[i].second;
    }
    for(int i = 0; i < this->historico.size(); i++) {
      cout << this->historico[i].first->getNome() << " - " << this->historico[i].second << " - R$ " << this->historico[i].first->getValorDeVenda() << endl;
    }
    cout << "Valor total: R$ " << this->valorTotal << endl;
  }
  
}