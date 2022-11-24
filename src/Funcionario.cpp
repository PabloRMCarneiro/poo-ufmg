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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.Funcionario"))
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.Funcionario"))
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getDepartamento"))
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getDataNascimento"))
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getSalario"))
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getRegistro"))
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getCargo"))
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getEstadoAtivo"))
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getJornada"))
  {
    throw "Acesso negado a Funcionario.getJornada";
  }
  else
  {
    return this->jornada;
  }
}

int Funcionario::getIdVeiculo()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getIdVeiculo"))
  {
    throw "Acesso negado a Funcionario.getIdVeiculo";
  }
  else
  {
    return this->idVeiculo;
  }
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.alteraRegistro"))
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.demiteFuncionario"))
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.promocao"))
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.reajuste"))
  {
    throw "Acesso negado a Funcionario.reajuste";
  }
  else
  {
    this->salario.setDissidio(valData, valDissidio);
  }
}


