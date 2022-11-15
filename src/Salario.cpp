#include "../include/Empresa.h"
#include <string>
#include <vector>

using namespace std;

Salario::Salario() {
  if (!Empresa::getEmpresa()->getAcesso("Salario.Salario")) {
    throw "Acesso negado a Salario.Salario";
  } else {
    this->valor = 0;
    this->dissidio = 0.0;
    this->registro.push_back(make_pair(Data(), 0.0));
  }
}

Salario::Salario(float valValor) {
  if (!Empresa::getEmpresa()->getAcesso("Salario.Salario")) {
    throw "Acesso negado a Salario.Salario ";
  } else {
    this->valor = valValor;
    this->dissidio = 0.0;
  }
}

Salario::~Salario() {}

float Salario::getValor() {
  if (!Empresa::getEmpresa()->getAcesso("Salario.getValor")) {
    throw "Acesso negado a Salario.getValor";
  } else {
    return this->valor;
  }
}

vector<pair<Data, float>> Salario::getRegistro() {
  if (!Empresa::getEmpresa()->getAcesso("Salario.getRegistro")) {
    throw "Acesso negado a Salario.getRegistro";
  } else {
    return this->registro;
  }
}

float Salario::getDissidio() {
  if (!Empresa::getEmpresa()->getAcesso("Salario.getDissidio")) {
    throw "Acesso negado a Salario.getDissidio";
  } else {
    return this->dissidio;
  }
}

void Salario::setValor(float valValor) { this->valor = valValor; }

void Salario::setDissidio(Data valData, float valDissidio) {
  this->dissidio = valDissidio;
  for (auto it : Empresa::getEmpresa()->getFuncionario()) {
    it->promocao(valData, valDissidio);
  }
}

void Salario::promocao(Data valData, float valPercentual) {
  if (!Empresa::getEmpresa()->getAcesso("Salario.promocao")) {
    throw "Acesso negado a Salario.promocao";
  } else {
    this->valor = this->valor + (this->valor * valPercentual/100);
    this->atualizaRegistro(valData);
  }
}

void Salario::reajuste(Data valData, float valDissidio) {
  if (!Empresa::getEmpresa()->getAcesso("Salario.reajuste")) {
    throw "Acesso negado a Salario.reajuste";
  } else {
    this->valor = this->valor + (this->valor * valDissidio/100);
    this->atualizaRegistro(valData);
  }
}

void Salario::atualizaRegistro(Data valData) {
  if (!Empresa::getEmpresa()->getAcesso("Salario.atualizaRegistro")) {
    throw "Acesso negado a Salario.atualizaRegistro";
  } else
    this->registro.push_back(make_pair(valData, this->valor));
}
