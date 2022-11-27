#include "../include/Funcionario.h"
#include "../include/Pessoa.h"
#include "../include/data.h"
#include "../include/Salario.h"
#include "../include/Cargo.h"
#include "../include/Departamento.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"
#include <string>
#include <vector>
//LogLeitura *a = new LogLeitura("nome", "Cargo");

using namespace std;


Funcionario::Funcionario():Pessoa()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.Funcionario"))
  {
    PermissaoNegada *a = new PermissaoNegada("Funcionario", "Funcionario");
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
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.Funcionario"))
  {
    PermissaoNegada *a = new PermissaoNegada("Funcionario", "Funcionario");
    throw "Acesso negado a Funcionario.Funcionario";
  }
  else
  { 
    this->departamento = valDepartamento;
    this->dataNascimento = valDataNascimento;
    LogEscrita *a = new LogEscrita("dataNascimento", "indefinido", dataNascimento.getData(), "Funcionario");
    this->salario = valSalario;
    LogEscrita *b = new LogEscrita("salario", "indefinido", to_string(valSalario.getValor()), "Funcionario");
    this->registro = valRegistro;
    this->cargo = valCargo;
    LogEscrita *c = new LogEscrita("cargo", "indefinido", valCargo.getNome(), "Funcionario");
    this->estadoAtivo = valEstadoAtivo;
    LogEscrita *d = new LogEscrita("estadoAtivo", "indefinido", to_string(valEstadoAtivo), "Funcionario");
    this->idVeiculo = 0;
    LogEscrita *f = new LogEscrita("idVeiculo", "indefinido", "0", "Funcionario");
    this->jornada = nullptr; 
    Empresa::getEmpresa()->setFuncionario(this);
  }
}

// Funcionario::~Funcionario()
// {
// }

Departamento Funcionario::getDepartamento()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getDepartamento"))
  {
    PermissaoNegada *a = new PermissaoNegada("getDepartamento", "Funcionario");
    throw "Acesso negado a Funcionario.getDepartamento";
  }
  else
  {
    LogLeitura *a = new LogLeitura("departamento", "Funcionario");
    return this->departamento;
  }
}

Data Funcionario::getDataNascimento()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getDataNascimento"))
  {
    PermissaoNegada *a = new PermissaoNegada("getDataNascimento", "Funcionario");
    throw "Acesso negado a Funcionario.getDataNascimento";
  }
  else
  {
    LogLeitura *a = new LogLeitura("dataNascimento", "Funcionario");
    return this->dataNascimento;
  }
}

Salario Funcionario::getSalario()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getSalario"))
  {
    PermissaoNegada *a = new PermissaoNegada("getSalario", "Funcionario");
    throw "Acesso negado a Funcionario.getSalario";
  }
  else
  {
    LogLeitura *a = new LogLeitura("salario", "Funcionario");
    return this->salario;
  }
}

vector <Data> Funcionario::getRegistro()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getRegistro"))
  {
    PermissaoNegada *a = new PermissaoNegada("getRegistro", "Funcionario");
    throw "Acesso negado a Funcionario.getRegistro";
  }
  else
  {
    LogLeitura *a = new LogLeitura("registro", "Funcionario");
    return this->registro;
  }
}

Cargo Funcionario::getCargo()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getCargo"))
  {
    PermissaoNegada *a = new PermissaoNegada("getCargo", "Funcionario");
    throw "Acesso negado a Funcionario.getCargo";
  }
  else
  {
    LogLeitura *a = new LogLeitura("cargo", "Funcionario");
    return this->cargo;
  }
}

bool Funcionario::getEstadoAtivo()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getEstadoAtivo"))
  {
    PermissaoNegada *a = new PermissaoNegada("getEstadoAtivo", "Funcionario");
    throw "Acesso negado a Funcionario.getEstadoAtivo";
  }
  else
  {
    LogLeitura *a = new LogLeitura("estadoAtivo", "Funcionario");
    return this->estadoAtivo;
  }
}

Turno* Funcionario::getJornada()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getJornada"))
  {
    PermissaoNegada *a = new PermissaoNegada("getJornada", "Funcionario");
    throw "Acesso negado a Funcionario.getJornada";
  }
  else
  {
    LogLeitura *a = new LogLeitura("jornada", "Funcionario");
    return this->jornada;
  }
}

