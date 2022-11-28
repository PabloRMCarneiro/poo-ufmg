#include "../include/Produto.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"
#include "../include/PermissaoNegada.h"
#include <string>

vector<Produto *> Produto::produtolist;

Produto::Produto()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.Produto"))
  {
    PermissaoNegada *a = new PermissaoNegada("Produto", "Produto");
    string mensagem = "Acesso negado a Produto.Produto";
    throw mensagem;
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
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.Produto"))
  {
    PermissaoNegada *a = new PermissaoNegada("Produto", "Produto");
    string mensagem = "Acesso negado a Produto.Produto";
    throw mensagem;
  }
  else
  {
    this->nome = nome;
    this->codigo = codigo;
    this->valorDeVenda = valorDeVenda;
    this->tamanhoDoLoteMinimo = tamanhoDoLoteMinimo;
    this->estoqueMinimo = estoqueMinimo;
    this->qtdEstoque = qtdEstoque;
    LogEscrita *a = new LogEscrita("nome", "indefinido", this->nome, "Produto");
    LogEscrita *b = new LogEscrita("codigo", "indefinido", to_string(this->codigo), "Produto");
    LogEscrita *c = new LogEscrita("valorDeVenda", "indefinido", to_string(this->valorDeVenda), "Produto");
    LogEscrita *d = new LogEscrita("tamanhoDoLoteMinimo", "indefinido", to_string(this->tamanhoDoLoteMinimo), "Produto");
    LogEscrita *e = new LogEscrita("estoqueMinimo", "indefinido", to_string(this->estoqueMinimo), "Produto");
    LogEscrita *f = new LogEscrita("qtdEstoque", "indefinido", to_string(this->qtdEstoque), "Produto");
    this->setCategoria(categ);
    this->novoProduto(this);
  }
}

Produto::~Produto()
{
}

string Produto::getNome()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getNome"))
  {
    PermissaoNegada *a = new PermissaoNegada("getNome", "Produto");
    string mensagem = "Acesso negado a Produto.getNome";
    throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("nome", "Produto");
    return nome;
  }
}

int Produto::getCodigo()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getCodigo"))
  {
    PermissaoNegada *a = new PermissaoNegada("getCodigo", "Produto");
    string mensagem = "Acesso negado a Produto.getCodigo";
    throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("codigo", "Produto");
    return codigo;
  }
}
vector<pair<MateriaPrima*, double>> Produto::getMateriaPrimaList()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getMateriaPrimaList"))
  {
    PermissaoNegada *a = new PermissaoNegada("getMateriaPrimaList", "Produto");
    string mensagem = "Acesso negado a Produto.getMateriaPrimaList";
    throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("materiaPrimaList", "Produto");
    return materiaPrimaList;
  }
}
void Produto::setMateriaPrimaList(vector<pair<MateriaPrima*, double>> valMateriaPrimaList)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setMateriaPrimaList"))
  {
    PermissaoNegada *a = new PermissaoNegada("setMateriaPrimaList", "Produto");
    string mensagem = "Acesso negado a Produto.setMateriaPrimaList";
    throw mensagem;
  }
  else
  {
    materiaPrimaList = valMateriaPrimaList;
  }
}
float Produto::getValorDeVenda()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getValorDeVenda"))
  {
    PermissaoNegada *a = new PermissaoNegada("getValorDeVenda", "Produto");
    string mensagem = "Acesso negado a Produto.getValorDeVenda";
    throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("valorDeVenda", "Produto");
    return valorDeVenda;
  }
}

int Produto::getTamanhoDoLoteMinimo()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getTamanhoDoLoteMinimo"))
  {
    PermissaoNegada *a = new PermissaoNegada("getTamanhoDoLoteMinimo", "Produto");
    string mensagem = "Acesso negado a Produto.getTamanhoDoLoteMinimo";
    throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("tamanhoDoLoteMinimo", "Produto");
    return this->tamanhoDoLoteMinimo;
  }
}

