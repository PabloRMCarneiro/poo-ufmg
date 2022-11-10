#include "../include/Produto.h"
#include "../include/Empresa.h"

vector <Produto*> Produto::produtolist;
Produto::Produto()
{
  if(!Empresa::getEmpresa()->getAcesso("Produto.Produto"))
  {
    throw "Acesso negado - Produto";
  }
  else
  {
    this->nome = "";
    this->codigo = 0;
    this->valorDeVenda = 0;
    this->tamanhoDoLoteMinimo = 0;
    this->estoqueMinimo = 0;
    this->qtdEstoque = 0;
    this->categoria = new Categoria();
    this->novoProduto(this);
  }
}

Produto::Produto(string nome, int codigo, float valorDeVenda, int tamanhoDoLoteMinimo, int estoqueMinimo, int qtdEstoque, string categ)
{
  if(!Empresa::getEmpresa()->getAcesso("Produto.Produto"))
  {
    throw "Acesso negado - Produto";
  }
  else
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
  
}

Produto::~Produto()
{
}

string Produto::getNome()
{
  if(!Empresa::getEmpresa()->getAcesso("Produto.getNome"))
  {
    throw "Acesso negado - Produto.getNome";
  }
  else
  {
    return this->nome;
  }
}

int Produto::getCodigo()
{
  if(!Empresa::getEmpresa()->getAcesso("Produto.getCodigo"))
  {
    throw "Acesso negado - Produto.getCodigo";
  }
  else
  {
    return this->codigo;
  }
}

float Produto::getValorDeVenda()
{
  if(!Empresa::getEmpresa()->getAcesso("Produto.getValorDeVenda"))
  {
    throw "Acesso negado - Produto.getValorDeVenda";
  }
  else
  {
    return this->valorDeVenda;
  }
}

int Produto::getTamanhoDoLoteMinimo()
{
  if(!Empresa::getEmpresa()->getAcesso("Produto.getTamanhoDoLoteMinimo"))
  {
    throw "Acesso negado - Produto.getTamanhoDoLoteMinimo";
  }
  else
  {
    return this->tamanhoDoLoteMinimo;
  }
}

int Produto::getEstoqueMinimo()
{
  if(!Empresa::getEmpresa()->getAcesso("Produto.getEstoqueMinimo"))
  {
    throw "Acesso negado - Produto.getEstoqueMinimo";
  }
  else
  {
    return this->estoqueMinimo;
  }
}

int Produto::getQtdEstoque()
{
  if(!Empresa::getEmpresa()->getAcesso("Produto.getQtdEstoque"))
  {
    throw "Acesso negado - Produto.getQtdEstoque";
  }
  else
  {
    return this->qtdEstoque;
  }
}
string Produto::getCategoria(){
  if(!Empresa::getEmpresa()->getAcesso("Produto.getCategoria"))
  {
    throw "Acesso negado - Produto.getCategoria";
  }
  else
  {
    return this->categoria->getTipo();
  }
}
OrdemDeProducao* Produto::getOrdem()
{
  if(!Empresa::getEmpresa()->getAcesso("Produto.getOrdem"))
  {
    throw "Acesso negado - Produto.getOrdem";
  }
  else
  {
    return this->ordem;
  }
}

Lote* Produto::getLote(int nl){
  if(!Empresa::getEmpresa()->getAcesso("Produto.getLote"))
  {
    throw "Acesso negado - Produto.getLote";
  }
  else
  {
    for(auto it : lotes){
      if(it->getNumLote() == nl){
        return it;
    }
  }
    return nullptr;
  }
  
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
  if(!Empresa::getEmpresa()->getAcesso("Produto.registraLote"))
  {
    throw "Acesso negado - Produto.registraLote";
  }
  else
  {
    this->lotes.push_back(new Lote(dataDeProducao, numeroLote, this->tamanhoDoLoteMinimo, this->nome));
    this->qtdEstoque += this->tamanhoDoLoteMinimo;
  }
}

pair<int, int> Produto::realizaVenda(int quantidade, Data venda)
{
  if(!Empresa::getEmpresa()->getAcesso("Produto.realizaVenda"))
  {
    throw "Acesso negado - Produto.realizaVenda";
  }
  else
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
}

void Produto::geraOrdem(Data dataQuandoAcabaEstoque)
{ 
  if(!Empresa::getEmpresa()->getAcesso("Produto.geraOrdem"))
  {
    throw "Acesso negado - Produto.geraOrdem";
  }
  else
  {
    this->ordem = new OrdemDeProducao(dataQuandoAcabaEstoque, this->nome, this->tamanhoDoLoteMinimo);
  }
}

bool Produto::temEstoque(int q)
{
  if(!Empresa::getEmpresa()->getAcesso("Produto.temEstoque"))
  {
    throw "Acesso negado - Produto.temEstoque";
  }
  else
  {
    return this->qtdEstoque >= q;
  }
}

void Produto::novoProduto(Produto* novo){
  if(!Empresa::getEmpresa()->getAcesso("Produto.novoProduto"))
  {
    throw "Acesso negado - Produto.novoProduto";
  }
  else
  {
    produtolist.push_back(novo);
  }
}

Produto* Produto::getProduto(string n){
  if(!Empresa::getEmpresa()->getAcesso("Produto.getProduto"))
  {
    throw "Acesso negado - Produto.getProduto";
  }
  else
  {
    for(auto it : produtolist){
      if(it->getNome() == n){
        return it;
    }
  }
    return nullptr;
  }
  
}