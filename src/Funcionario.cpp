#include "../include/Funcionario.h"
#include "../include/Pessoa.h"
#include "../include/data.h"
#include "../include/Salario.h"
#include "../include/Cargo.h"
#include "../include/Departamento.h"
#include "../include/Empresa.h"
#include <string>
#include <vector>

using namespace std;

Funcionario::Funcionario():Pessoa()
{
  if(!Empresa::getEmpresa()->getAcesso("Funcionario.Funcionario"))
  {
    throw "Acesso negado a Funcionario.Funcionario";
  }
  else
  { 
    this->departamento = Departamento();
    this->dataNascimento = Data();
    this->salario = Salario();
    this->registro = vector <Data>();
    this->cargo = Cargo();
    this->estadoAtivo = false;
    this->jornada = nullptr;
    this->idVeiculo = 0;
  }
}

Funcionario::Funcionario(string valNome, Endereco valEndereco, string valEmail, string valDocumento, long int valTelefone, Departamento valDepartamento, Data valDataNascimento, Salario valSalario, vector <Data> valRegistro,Cargo valCargo, bool valEstadoAtivo)
:Pessoa(valNome, valEndereco, valEmail, valDocumento, valTelefone)
{
  if(!Empresa::getEmpresa()->getAcesso("Funcionario.Funcionario"))
  {
    throw "Acesso negado a Funcionario.Funcionario";
  }
  else
  { 
    this->departamento = valDepartamento;
    this->dataNascimento = valDataNascimento;
    this->salario = valSalario;
    this->registro = valRegistro;
    this->cargo = valCargo;
    this->estadoAtivo = valEstadoAtivo;
    this->idVeiculo = 0;
    this->jornada = nullptr; 
  }
}

Funcionario::~Funcionario()
{
}

Departamento Funcionario::getDepartamento()
{
  if(!Empresa::getEmpresa()->getAcesso("Funcionario.getDepartamento"))
  {
    throw "Acesso negado a Funcionario.getDepartamento";
  }
  else
  {
    return this->departamento;
  }
}

Data Funcionario::getDataNascimento()
{
  if(!Empresa::getEmpresa()->getAcesso("Funcionario.getDataNascimento"))
  {
    throw "Acesso negado a Funcionario.getDataNascimento";
  }
  else
  {
    return this->dataNascimento;
  }
}

Salario Funcionario::getSalario()
{
  if(!Empresa::getEmpresa()->getAcesso("Funcionario.getSalario"))
  {
    throw "Acesso negado a Funcionario.getSalario";
  }
  else
  {
    return this->salario;
  }
}

vector <Data> Funcionario::getRegistro()
{
  if(!Empresa::getEmpresa()->getAcesso("Funcionario.getRegistro"))
  {
    throw "Acesso negado a Funcionario.getRegistro";
  }
  else
  {
    return this->registro;
  }
}

Cargo Funcionario::getCargo()
{
  if(!Empresa::getEmpresa()->getAcesso("Funcionario.getCargo"))
  {
    throw "Acesso negado a Funcionario.getCargo";
  }
  else
  {
    return this->cargo;
  }
}

bool Funcionario::getEstadoAtivo()
{
  if(!Empresa::getEmpresa()->getAcesso("Funcionario.getEstadoAtivo"))
  {
    throw "Acesso negado a Funcionario.getEstadoAtivo";
  }
  else
  {
    return this->estadoAtivo;
  }
}

Turno* Funcionario::getJornada()
{
  return this->jornada;
}

int Funcionario::getIdVeiculo()
{
  return this->idVeiculo;
}

void Funcionario::setJornada(Turno* valJornada)
{
  this->jornada = valJornada;
}

void Funcionario::setIdVeiculo(int valIdVeiculo)
{
  this->idVeiculo = valIdVeiculo;
}

void Funcionario::setDepartamento(Departamento valDepartamento)
{
  this->departamento.setNome(valDepartamento.getNome());
}

void Funcionario::setDataNascimento(Data valDataNascimento)
{
  this->dataNascimento = valDataNascimento;
}

void Funcionario::setSalario(Data valData, Salario valSalario)
{
  this->salario = valSalario;
}

void Funcionario::setRegistro(vector <Data> valRegistro)
{
  this->registro = valRegistro;
}

void Funcionario::setCargo(Cargo valCargo)
{
  this->cargo = valCargo;
}

void Funcionario::setEstadoAtivo(bool valEstadoAtivo)
{
  this->estadoAtivo = valEstadoAtivo;
}

void Funcionario::alteraRegistro(Data valData)
{
  if(!Empresa::getEmpresa()->getAcesso("Funcionario.alteraRegistro"))
  {
    throw "Acesso negado a Funcionario.alteraRegistro";
  }
  else
  {
    this->registro.push_back(valData);
  }
}

void Funcionario::demiteFuncionario()
{
  if(!Empresa::getEmpresa()->getAcesso("Funcionario.demiteFuncionario"))
  {
    throw "Acesso negado a Funcionario.demiteFuncionario";
  }
  else
  {
    this->estadoAtivo = false;
  }
}

void Funcionario::promocao(Data valData, float valPercentual)
{
  if(!Empresa::getEmpresa()->getAcesso("Funcionario.promocao"))
  {
    throw "Acesso negado a Funcionario.promocao";
  }
  else
  {
    this->setSalario(valData, this->getSalario().getValor() * (1 + valPercentual/100));
    this->alteraRegistro(valData);
  }
}

void Funcionario::reajuste(Data valData, float valDissidio){
  if(!Empresa::getEmpresa()->getAcesso("Funcionario.reajuste"))
  {
    throw "Acesso negado a Funcionario.reajuste";
  }
  else
  {
    this->salario.setDissidio(valData, valDissidio);
  }
}


