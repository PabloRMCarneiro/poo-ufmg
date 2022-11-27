#include "../include/Produto.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"
#include "../include/PermissaoNegada.h"
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

void Produto::setNome(string nome)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setNome"))
  {
    PermissaoNegada *a = new PermissaoNegada("setNome", "Produto");
    string mensagem = "Acesso negado a Produto.setNome";
    throw mensagem;
  }
  else
  {
    this->nome = nome;
  }
}

void Produto::setCodigo(int codigo)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setCodigo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setCodigo", "Produto");
    string mensagem = "Acesso negado a Produto.setCodigo";
    throw mensagem;
  }
  else
  {
    this->codigo = codigo;
  }
}

void Produto::setValorDeVenda(float valorDeVenda)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setValorDeVenda"))
  {
    PermissaoNegada *a = new PermissaoNegada("setValorDeVenda", "Produto");
    string mensagem = "Acesso negado a Produto.setValorDeVenda";
    throw mensagem;
  }
  else
  {
    this->valorDeVenda = valorDeVenda;
  }
}

void Produto::setTamanhoDoLoteMinimo(int tamanhoDoLoteMinimo)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setTamanhoDoLoteMinimo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setTamanhoDoLoteMinimo", "Produto");
    string mensagem = "Acesso negado a Produto.setTamanhoDoLoteMinimo";
    throw mensagem;
  }
  else
  {
    this->tamanhoDoLoteMinimo = tamanhoDoLoteMinimo;
  }
}

void Produto::setEstoqueMinimo(int estoqueMinimo)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setEstoqueMinimo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setEstoqueMinimo", "Produto");
    string mensagem = "Acesso negado a Produto.setEstoqueMinimo";
    throw mensagem;
  }
  else
  {
    this->estoqueMinimo = estoqueMinimo;
  }
}

void Produto::setQtdEstoque(int qtdEstoque)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Produto.setQtdEstoque"))
  {
    PermissaoNegada *a = new PermissaoNegada("setQtdEstoque", "Produto");
    string mensagem = "Acesso negado a Produto.setQtdEstoque";
    throw mensagem;
  }
  else
  {
    this->qtdEstoque = qtdEstoque;
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
    return this->qtdEstoque >= q;
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
  this->valorDeVenda = this->valorDeVenda*alteracao;
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