int Funcionario::getIdVeiculo()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getIdVeiculo"))
  {
    PermissaoNegada *a = new PermissaoNegada("getIdVeiculo", "Funcionario");
    throw "Acesso negado a Funcionario.getIdVeiculo";
  }
  else
  {
    LogLeitura *a = new LogLeitura("idVeiculo", "Funcionario");
    return this->idVeiculo;
  }
}

void Funcionario::setJornada(Turno* valJornada)
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getIdVeiculo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setJornada", "Funcionario");
    throw "Acesso negado a Funcionario.setJornada";
  }
  else
  {
    this->jornada = valJornada;
  }
}

void Funcionario::setIdVeiculo(int valIdVeiculo)
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getIdVeiculo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setIdVeiculo", "Funcionario");
    throw "Acesso negado a Funcionario.setIdVeiculo";
  }
  else
  {
    LogEscrita *a = new LogEscrita("idVeiculo", to_string(this->idVeiculo), to_string(valIdVeiculo), "Funcionario");
    this->idVeiculo = valIdVeiculo;
  }
}

void Funcionario::setDepartamento(Departamento valDepartamento)
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getIdVeiculo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setDepartamento", "Funcionario");
    throw "Acesso negado a Funcionario.setDepartamento";
  }
  else
  {
    this->departamento = valDepartamento;
  }
}

void Funcionario::setDataNascimento(Data valDataNascimento)
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getIdVeiculo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setDepartamento", "Funcionario");
    throw "Acesso negado a Funcionario.setDepartamento";
  }
  else
  {
    this->dataNascimento = valDataNascimento;
  }
}

void Funcionario::setSalario(Data valData, Salario valSalario)
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getIdVeiculo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setSalario", "Funcionario");
    throw "Acesso negado a Funcionario.setSalario";
  }
  else
  {
    this->salario = valSalario;
  }
}

void Funcionario::setRegistro(vector <Data> valRegistro)
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getIdVeiculo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setRegistro", "Funcionario");
    throw "Acesso negado a Funcionario.setRegistro";
  }
  else
  {
    this->registro = valRegistro;
  }
}

void Funcionario::setCargo(Cargo valCargo)
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getIdVeiculo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setCargo", "Funcionario");
    throw "Acesso negado a Funcionario.setCargo";
  }
  else
  {
    this->cargo = valCargo;
  }
}

void Funcionario::setEstadoAtivo(bool valEstadoAtivo)
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getIdVeiculo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setEstadoAtivo", "Funcionario");
    throw "Acesso negado a Funcionario.setEstadoAtivo";
  }
  else
  {
    LogEscrita *a = new LogEscrita("estadoAtivo", to_string(estadoAtivo), to_string(valEstadoAtivo), "Funcionario");
    this->estadoAtivo = valEstadoAtivo;
  }
}

void Funcionario::alteraRegistro(Data valData)
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.alteraRegistro"))
  {
    PermissaoNegada *a = new PermissaoNegada("alteraRegistro", "Funcionario");
    throw "Acesso negado a Funcionario.alteraRegistro";
  }
  else
  {
    this->registro.push_back(valData);
    this->setEstadoAtivo(!estadoAtivo);
  }
}

void Funcionario::demiteFuncionario()
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.demiteFuncionario"))
  {
    PermissaoNegada *a = new PermissaoNegada("demiteFuncionario", "Funcionario");
    throw "Acesso negado a Funcionario.demiteFuncionario";
  }
  else
  {
    LogEscrita *a = new LogEscrita("estadoAtivo", to_string(estadoAtivo), to_string(false), "Funcionario");
    this->estadoAtivo = false;
  }
}

void Funcionario::promocao(Data valData, float valPercentual)
{
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.promocao"))
  {
    PermissaoNegada *a = new PermissaoNegada("promocao", "Funcionario");
    throw "Acesso negado a Funcionario.promocao";
  }
  else
  {
    this->setSalario(valData, this->getSalario().getValor() * (1 + valPercentual/100));
    this->alteraRegistro(valData);
  }
}

void Funcionario::reajuste(Data valData, float valDissidio){
  if(false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.reajuste"))
  {
    PermissaoNegada *a = new PermissaoNegada("reajuste", "Funcionario");
    throw "Acesso negado a Funcionario.reajuste";
  }
  else
  {
    string salarioAntes = to_string(salario.getValor());
    this->salario.setDissidio(valData, valDissidio);
    LogEscrita *a = new LogEscrita("salario", salarioAntes, to_string(salario.getValor()), "Funcionario");
  }
}