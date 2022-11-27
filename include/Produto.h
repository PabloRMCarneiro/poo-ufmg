#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED
#include <vector>
#include "Lote.h"
#include "Categoria.h"
#include "OrdemDeProducao.h"
#include "MateriaPrima.h"

using namespace std;

class Produto {
  private:
    string nome;
    int codigo;
    float valorDeVenda;
    Categoria* categoria;
    vector <Lote*> lotes;
    int tamanhoDoLoteMinimo;
    int estoqueMinimo;
    int qtdEstoque;
    OrdemDeProducao* ordem;
    vector<pair<MateriaPrima*, double>> materiaPrimaList;
  public:
    Produto(string nome, int codigo, float valorDeVenda, int tamanhoDoLoteMinimo, int estoqueMinimo, int qtdEstoque, string categ);
    Produto();
    ~Produto();

    vector<pair<MateriaPrima*, double>> getMateriaPrimaList();
    string getNome();
    int getCodigo();
    float getValorDeVenda();
    int getTamanhoDoLoteMinimo();
    int getEstoqueMinimo();
    int getQtdEstoque();
    Categoria* getCategoria();
    OrdemDeProducao* getOrdem();
    Lote* getLote(int nl);

    void alteraPreco(double alteracao);
    void setMateriaPrimaList(vector<pair<MateriaPrima*, double>> valMateriaPrimaList);
    void setNome(string nome);
    void setCodigo(int codigo);
    void setValorDeVenda(float valorDeVenda);
    void setTamanhoDoLoteMinimo(int tamanhoDoLoteMinimo);
    void setEstoqueMinimo(int estoqueMinimo);
    void setQtdEstoque(int qtdEstoque);
    void setCategoria(string categ);

    void registraLote(int numeroLote, Data dataDeProducao);
    pair<int, int> realizaVenda(int quantidade, Data venda);
    void geraOrdem(Data dataQuandoAcabaEstoque);
    bool temEstoque(int q);
    
    static vector <Produto*> produtolist;
    static void novoProduto(Produto* novo);
    static Produto* getProduto(string n);
};

#endif