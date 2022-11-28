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

using namespace std;


Funcionario::Funcionario():Pessoa()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.Funcionario"))
  {
    PermissaoNegada *a = new PermissaoNegada("Funcionario", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.Funcionario";
    throw mensagem;
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
    PermissaoNegada *a = new PermissaoNegada("Funcionario", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.Funcionario";
    throw mensagem;
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

Departamento Funcionario::getDepartamento()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getDepartamento"))
  {
    PermissaoNegada *a = new PermissaoNegada("getDepartamento", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.getDepartamento";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("departamento", "Funcionario");
    return this->departamento;
  }
}

Data Funcionario::getDataNascimento()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getDataNascimento"))
  {
    PermissaoNegada *a = new PermissaoNegada("getDataNascimento", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.getDataNascimento";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("dataNascimento", "Funcionario");
    return this->dataNascimento;
  }
}

Salario Funcionario::getSalario()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getSalario"))
  {
    PermissaoNegada *a = new PermissaoNegada("getSalario", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.getSalario";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("salario", "Funcionario");
    return this->salario;
  }
}

vector <Data> Funcionario::getRegistro()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getRegistro"))
  {
    PermissaoNegada *a = new PermissaoNegada("getRegistro", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.getRegistro";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("registro", "Funcionario");
    return this->registro;
  }
}

Cargo Funcionario::getCargo()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getCargo"))
  {
    PermissaoNegada *a = new PermissaoNegada("getCargo", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.getCargo";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("cargo", "Funcionario");
    return this->cargo;
  }
}

bool Funcionario::getEstadoAtivo()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getEstadoAtivo"))
  {
    PermissaoNegada *a = new PermissaoNegada("getEstadoAtivo", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.getEstadoAtivo";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("estadoAtivo", "Funcionario");
    return this->estadoAtivo;
  }
}

Turno* Funcionario::getJornada()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getJornada"))
  {
    PermissaoNegada *a = new PermissaoNegada("getJornada", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.getJornada";
    throw mensagem;
    
  }
  else
  {
    LogLeitura *a = new LogLeitura("jornada", "Funcionario");
    return this->jornada;
  }
}

int Funcionario::getIdVeiculo()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.getIdVeiculo"))
  {
    PermissaoNegada *a = new PermissaoNegada("getIdVeiculo", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.getIdVeiculo";
    throw mensagem;
  }
  else
  {
    LogLeitura *a = new LogLeitura("idVeiculo", "Funcionario");
    return this->idVeiculo;
  }
}

void Funcionario::setJornada(Turno* valJornada)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.setJornada"))
  {
    PermissaoNegada *a = new PermissaoNegada("setJornada", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.setJornada";
    throw mensagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("salario", "indefinido", valJornada->getPeriodo(), "Funcionario");
    this->jornada = valJornada;
  }
}

void Funcionario::setIdVeiculo(int valIdVeiculo)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.setIdVeiculo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setIdVeiculo", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.setIdVeiculo";
    throw mensagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("idVeiculo", to_string(this->idVeiculo), to_string(valIdVeiculo), "Funcionario");
    this->idVeiculo = valIdVeiculo;
  }
}

void Funcionario::setDepartamento(Departamento valDepartamento)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.setDepartamento"))
  {
    PermissaoNegada *a = new PermissaoNegada("setDepartamento", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.setDepartamento";
    throw mensagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("salario", departamento.getNome(), valDepartamento.getNome(), "Funcionario");
    this->departamento = valDepartamento;
  }
}

void Funcionario::setDataNascimento(Data valDataNascimento)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.setDataNascimento"))
  {
    PermissaoNegada *a = new PermissaoNegada("setDepartamento", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.setDataNascimento";
    throw mensagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("salario", dataNascimento.getData(), valDataNascimento.getData(), "Funcionario");
    this->dataNascimento = valDataNascimento;
  }
}

void Funcionario::setSalario(Data valData, Salario valSalario)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.setSalario"))
  {
    PermissaoNegada *a = new PermissaoNegada("setSalario", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.setSalario";
    throw mensagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("salario", to_string(salario.getValor()), to_string(valSalario.getValor()), "Funcionario");
    this->salario = valSalario;
  }
}

void Funcionario::setRegistro(vector <Data> valRegistro)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.setRegistro"))
  {
    PermissaoNegada *a = new PermissaoNegada("setRegistro", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.setRegistro";
    throw mensagem;
  }
  else
  {
    this->registro = valRegistro;
  }
}

void Funcionario::setCargo(Cargo valCargo)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.setCargo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setCargo", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.setCargo";
    throw mensagem;
  }
  else
  {
    LogEscrita *f = new LogEscrita("cargo", cargo.getNome(), valCargo.getNome(), "Funcionario");
    this->cargo = valCargo;
  }
}

void Funcionario::setEstadoAtivo(bool valEstadoAtivo)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.setEstadoAtivo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setEstadoAtivo", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.setEstadoAtivo";
    throw mensagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("estadoAtivo", to_string(estadoAtivo), to_string(valEstadoAtivo), "Funcionario");
    this->estadoAtivo = valEstadoAtivo;
  }
}

void Funcionario::alteraRegistro(Data valData)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.alteraRegistro"))
  {
    PermissaoNegada *a = new PermissaoNegada("alteraRegistro", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.alteraRegistro";
    throw mensagem;
  }
  else
  {
    this->registro.push_back(valData);
    this->setEstadoAtivo(!estadoAtivo);
  }
}

void Funcionario::demiteFuncionario()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.demiteFuncionario"))
  {
    PermissaoNegada *a = new PermissaoNegada("demiteFuncionario", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.demiteFuncionario";
    throw mensagem;
  }
  else
  {
    LogEscrita *a = new LogEscrita("estadoAtivo", to_string(estadoAtivo), to_string(false), "Funcionario");
    this->estadoAtivo = false;
  }
}

void Funcionario::promocao(Data valData, float valPercentual)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Funcionario.promocao"))
  {
    PermissaoNegada *a = new PermissaoNegada("promocao", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.promocao";
    throw mensagem;
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
    PermissaoNegada *a = new PermissaoNegada("reajuste", "Funcionario");
    string mensagem = "Acesso negado a Funcionario.reajuste";
    throw mensagem;
  }
  else
  {
    string salarioAntes = to_string(salario.getValor());
    this->salario.setDissidio(valData, valDissidio);
    LogEscrita *a = new LogEscrita("salario", salarioAntes, to_string(salario.getValor()), "Funcionario");
  }
}