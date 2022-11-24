#include "../include/RegistroVendas.h"
#include "../include/Empresa.h"

RegistroVendas::RegistroVendas(Data dv, Produto *p, int q, Cliente *cl)
{
  if (!Empresa::getEmpresa()->getAcesso("RegistroVendas.RegistroVendas"))
  {
    throw "Acesso negado - RegistroVendas";
  }
  else
  {
    this->setDataDeVenda(dv);
    this->setProduto(p);
    this->setQuantidadeVenda(q);
    this->setCliente(cl);
  }
}

Cliente *RegistroVendas::getCliente()
{
  if (!Empresa::getEmpresa()->getAcesso("RegistroVendas.getCliente"))
  {
    throw "Acesso negado - getCliente";
  }
  else
  {
    return this->cliente;
  }
}

Data RegistroVendas::getDataDeVenda()
{
  if (!Empresa::getEmpresa()->getAcesso("RegistroVendas.getDataDeVenda"))
  {
    throw "Acesso negado - getDataDeVenda";
  }
  else
  {
    return this->dataDeVenda;
  }
}

vector<int> RegistroVendas::getNumeroDoLote()
{
  if (!Empresa::getEmpresa()->getAcesso("RegistroVendas.getNumeroDoLote"))
  {
    throw "Acesso negado - getNumeroDoLote";
  }
  else
  {
    return this->lote;
  }
}

Produto *RegistroVendas::getProduto()
{
  if (!Empresa::getEmpresa()->getAcesso("RegistroVendas.getProduto"))
  {
    throw "Acesso negado - getProduto";
  }
  else
  {
    return this->produto;
  }
}

int RegistroVendas::getQuantidadeVenda()
{
  if (!Empresa::getEmpresa()->getAcesso("RegistroVendas.getQuantidadeVenda"))
  {
    throw "Acesso negado - getQuantidadeVenda";
  }
  else
  {
    return this->quantidadeVenda;
  }
}

void RegistroVendas::setCliente(Cliente *cl)
{
  this->cliente = cl;
}

void RegistroVendas::setDataDeVenda(Data v)
{
  this->dataDeVenda = v;
}

void RegistroVendas::setNumeroDoLote(int nl)
{
  this->lote.push_back(nl);
}

void RegistroVendas::setProduto(string p)
{
  this->produto = Produto::getProduto(p);
}

void RegistroVendas::setProduto(Produto *p)
{
  this->produto = p;
}

void RegistroVendas::setQuantidadeVenda(int qvenda)
{
  this->quantidadeVenda = qvenda;
  if (this->validaVenda(qvenda))
  {
    pair<int, int> a = this->produto->realizaVenda(qvenda, this->dataDeVenda);
    this->lote.push_back(a.first);
    while (a.second > 0)
    {
      pair<int, int> a = this->produto->realizaVenda(qvenda, this->dataDeVenda);
      this->lote.push_back(a.first);
    }
  }
}

bool RegistroVendas::validaVenda(int q)
{
  this->vendido = this->produto->temEstoque(q);
  return this->vendido;
}