#include "../include/RegistroVendas.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"
#include "../include/PermissaoNegada.h"
#include <string>

RegistroVendas::RegistroVendas(Data dv, Produto *p, int q, Cliente *cl)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.RegistroVendas"))
  {
      PermissaoNegada *a = new PermissaoNegada("RegistroVendas", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.RegistroVendas";
      throw mensagem;
  }
  else
  {
    this->setDataDeVenda(dv);
    this->setProduto(p);
    this->setQuantidadeVenda(q);
    this->setCliente(cl);
    Empresa::getEmpresa()->setRegistroVendas(this);
  }
}

Cliente *RegistroVendas::getCliente()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.getCliente"))
  {
      PermissaoNegada *a = new PermissaoNegada("getCliente", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.getCliente";
      throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("cliente", "RegistroVendas");
    return this->cliente;
  }
}
void RegistroVendas::setCodigoPedido(int valCodigoPedido)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.setCodigoPedido"))
  {
      PermissaoNegada *a = new PermissaoNegada("setCodigoPedido", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.setCodigoPedido";
      throw mensagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("codigoPedido", "indefinido", to_string(valCodigoPedido), "RegistroVendas");
    this->codigoPedido = valCodigoPedido;
  }
}
int RegistroVendas::getCodigoPedido()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.getCodigoPedido"))
  {
      PermissaoNegada *a = new PermissaoNegada("getCodigoPedido", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.getCodigoPedido";
      throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("codigoPedido", "RegistroVendas");
    return this->codigoPedido;
  }
}
Data RegistroVendas::getDataDeVenda()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.getDataDeVenda"))
  {
      PermissaoNegada *a = new PermissaoNegada("getDataDeVenda", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.getDataDeVenda";
      throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("dataDeVenda", "RegistroVendas");
    return this->dataDeVenda;
  }
}

vector<int> RegistroVendas::getNumeroDoLote()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.getNumeroDoLote"))
  {
      PermissaoNegada *a = new PermissaoNegada("getNumeroDoLote", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.getNumeroDoLote";
      throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("lote", "RegistroVendas");
    return this->lote;
  }
}

Produto *RegistroVendas::getProduto()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.getProduto"))
  {
      PermissaoNegada *a = new PermissaoNegada("getProduto", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.getProduto";
      throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("produto", "RegistroVendas");
    return this->produto;
  }
}

int RegistroVendas::getQuantidadeVenda()
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.getQuantidadeVenda"))
  {
      PermissaoNegada *a = new PermissaoNegada("getQuantidadeVenda", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.getQuantidadeVenda";
      throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("quantidadeVenda", "RegistroVendas");
    return this->quantidadeVenda;
  }
}

void RegistroVendas::setCliente(Cliente *cl)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.setCliente"))
  {
      PermissaoNegada *a = new PermissaoNegada("setCliente", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.setCliente";
      throw mensagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("cliente", "indefinido", cl->getNome(), "RegistroVendas");
    this->cliente = cl;
  }
}

void RegistroVendas::setDataDeVenda(Data v)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.setDataDeVenda"))
  {
      PermissaoNegada *a = new PermissaoNegada("setDataDeVenda", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.setDataDeVenda";
      throw mensagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("dataDeVenda", "indefinido", v.getData(), "RegistroVendas");
    this->dataDeVenda = v;
  }
}

void RegistroVendas::setNumeroDoLote(int nl)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.setNumeroDoLote"))
  {
      PermissaoNegada *a = new PermissaoNegada("setNumeroDoLote", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.setNumeroDoLote";
      throw mensagem;
  }
  else
  {
    this->lote.push_back(nl);
  }
}

void RegistroVendas::setProduto(string p)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.setProduto"))
  {
      PermissaoNegada *a = new PermissaoNegada("setProduto", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.setProduto";
      throw mensagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("produto", "indefinido", p, "RegistroVendas");
    this->produto = Produto::getProduto(p);
  }
}

void RegistroVendas::setProduto(Produto *p)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.setProduto"))
  {
      PermissaoNegada *a = new PermissaoNegada("setProduto", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.setProduto";
      throw mensagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("produto", "indefinido", p->getNome(), "RegistroVendas");
    this->produto = p;
  }
}

void RegistroVendas::setQuantidadeVenda(int qvenda)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.setQuantidadeVenda"))
  {
      PermissaoNegada *a = new PermissaoNegada("setQuantidadeVenda", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.setQuantidadeVenda";
      throw mensagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("quantidadeVenda", "indefinido", to_string(qvenda), "RegistroVendas");
    this->quantidadeVenda = qvenda;
    if (this->validaVenda(qvenda))
    {
      pair<int, int> a = this->getProduto()->realizaVenda(qvenda, this->dataDeVenda);
      this->lote.push_back(a.first);
      while (a.second > 0)
      {
        a = this->getProduto()->realizaVenda(a.second, this->dataDeVenda);
        this->lote.push_back(a.first);
      }
    }
  }
}

bool RegistroVendas::validaVenda(int q)
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.validaVenda"))
  {
      PermissaoNegada *a = new PermissaoNegada("validaVenda", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.validaVenda";
      throw mensagem;
  }
  else
  {
    this->vendido = this->getProduto()->temEstoque(q);
    LogEscrita *a = new LogEscrita("vendido", "indefinido", to_string(vendido), "RegistroVendas");
    return this->vendido;
  }
}

void RegistroVendas::imprime(){
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("RegistroVendas.imprime"))
  {
      PermissaoNegada *a = new PermissaoNegada("imprime", "RegistroVendas");
      string mensagem = "Acesso negado a RegistroVendas.imprime";
      throw mensagem;
  }
  else
  {
    cout << "Em " << this->getDataDeVenda().getData() << ", foram vendidas " << this->getQuantidadeVenda() << " unidades de ";
    cout << this->getProduto()->getNome() << " pelo cliente " << this->getCliente()->getNome() << "." << endl;
  }
}