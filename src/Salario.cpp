#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"
#include "../include/Funcionario.h"
#include "../include/Salario.h"
#include <string>
#include <vector>

using namespace std;

Salario::Salario() {
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.Salario"))
  {
    throw "Acesso negado a Salario.Salario";
  }
  else
  {
    this->valor = 0;
    this->dissidio = 0.0;
    this->registro.push_back(make_pair(Data(), 0.0));
  }
}

Salario::Salario(float valValor) {
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.Salario"))
  {
    throw "Acesso negado a Salario.Salario";
  }
  else
  {
    this->valor = valValor;
    this->dissidio = 0.0;
  }
}

Salario::~Salario() {}

float Salario::getValor() {
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.getValor"))
  {
    throw "Acesso negado a Salario.getValor";
  }
  else
  {
    return this->valor;
  }
}

vector<pair<Data, float>> Salario::getRegistro() {
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.getRegistro"))
  {
    throw "Acesso negado a Salario.getRegistro";
  }
  else
  {
    return this->registro;
  }
}

float Salario::getDissidio() {
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.getDissidio"))
  {
    throw "Acesso negado a Salario.getDissidio";
  }
  else
  {
    return this->dissidio;
  }
}

void Salario::setValor(float valValor) { this->valor = valValor; }

void Salario::setDissidio(Data valData, float valDissidio) {
  this->dissidio = valDissidio;
  for (auto it : Empresa::getEmpresa()->getFuncionarios()) {
    it->promocao(valData, valDissidio);
  }
}

void Salario::promocao(Data valData, float valPercentual) {
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.promocao"))
  {
    throw "Acesso negado a Salario.promocao";
  }
  else
  {
    this->valor = this->valor + (this->valor * valPercentual/100);
    this->atualizaRegistro(valData);
  }
}

void Salario::reajuste(Data valData, float valDissidio) {
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.reajuste"))
  {
    throw "Acesso negado a Salario.reajuste";
  }
  else
  {
    this->valor = this->valor + (this->valor * valDissidio/100);
    this->atualizaRegistro(valData);
  }
}

void Salario::atualizaRegistro(Data valData) {
  if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Salario.atualizaRegistro"))
  {
    throw "Acesso negado a Salario.atualizaRegistro";
  }
  else
    this->registro.push_back(make_pair(valData, this->valor));
}