#include "../include/Produto.h"
vector <Produto*> Produto::produtolist;
Produto::Produto()
{
  // this->nome = "";
  // this->codigo = 0;
  // this->valorDeVenda = 0;
  // this->tamanhoDoLoteMinimo = 0;
  // this->estoqueMinimo = 0;
  // this->qtdEstoque = 0;
  // this->ordemDeProducao = Data();
  this->novoProduto(this);
}

Produto::Produto(string nome, int codigo, float valorDeVenda, int tamanhoDoLoteMinimo, int estoqueMinimo, int qtdEstoque, string categ)
{
  this->nome = nome;
  this->codigo = codigo;
  this->valorDeVenda = valorDeVenda;
  this->tamanhoDoLoteMinimo = tamanhoDoLoteMinimo;
  this->estoqueMinimo = estoqueMinimo;
  this->qtdEstoque = qtdEstoque;
  this->setCategoria(categ);
  //this->ordemDeProducao();
  this->novoProduto(this);
}

Produto::~Produto()
{
}

string Produto::getNome()
{
  return this->nome;
}

int Produto::getCodigo()
{
  return this->codigo;
}

float Produto::getValorDeVenda()
{
  return this->valorDeVenda;
}

int Produto::getTamanhoDoLoteMinimo()
{
  return this->tamanhoDoLoteMinimo;
}

int Produto::getEstoqueMinimo()
{
  return this->estoqueMinimo;
}

int Produto::getQtdEstoque()
{
  return this->qtdEstoque;
}
string Produto::getCategoria(){
  return categoria->getTipo();
}
OrdemDeProducao* Produto::getOrdem()
{
  return &this->ordem;
}
Lote* Produto::getLote(int nl){
  for(auto it : lotes){
    if(it->getNumLote() == nl){
      return it;
    }
  }
  return nullptr;
}



void Produto::setNome(string nome)
{
  this->nome = nome;
}

void Produto::setCodigo(int codigo)
{
  this->codigo = codigo;
}

void Produto::setValorDeVenda(float valorDeVenda)
{
  this->valorDeVenda = valorDeVenda;
}

void Produto::setTamanhoDoLoteMinimo(int tamanhoDoLoteMinimo)
{
  this->tamanhoDoLoteMinimo = tamanhoDoLoteMinimo;
}

void Produto::setEstoqueMinimo(int estoqueMinimo)
{
  this->estoqueMinimo = estoqueMinimo;
}

void Produto::setQtdEstoque(int qtdEstoque)
{
  this->qtdEstoque = qtdEstoque;
}
void Produto::setCategoria(string categ){
  if(Categoria::getCategoria(categ) != nullptr){
    this->setCategoria(categ);
  }else {
    this->categoria = new Categoria(categ);
  }
}
void Produto::registraLote(int numeroLote, Data dataDeProducao){
  this->lotes.push_back(new Lote(dataDeProducao, numeroLote, this->tamanhoDoLoteMinimo, this->nome));
  this->qtdEstoque += this->tamanhoDoLoteMinimo;
}
pair<int, int> Produto::realizaVenda(int quantidade, Data venda)
{
  int lote, faltaVender;
  for(auto it : this->lotes){
    if(it->getQuantidadeAtual() > 0){
      lote = it->getNumLote();
      faltaVender = it->vende(quantidade);
      this->qtdEstoque-=(quantidade-faltaVender);
      break;
    }
  }
  if(this->qtdEstoque < this->estoqueMinimo){
    geraOrdem(venda);
  }
  return make_pair(lote, faltaVender);
}

void Produto::geraOrdem(Data dataQuandoAcabaEstoque)
{ 
  this->ordem = OrdemDeProducao(dataQuandoAcabaEstoque, this->nome, this->tamanhoDoLoteMinimo);
}

bool Produto::temEstoque(int q)
{
  return (this->qtdEstoque >= q);
}
void Produto::novoProduto(Produto* novo){
  produtolist.push_back(novo);
}
Produto* Produto::getProduto(string n){
  for(auto it : produtolist){
    if(it->getNome() == n){
      return it;
    }
  }
  return nullptr;
}