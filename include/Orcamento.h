#ifndef ORCAMENTO_H_INCLUDED
#define ORCAMENTO_H_INCLUDED

#include "Cliente.h"
#include "Produto.h"

#include "data.h"
#include <utility>
#include <vector>
#include <iostream>

class Orcamento {
private:
  vector<Produto*> produtos;
  Data data;
  Cliente cliente;
  float valorTotal;
  vector<pair<Produto*, float>> historico;

public:
  Orcamento();
  Orcamento(Cliente cliente, Data data);
  vector <Produto*> getProduto();
  int getQuantidade(string nomeDoProduto);
  Data getData();
  Cliente getCliente();
  float getValorTotal();

  void setProduto(Produto* produto);
  void setData(Data data);
  void setCliente(Cliente cliente);

  void listagemDeProdutos();
  void realizaOrcamento();
};

#endif
