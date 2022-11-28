#ifndef ORCAMENTO_H_INCLUDED
#define ORCAMENTO_H_INCLUDED

#include "Cliente.h"
#include "Produto.h"
#include "MateriaPrima.h"
#include "Fornecedor.h"
#include "UsuarioLogado.h"
#include "data.h"
#include <utility>
#include <vector>
#include <iostream>

class Orcamento {
private:
  bool compraDeProduto;
  vector<pair<string, double>> itens;
  Data dataOrcamento;
  Cliente* cliente;
  Fornecedor* fornecedor;
  double valorTotal;
  int quantidadeProduto;
  vector<pair<string, double>> precos;
  
public:
  Orcamento();
  Orcamento(bool isCompraDeProduto, vector<pair<string, double>> valItens, Data valData, Fornecedor* valFornecedor);
  Orcamento(bool isCompraDeProduto, vector<pair<string, double>> valItens, Data valData, Cliente* valCliente);
  vector<pair<string, double>> getPrecos();
  double getValorTotal();
  Cliente* getCliente();
  Fornecedor* getFornecedor();
  vector<pair<string, double>> getItens();
  bool isCompraDeProduto();
  Data getDataOrcamento();
  double getPreco(string valItem);

  void setItens(vector<pair<string, double>> valItens);
  void setTotal();
  void setCliente(Cliente* valCliente);
  void setCompraDeProduto(bool compraDeProduto);
  void auxiliarMateriaPrima();
  void auxiliarProduto();
  void setFornecedor(Fornecedor* valFornecedor);
  void setDataOrcamento(Data valData);
};

#endif