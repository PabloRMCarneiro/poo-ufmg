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
  if(!Empresa::getEmpresa()->getAcesso("Empresa.Empresa"))
  {
    throw "Acesso negado";
  }
  else
  {
    return empresa;
  }
}

bool Empresa::getAcesso(string valFuncoes)
{
  if(!Empresa::getEmpresa()->getAcesso("Empresa.Empresa"))
  {
    throw "Acesso negado";
  }
  else
    return empresa->usuarioLogado->getPermissoes(valFuncoes);
}

void Empresa::login(Usuario *valUsuario)
{
  empresa->usuarioLogado = valUsuario;
}

Usuario* Empresa::getUsuario()
{
  if(!Empresa::getEmpresa()->getAcesso("Empresa.Empresa"))
  {
    throw "Acesso negado";
  }
  else
    return empresa->usuarioLogado;
}

Cargo* Empresa::getCargo(string name)
{ 
  if(!Empresa::getEmpresa()->getAcesso("Empresa.Empresa"))
  {
    throw "Acesso negado";
  }
  else 
  {
    for(auto it : cargos){
      if(it->getNome() == name){
        return it;
      } 
    }
    return nullptr;
  }

}

Departamento *Empresa::getDepartamento(string name)
{

  if(!Empresa::getEmpresa()->getAcesso("Empresa.Empresa"))
  {
    throw "Acesso negado";
  }
  else 
  {
    for(auto it : departamentos){
      if(it->getNome() == name){
        return it;
    }
  }
  return nullptr;
  }
}

Cliente *Empresa::getCliente(string doc)
{

  if(!Empresa::getEmpresa()->getAcesso("Empresa.Empresa"))
  {
    throw "Acesso negado";
  }
  else 
  {
    for(auto it : clientes){
      if(it->getDocumento() == doc){
        return it;
    }
  }
  return nullptr;
  }
}

Funcionario *Empresa::getFuncionario(string doc)
{

  if(!Empresa::getEmpresa()->getAcesso("Empresa.Empresa"))
  {
    throw "Acesso negado";
  }
  else 
  {
    for(auto it : funcionarios){
      if( it->getDocumento() == doc){
        return it;
      }
    }
    return nullptr;
  }
}

RegistroVendas *Empresa::getRegistroVendas(Data valData, Produto* valProduto, Cliente* valCliente)
{

  if(!Empresa::getEmpresa()->getAcesso("Empresa.Empresa"))
  {
    throw "Acesso negado";
  }
  else 
  {
    for(auto it : registrosVendas){
    if((it->getDataDeVenda() == valData) && (it->getProduto() == valProduto) && (it->getCliente()== valCliente)){
      return it;
    }
  }
  return nullptr;
  }
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
