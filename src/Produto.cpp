#include "../include/Produto.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"

vector<Produto *> Produto::produtolist;

Produto::Produto()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.Produto"))
  {
    throw "Acesso negado a Produto.Produto";
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
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.Produto"))
  {
    throw "Acesso negado a Produto.Produto";
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
    this->novoProduto(this);
  }
}

Produto::~Produto()
{
}

string Produto::getNome()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getNome"))
  {
    throw "Acesso negado a Produto.getNome";
  }
  else

  {
    return this->nome;
  }
}

int Produto::getCodigo()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getCodigo"))
  {
    throw "Acesso negado a Produto.getCodigo";
  }
  else

  {
    return this->codigo;
  }
}
vector<pair<MateriaPrima*, double>> Produto::getMateriaPrimaList(){
  return this->materiaPrimaList;
}
void Produto::setMateriaPrimaList(vector<pair<MateriaPrima*, double>> valMateriaPrimaList){
  this->materiaPrimaList = valMateriaPrimaList;
}
float Produto::getValorDeVenda()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getValorDeVenda"))
  {
    throw "Acesso negado a Produto.getValorDeVenda";
  }
  else

  {
    return this->valorDeVenda;
  }
}

int Produto::getTamanhoDoLoteMinimo()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getTamanhoDoLoteMinimo"))
  {
    throw "Acesso negado a Produto.getTamanhoDoLoteMinimo";
  }
  else

  {
    return this->tamanhoDoLoteMinimo;
  }
}

int Produto::getEstoqueMinimo()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getEstoqueMinimo"))
  {
    throw "Acesso negado a Produto.getEstoqueMinimo";
  }
  else

  {
    return this->estoqueMinimo;
  }
}

int Produto::getQtdEstoque()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getQtdEstoque"))
  {
    throw "Acesso negado a Produto.getQtdEstoque";
  }
  else

  {
    return this->qtdEstoque;
  }
}
Categoria* Produto::getCategoria()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getCategoria"))
  {
    throw "Acesso negado a Produto.getCategoria";
  }
  else

  {
    return this->categoria;
  }
}
OrdemDeProducao *Produto::getOrdem()
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getOrdem"))
  {
    throw "Acesso negado a Produto.getOrdem";
  }
  else

  {
    return this->ordem;
  }
}

Lote *Produto::getLote(int nl)
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getLote"))
  {
    throw "Acesso negado a Produto.getLote";
  }
  else

  {
    for (auto it : lotes)
    {
      if (it->getNumLote() == nl)
      {
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

void Produto::setCategoria(string categ)
{
  this->categoria= Empresa::getEmpresa()->getCategoria(categ);
}

void Produto::registraLote(int numeroLote, Data dataDeProducao)
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.registraLote"))
  {
    throw "Acesso negado a Produto.registraLote";
  }
  else

  {
    int cont =0;
    for(auto it : materiaPrimaList){
      if(it.first->getEstoque() >= (it.second*this->tamanhoDoLoteMinimo)){
        cont =1;
      } else {
        cont =0;
        throw "Falta Materia Prima!";
      }
    }
    if(cont == 1){
      this->lotes.push_back(new Lote(dataDeProducao, numeroLote, this->tamanhoDoLoteMinimo, this->nome));
      this->qtdEstoque += this->tamanhoDoLoteMinimo;
      for(auto it : materiaPrimaList){
        it.first->setEstoque((-it.second*this->tamanhoDoLoteMinimo), Data::dataDeHoje);
      }
    }
  }
}

pair<int, int> Produto::realizaVenda(int quantidade, Data venda)
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.realizaVenda"))
  {
    throw "Acesso negado a Produto.realizaVenda";
  }
  else
  {
    int lote, faltaVender=quantidade;
    for (auto it : this->lotes)
    {
      if (it->getQuantidadeAtual() > 0)
      {
        lote = it->getNumLote();
        faltaVender = it->vende(faltaVender);
        this->qtdEstoque -= (quantidade - faltaVender);
        break;
      }
    }
    if (this->qtdEstoque < this->estoqueMinimo)
    {
      geraOrdem(venda);
    }
    return make_pair(lote, faltaVender);
  }
}

void Produto::geraOrdem(Data dataQuandoAcabaEstoque)
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.geraOrdem"))
  {
    throw "Acesso negado a Produto.geraOrdem";
  }
  else

  {
    this->ordem = new OrdemDeProducao(dataQuandoAcabaEstoque, this->nome, this->tamanhoDoLoteMinimo);
  }
}

bool Produto::temEstoque(int q)
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.temEstoque"))
  {
    throw "Acesso negado a Produto.temEstoque";
  }
  else

  {
    return this->qtdEstoque >= q;
  }
}

void Produto::novoProduto(Produto *novo)
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.novoProduto"))
  {
    throw "Acesso negado a Produto.novoProduto";
  }
  else

  {
    produtolist.push_back(novo);
  }
}
void Produto::alteraPreco(double alteracao){
  this->valorDeVenda = this->valorDeVenda*alteracao;
}
Produto *Produto::getProduto(string n)
{
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getProduto"))
  {
    throw "Acesso negado a Produto.getProduto";
  }
  else

  {
    for (auto it : produtolist)
    {
      if (it->getNome() == n)
      {
        return it;
      }
    }
    return nullptr;
  }
}