int Produto::getEstoqueMinimo()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getEstoqueMinimo"))
  {
    PermissaoNegada *a = new PermissaoNegada("getEstoqueMinimo", "Produto");
    string mensagem = "Acesso negado a Produto.getEstoqueMinimo";
    throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("estoqueMinimo", "Produto");
    return this->estoqueMinimo;
  }
}

int Produto::getQtdEstoque()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getQtdEstoque"))
  {
    PermissaoNegada *a = new PermissaoNegada("getQtdEstoque", "Produto");
    string mensagem = "Acesso negado a Produto.getQtdEstoque";
    throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("qtdEstoque", "Produto");
    return this->qtdEstoque;
  }
}
Categoria* Produto::getCategoria()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getCategoria"))
  {
    PermissaoNegada *a = new PermissaoNegada("getCategoria", "Produto");
    string mensagem = "Acesso negado a Produto.getCategoria";
    throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("categoria", "Produto");
    return this->categoria;
  }
}

OrdemDeProducao *Produto::getOrdem()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getOrdem"))
  {
    PermissaoNegada *a = new PermissaoNegada("getOrdem", "Produto");
    string mensagem = "Acesso negado a Produto.getOrdem";
    throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("ordem", "Produto");
    return this->ordem;
  }
}

Lote *Produto::getLote(int nl)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getLote"))
  {
    PermissaoNegada *a = new PermissaoNegada("getLote", "Produto");
    string mensagem = "Acesso negado a Produto.getLote";
    throw mensagem;
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

void Produto::setNome(string valNome)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setNome"))
  {
    PermissaoNegada *a = new PermissaoNegada("setNome", "Produto");
    string mensagem = "Acesso negado a Produto.setNome";
    throw mensagem;
  }
  else
  {
    LogEscrita *f = new LogEscrita("nome", this->nome, valNome, "Produto");
    this->nome = valNome;
  }
}

void Produto::setCodigo(int valCodigo)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setCodigo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setCodigo", "Produto");
    string mensagem = "Acesso negado a Produto.setCodigo";
    throw mensagem;
  }
  else
  {
    LogEscrita *f = new LogEscrita("codigo", to_string(this->codigo), to_string(valCodigo), "Produto");
    this->codigo = valCodigo;
  }
}

void Produto::setValorDeVenda(float valValorDeVenda)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setValorDeVenda"))
  {
    PermissaoNegada *a = new PermissaoNegada("setValorDeVenda", "Produto");
    string mensagem = "Acesso negado a Produto.setValorDeVenda";
    throw mensagem;
  }
  else
  {
    LogEscrita *f = new LogEscrita("valorDeVenda", to_string(valorDeVenda), to_string(valValorDeVenda), "Produto");
    this->valorDeVenda = valValorDeVenda;
  }
}

void Produto::setTamanhoDoLoteMinimo(int valTamanhoDoLoteMinimo)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setTamanhoDoLoteMinimo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setTamanhoDoLoteMinimo", "Produto");
    string mensagem = "Acesso negado a Produto.setTamanhoDoLoteMinimo";
    throw mensagem;
  }
  else
  {
    LogEscrita *f = new LogEscrita("tamanhoDoLoteMinimo", to_string(tamanhoDoLoteMinimo), to_string(valTamanhoDoLoteMinimo), "Produto");
    this->tamanhoDoLoteMinimo = valTamanhoDoLoteMinimo;
  }
}

void Produto::setEstoqueMinimo(int valEstoqueMinimo)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setEstoqueMinimo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setEstoqueMinimo", "Produto");
    string mensagem = "Acesso negado a Produto.setEstoqueMinimo";
    throw mensagem;
  }
  else
  {
    LogEscrita *f = new LogEscrita("estoqueMinimo", to_string(estoqueMinimo), to_string(valEstoqueMinimo), "Produto");
    this->estoqueMinimo = valEstoqueMinimo;
  }
}

