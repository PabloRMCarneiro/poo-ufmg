#ifndef ORCAMENTO_H_INCLUDED
#define ORCAMENTO_H_INCLUDED

#include "Cliente.h"
#include "Produto.h"
#include "Fornecedor.h"

#include "data.h"
#include <utility>
#include <vector>
#include <iostream>
// + setOrçamento() : void
// + auxiliarMateriaPrima() : void
// + auxiliarProduto() : void
// + setItens(vector <string>) : void
// + setTotal(double) : void
// + setCliente(Cliente*) : void
// + setCompraDeProduto(bool) : void

// + getPreços() : vector<pair<string, double>>
// + getTotal() : double
// + getCliente() : Cliente*
// + getFornecedor() : Fornecedor*
// + getItens() : vector<string>
// + isCompraDeProduto() : bool
// + getData() : Data
// + getPreço(string) : double

// + Orçamento()
class Orcamento {
private:
  bool compraDeProduto;
  vector<string> itens;
  Data dataOrçamento;
  Cliente* cliente;
  Fornecedor* fornecedor;
  double valorvalor;
  vector<pair<string, float>> preços;
  
public:
  Orcamento();
  Orcamento(bool isCompraDeProduto, vector<string> valItens, Data valData);
  //
  vector<pair<string, double>> getPreços();
  double getValorTotal();
  Cliente* getCliente();
  Fornecedor* getFornecedor();
  vector<string> getItens();
  bool isCompraDeProduto();
  Data getDataOrcamento();
  double getPreço(string valItem);

  void setOrcamento();
  void setItens(vector <string> valItens);
  void setTotal(double valTotal);
  void setCliente(Cliente* valCliente);
  void setCompraDeProduto(bool compraDeProduto);
  void auxiliarMateriaPrima();
  void auxiliarProduto();
  void setFornecedor(Fornecedor* valFornecedor);
  void setData(Data valData);
  void setCliente(Cliente valCliente);

};

#endif
