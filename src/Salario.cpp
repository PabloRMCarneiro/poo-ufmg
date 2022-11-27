#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"
#include "../include/Funcionario.h"
#include "../include/Salario.h"
#include "../include/PermissaoNegada.h"

#include <string>
#include <vector>

using namespace std;

Salario::Salario() 
{
  if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.Salario")) {
      PermissaoNegada *a = new PermissaoNegada("Salario", "Salario");
      string mensagem = "Acesso negado a Salario.Salario";
      throw mensagem;
  } 
  else 
  {
    this->valor = 0;
    this->dissidio = 0.0;
    this->registro.push_back(make_pair(Data(), 0.0));
  }
}

Salario::Salario(float valValor) 
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.Salario")) {
      PermissaoNegada *a = new PermissaoNegada("Salario", "Salario");
      string mensagem = "Acesso negado a Salario.Salario";
      throw mensagem;
  } 
  else 
  {
    this->valor = valValor;
    this->dissidio = 0.0;
    LogEscrita *a = new LogEscrita("valor", "indefinido", to_string(valValor), "Salario");
    LogEscrita *b = new LogEscrita("dissidio", "indefinido", to_string(0.0), "Salario");
  }
}

Salario::~Salario() {}

float Salario::getValor() 
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.getValor")) {
      PermissaoNegada *a = new PermissaoNegada("getValor", "Salario");
      string mensagem = "Acesso negado a Salario.getValor";
      throw mensagem;
  } 
  else 
  {
    LogLeitura *logLeitura = new LogLeitura("valor", "Salario");
    return this->valor;
  }
}

vector<pair<Data, float>> Salario::getRegistro() 
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.getRegistro")) {
      PermissaoNegada *a = new PermissaoNegada("getRegistro", "Salario");
      string mensagem = "Acesso negado a Salario.getRegistro";
      throw mensagem;
  } 
  else 
  {
    LogLeitura *logLeitura = new LogLeitura("registro", "Salario");
    return this->registro;
  }
}

float Salario::getDissidio() 
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.getDissidio")) {
      PermissaoNegada *a = new PermissaoNegada("getDissidio", "Salario");
      string mensagem = "Acesso negado a Salario.getDissidio";
      throw mensagem;
  } 
  else 
  {
    LogLeitura *logLeitura = new LogLeitura("dissidio", "Salario");
    return this->dissidio;
  }
}

void Salario::setValor(float valValor) 
{ 
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.setValor")) {
      PermissaoNegada *a = new PermissaoNegada("setValor", "Salario");
      string mensagem = "Acesso negado a Salario.setValor";
      throw mensagem;
  } 
  else 
  {
    LogEscrita *a = new LogEscrita("valor", to_string(valor), to_string(valValor), "Salario");
    this->valor = valValor;
  }
}

void Salario::setDissidio(Data valData, float valDissidio) 
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.setDissidio")) {
      PermissaoNegada *a = new PermissaoNegada("setDissidio", "Salario");
      string mensagem = "Acesso negado a Salario.setDissidio";
      throw mensagem;
  } 
  else 
  {
    LogEscrita *a = new LogEscrita("valor", to_string(dissidio), to_string(valDissidio), "Salario");
    this->dissidio = valDissidio;
    for (auto it : Empresa::getEmpresa()->getFuncionarios()) {
      it->promocao(valData, valDissidio);
    }
  }
}

void Salario::promocao(Data valData, float valPercentual) {
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.promocao")) {
      PermissaoNegada *a = new PermissaoNegada("promocao", "Salario");
      string mensagem = "Acesso negado a Salario.promocao";
      throw mensagem;
  } 
  else 
  {
    this->setValor(this->valor + (this->valor * valPercentual/100));
    this->atualizaRegistro(valData);
  }
}

void Salario::reajuste(Data valData, float valDissidio) {
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.reajuste")) {
      PermissaoNegada *a = new PermissaoNegada("reajuste", "Salario");
      string mensagem = "Acesso negado a Salario.reajuste";
      throw mensagem;
  } 
  else
  {
    this->setValor(this->valor + (this->valor * valDissidio/100));
    this->atualizaRegistro(valData);
  }
}

void Salario::atualizaRegistro(Data valData) {
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.atualizaRegistro")) {
      PermissaoNegada *a = new PermissaoNegada("atualizaRegistro", "Salario");
      string mensagem = "Acesso negado a Salario.atualizaRegistro";
      throw mensagem;
  }
  else
  {
    this->registro.push_back(make_pair(valData, this->valor));
  }
}