#include "../include/Empresa.h"


using namespace std;

Empresa *Empresa::empresa = new Empresa();

Empresa::Empresa()
{
}

Empresa *Empresa::getEmpresa()
{
/*   if(!Empresa::getEmpresa()->getAcesso("Empresa.Empresa"))
  {
    throw "Acesso negado";
  }
  else
  { */
    return empresa;
  //}
}

bool Empresa::getAcesso(string valFuncoes)
{
  if(empresa->usuarioLogado->getPermissoes(valFuncoes)) return true;
  else return false;
}

void Empresa::login(Usuario *valUsuario)
{
  empresa->usuarioLogado = valUsuario;
}
 
Usuario* Empresa::getUsuario()
{
  if(!Empresa::getEmpresa()->getAcesso("Empresa.getUsuario"))
  {
    throw "Acesso negado a Empresa->getUsuario";
  }
  else
    return empresa->usuarioLogado;
}

void Empresa::setUsuario(Usuario *valUsuario)
{
  empresa->usuarioLogado = valUsuario;
}

 Cargo * Empresa::getCargo(Cargo *valCargo)
{
  if(!Empresa::getEmpresa()->getAcesso("Empresa.getCargo"))
  {
    throw "Acesso negado a Empresa->getCargo";
  }
  else
  {
    for (int i = 0; i < empresa->cargos.size(); i++)
    {
      if (empresa->cargos[i]->getNome() == valCargo->getNome())
      {
        return empresa->cargos[i];
      }
    }
    return nullptr;
  }
}

void Empresa::setCargo(Cargo *valCargo)
{
  empresa->cargos.push_back(valCargo);
}

Departamento *Empresa::getDepartamento(string name)
{

  if(!Empresa::getEmpresa()->getAcesso("Empresa.getDepartamento"))
  {
    throw "Acesso negado a Empresa->getDepartamento";
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

void Empresa::setDepartamento(Departamento *valDepartamento)
{
  empresa->departamentos.push_back(valDepartamento);
}

Cliente *Empresa::getCliente(string doc)
{

  if(!Empresa::getEmpresa()->getAcesso("Empresa.getCliente"))
  {
    throw "Acesso negado a Empresa->getCliente";
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

void Empresa::setCliente(Cliente *valCliente)
{
  empresa->clientes.push_back(valCliente);
}

Funcionario *Empresa::getFuncionario(string doc)
{

  if(!Empresa::getEmpresa()->getAcesso("Empresa.getFuncionario"))
  {
    throw "Acesso negado a Empresa->getFuncionario";
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

vector<Funcionario*> Empresa::getFuncionario(){
  return this->funcionarios;
}

void Empresa::setFuncionario(Funcionario *valFuncionario)
{
  empresa->funcionarios.push_back(valFuncionario);
}

RegistroVendas *Empresa::getRegistroVendas(Data valData, Produto* valProduto, Cliente* valCliente)
{

  if(!Empresa::getEmpresa()->getAcesso("Empresa.getRegistroVendas"))
  {
    throw "Acesso negado a Empresa->getRegistroVendas";
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


void Empresa::setRegistroVendas(RegistroVendas *valRegistro)
{
  empresa->registrosVendas.push_back(valRegistro);
}
