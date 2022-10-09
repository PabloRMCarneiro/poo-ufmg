#include "../include/Empresa.h"
#include "../include/Departamento.h"
#include "../include/Funcionario.h"
#include "../include/Cliente.h"
#include "../include/Cargo.h"
#include "../include/RegistroVendas.h"
#include "../include/Usuario.h"
#include "../include/data.h"

using namespace std;

Empresa *Empresa::empresa = new Empresa();

Empresa::Empresa()
{
}

Empresa *Empresa::getEmpresa()
{
  return empresa;
}

bool Empresa::getAcesso(string valFuncoes)
{
  return empresa->usuarioLogado->getPermissoes(valFuncoes);
}

void Empresa::login(Usuario *valUsuario)
{
  empresa->usuarioLogado = valUsuario;
}

Usuario* Empresa::getUsuario()
{
  return empresa->usuarioLogado;
}

Cargo* Empresa::getCargo()
{
  return empresa->cargos;
}

Departamento *Empresa::getDepartamento()
{
  return empresa->departamentos;
}

Cliente *Empresa::getCliente()
{
  return empresa->clientes;
}

Funcionario *Empresa::getFuncionario()
{
  return empresa->funcionarios;
}

RegistroVendas *Empresa::getRegistroVendas()
{
  return empresa->registrosVendas;
}

void Empresa::setUsuario()
{
  empresa->usuarioLogado = new Usuario();
}

void Empresa::setCargo(Cargo *valCargo)
{
  empresa->cargos.push_back(valCargo);
}

void Empresa::setDepartamento(Departamento *valDepartamento)
{
  empresa->departamentos.push_back(valDepartamento);
}

void Empresa::setCliente(Cliente *valCliente)
{
  empresa->clientes.push_back(valCliente);
}

void Empresa::setFuncionario(Funcionario *valFuncionario)
{
  empresa->funcionarios.push_back(valFuncionario);
}

void Empresa::setRegistroVendas(RegistroVendas *valRegistro)
{
  empresa->registrosVendas.push_back(valRegistro);
}
