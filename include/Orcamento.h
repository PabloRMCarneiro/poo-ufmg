#ifndef ORCAMENTO_H_INCLUDED
#define ORCAMENTO_H_INCLUDED

#include "Cliente.h"
#include "Produto.h"
#include "Fornecedor.h"

#include "data.h"
#include <utility>
#include <vector>
#include <iostream>

class Orcamento {
private:
  vector<Produto*> produtos;
  Data data;
  Cliente* cliente;
  Fornecedor* fornecedor;
  float valorTotal;
  vector<pair<Produto*, float>> historicoProduto;
  vector<MateriaPrima*> materiaPrimaLista;
  vector<pair<MateriaPrima*, double>> historicoMateriaPrimaLista;

public:
  Orcamento();
  Orcamento(Cliente cliente, Data data);
  vector <Produto*> getProduto();
  int getQuantidade(string nomeDoProduto);
  Data getData();
  Cliente getCliente();
  float getValorTotal();
  vector<MateriaPrima*> getMateriaPrimaLista(); // falta implementar
  vector<pair<MateriaPrima*, double>> getHistoricoMateriaPrima(); // falta implementar
  Fornecedor *getFornecedor(); // falta implementar

  void setFornecedor(Fornecedor* valFornecedor); // falta implementar
  void setMateriaPrimaLista(vector<MateriaPrima*>); // falta implementar
  void setProduto(Produto* produto);
  void setData(Data data);
  void setCliente(Cliente cliente);

  void listagemDeProdutos();
  void realizaOrcamento();
};

#endif
