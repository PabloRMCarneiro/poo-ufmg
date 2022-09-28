#include <string>
#include <vector>
#include "../include/Produto.h"

using namespace std;


Produto::Produto()
{
  this->nome = "";
  this->codigo = 0;
  this->valorDeVenda = 0;
  this->tamanhoDoLoteMinimo = 0;
  this->estoqueMinimo = 0;
  this->qtdEstoque = 0;
  this->ordemDeProducao = Data();
}

Produto::Produto(string nome, int codigo, float valorDeVenda, int tamanhoDoLoteMinimo, int estoqueMinimo, int qtdEstoque, Data ordemDeProducao)
{
  this->nome = nome;
  this->codigo = codigo;
  this->valorDeVenda = valorDeVenda;
  this->tamanhoDoLoteMinimo = tamanhoDoLoteMinimo;
  this->estoqueMinimo = estoqueMinimo;
  this->qtdEstoque = qtdEstoque;
  this->ordemDeProducao = ordemDeProducao;
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

Data Produto::getOrdemDeProducao()
{
  return this->ordemDeProducao;
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

void Produto::setOrdemDeProducao(Data ordemDeProducao)
{
  this->ordemDeProducao = ordemDeProducao;
}

void Produto::realizaVenda(int quantidade)
{
  this->qtdEstoque -= quantidade;
}

void Produto::geraOrdemDeProducao(Data dataQuandoAcabaEstoque)
{
  this->ordemDeProducao = dataQuandoAcabaEstoque;
}

bool Produto::temEstoque()
{
  return this->qtdEstoque > 0;
}
