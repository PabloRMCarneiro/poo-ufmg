#include "Funcionario.h"
#include "Pessoa.h"
#include "data.h"
#include "Salario.h"
#include "Cargo.h"
#include "Departamento.h"
#include <string>
#include <vector>

using namespace std;


Funcionario::Funcionario()
{
  this->departamento = Departamento();
  this->dataNascimento = Data();
  this->salario = Salario();
  this->registro = vector <Data>();
  this->cargo = Cargo();
  this->estadoAtivo = false;
}

Funcionario::Funcionario(Departamento valDepartamento, Data valDataNascimento, Salario valSalario, vector <Data> valRegistro,Cargo valCargo, bool valEstadoAtivo)
{
  this->departamento = valDepartamento;
  this->dataNascimento = valDataNascimento;
  this->salario = valSalario;
  this->registro = valRegistro;
  this->cargo = valCargo;
  this->estadoAtivo = valEstadoAtivo;
}

Funcionario::~Funcionario()
{
}

//Metodos get:

Departamento Funcionario::getDepartamento()
{
  return this->departamento;
}

Data Funcionario::getDataNascimento()
{
  return this->dataNascimento;
}

Salario Funcionario::getSalario()
{
  return this->salario;
}

vector <Data> Funcionario::getRegistro()
{
  return this->registro;
}

Cargo Funcionario::getCargo()
{
  return this->cargo;
}

bool Funcionario::getEstadoAtivo()
{
  return this->estadoAtivo;
}

//Metodos set:

void Funcionario::setDepartamento(Departamento valDepartamento)
{
  this->departamento.setNome(valDepartamento.getNome());
}

void Funcionario::setDataNascimento(Data valDataNascimento)
{
  this->dataNascimento = valDataNascimento;
}

void Funcionario::setSalario(Salario valSalario)
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

//Metodos:

void Funcionario::alteraRegistro(Data valData)
{
  this->registro.push_back(valData);
}

void Funcionario::demiteFuncionario()
{
  this->estadoAtivo = false;
}

void Funcionario::alteraSalario(float valPercentual)
{
  this->salario.setValor(this->salario.getValor() + (this->salario.getValor() * valPercentual));
}