void Produto::setQtdEstoque(int valQtdEstoque)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setQtdEstoque"))
  {
    PermissaoNegada *a = new PermissaoNegada("setQtdEstoque", "Produto");
    string mensagem = "Acesso negado a Produto.setQtdEstoque";
    throw mensagem;
  }
  else
  {
    LogEscrita *f = new LogEscrita("qtdEstoque", to_string(qtdEstoque), to_string(valQtdEstoque), "Produto");
    this->qtdEstoque = valQtdEstoque;
  }
}

void Produto::setCategoria(string categ)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setCategoria"))
  {
    PermissaoNegada *a = new PermissaoNegada("setCategoria", "Produto");
    string mensagem = "Acesso negado a Produto.setCategoria";
    throw mensagem;
  }
  else
  {
    LogEscrita *f = new LogEscrita("categoria", "indefinido", categ, "Produto");
    this->categoria= Empresa::getEmpresa()->getCategoria(categ);
  }
}

void Produto::registraLote(int numeroLote, Data dataDeProducao)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.registraLote"))
  {
    PermissaoNegada *a = new PermissaoNegada("registraLote", "Produto");
    string mensagem = "Acesso negado a Produto.registraLote";
    throw mensagem;
  }
  else
  {
    int cont =0;
    for(auto it : this->getMateriaPrimaList()){
      if(it.first->getEstoque() >= (it.second*this->tamanhoDoLoteMinimo)){
        cont =1;
      } else {
        cont =0;
        throw "Falta Materia Prima!";
      }
    }
    if(cont == 1){
      this->lotes.push_back(new Lote(dataDeProducao, numeroLote, this->tamanhoDoLoteMinimo, this->nome));
      this->setQtdEstoque(this->qtdEstoque + this->tamanhoDoLoteMinimo);
      for(auto it : materiaPrimaList){
        it.first->setEstoque((-it.second*this->tamanhoDoLoteMinimo), Data::dataDeHoje);
      }
    }
  }
}

pair<int, int> Produto::realizaVenda(int quantidade, Data venda)
{
  
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.realizaVenda"))
  {
    PermissaoNegada *a = new PermissaoNegada("realizaVenda", "Produto");
    string mensagem = "Acesso negado a Produto.realizaVenda";
    throw mensagem;
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
        this->setQtdEstoque(this->qtdEstoque -(quantidade - faltaVender));
        break;
      }
    }
    if (this->getQtdEstoque() < this->getEstoqueMinimo())
    {
      geraOrdem(venda);
    }
    return make_pair(lote, faltaVender);
  }
}

void Produto::geraOrdem(Data dataQuandoAcabaEstoque)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.geraOrdem"))
  {
    PermissaoNegada *a = new PermissaoNegada("geraOrdem", "Produto");
    string mensagem = "Acesso negado a Produto.geraOrdem";
    throw mensagem;
  }
  else
  {
    this->ordem = new OrdemDeProducao(dataQuandoAcabaEstoque, this->nome, this->tamanhoDoLoteMinimo);
  }
}

bool Produto::temEstoque(int q)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.temEstoque"))
  {
    PermissaoNegada *a = new PermissaoNegada("temEstoque", "Produto");
    string mensagem = "Acesso negado a Produto.temEstoque";
    throw mensagem;
  }
  else
  {
    return this->getQtdEstoque() >= q;
  }
}

void Produto::novoProduto(Produto *novo)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.novoProduto"))
  {
    PermissaoNegada *a = new PermissaoNegada("novoProduto", "Produto");
    string mensagem = "Acesso negado a Produto.novoProduto";
    throw mensagem;
  }
  else
  {
    produtolist.push_back(novo);
  }
}
void Produto::alteraPreco(double alteracao){
  string valorvenda = to_string(valorDeVenda);
  this->valorDeVenda = this->valorDeVenda*alteracao;
  LogEscrita *f = new LogEscrita("valorDeVenda", valorvenda, to_string(valorDeVenda), "Produto");
}

Produto *Produto::getProduto(string n)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.getProduto"))
  {
    PermissaoNegada *a = new PermissaoNegada("getProduto", "Produto");
    string mensagem = "Acesso negado a Produto.getProduto";
    throw mensagem;
  }
  else
  {
    LogLeitura *f = new LogLeitura("produtolist", "Produto");
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