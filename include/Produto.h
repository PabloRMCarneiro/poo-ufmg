#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED
#include <string>
#include <vector>
#include "../include/data.h"
/* #include "../include/Categoria.h"
#include "../include/Lote.h" */

using namespace std;

class Produto {

  private:
    string nome;
    int codigo;
    float valorDeVenda;
    /*Categoria categoria;*/
    /* vector <Lote*> lotes;*/
    int tamanhoDoLoteMinimo;
    int estoqueMinimo;
    int qtdEstoque;
    Data ordemDeProducao;

  public:
    Produto(string nome, int codigo, float valorDeVenda, int tamanhoDoLoteMinimo, int estoqueMinimo, int qtdEstoque, Data ordemDeProducao);
    Produto();
    ~Produto();

    string getNome();
    int getCodigo();
    float getValorDeVenda();
    int getTamanhoDoLoteMinimo();
    int getEstoqueMinimo();
    int getQtdEstoque();
    /*Categoria* getCategoria()*/
    Data getOrdemDeProducao();

    void setNome(string nome);
    void setCodigo(int codigo);
    void setValorDeVenda(float valorDeVenda);
    void setTamanhoDoLoteMinimo(int tamanhoDoLoteMinimo);
    void setEstoqueMinimo(int estoqueMinimo);
    void setQtdEstoque(int qtdEstoque);
    void setOrdemDeProducao(Data ordemDeProducao);
    void setCategoria(string);

    void registraLote(int quantidade, Data dataDeProducao, int quantidadeProduzida, string nomeDoProduto);
    void realizaVenda(int quantidade);
    void geraOrdemDeProducao(Data dataQuandoAcabaEstoque);

    bool temEstoque();

};

#endif