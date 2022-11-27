#include "../include/Empresa.h"
#include "../include/LogEscrita.h"
#include "../include/LogLeitura.h"

using namespace std;

Empresa *Empresa::empresa = nullptr;

Empresa::Empresa(){

}

Empresa *Empresa::getEmpresa(){
  if(empresa ==nullptr){
    empresa = new Empresa;
  }
  return empresa;
}

vector <LogEscrita*> Empresa::getlogsEscrita(){
  return this->logsEscrita;
}
vector<RegistroVendas*> Empresa::getRegistrosVendas(){
  return this->registrosVendas;
}
vector <LogLeitura*> Empresa::getlogsLeitura(){
  return this->logsLeitura;
}
void Empresa::setlogAcessoNegado(PermissaoNegada* valPermissaoNegada){
  this->logsAcessoNegado.push_back(valPermissaoNegada);
}
vector<PermissaoNegada*> Empresa::getLogAcesso(){
  return this->logsAcessoNegado;
}
MateriaPrima* Empresa::getMateriaPrima(string valMateriaPrima){
  for(auto it : this->materiaPrimaLista){
    if(it->getNome() == valMateriaPrima){
      return it;
    }
  }
  return nullptr;
}

vector<MateriaPrima*> Empresa::getMateriaPrimaLista(){
  return this->materiaPrimaLista;
}

void Empresa::setMateriaPrima(MateriaPrima* valMateriaPrima){
  this->materiaPrimaLista.push_back(valMateriaPrima);
}

void Empresa::setMateriaPrimaLista(vector<MateriaPrima*> valMateriaPrima){
  this->materiaPrimaLista = valMateriaPrima;
}

void Empresa::setOrdemDeCompra(OrdemDeCompra* valOrdemDeCompra){
  this->ordemDeCompraLista.push_back(valOrdemDeCompra);
}

void Empresa::setOrdemDeProducao(OrdemDeProducao* valOrdemDeProducao){
  this->ordemDeProducaoLista.push_back(valOrdemDeProducao);
}

vector<OrdemDeCompra*> Empresa::getOrdemDeCompraLista(){
  return this->ordemDeCompraLista;
}

vector<OrdemDeProducao*> Empresa::getOrdemDeProducaoLista(){
  return this->ordemDeProducaoLista;
}

 Cargo * Empresa::getCargo(string valCargo){
  for (int i = 0; i < empresa->cargos.size(); i++)
  {
    if (empresa->cargos[i]->getNome() == valCargo)
    {
      return empresa->cargos[i];
    }
  }
  return nullptr;
}

UsuarioLogado* Empresa::getUsuario(){
  return this->usuarioLogado;
}

void Empresa::login(UsuarioLogado* valUsuario){
  this->usuarioLogado = valUsuario;
}

void Empresa::setlogEscrita(LogEscrita* valLogEscrita){
  this->logsEscrita.push_back(valLogEscrita);
}

void Empresa::setlogLeitura(LogLeitura* valLogLeitura){
  this->logsLeitura.push_back(valLogLeitura);
}

void Empresa::setCargo(Cargo *valCargo)
{
  empresa->cargos.push_back(valCargo);
}

void Empresa::setEndereco(Endereco valEndereco){
  this->endereco = valEndereco;
}

Endereco Empresa::getEndereco(){
  return this->endereco;
}

Departamento *Empresa::getDepartamento(string name){
  for(auto it : departamentos){
    if(it->getNome() == name){
      return it;
    }
  }
  return nullptr;
}
Categoria* Empresa::getCategoria(string valCategoria){
  for(auto it : categorias){
    if(it->getTipo()==valCategoria){
      return it;
    }
  }
  return nullptr;
}
void Empresa::setCategoria(Categoria* valCategoria){
  if(getCategoria(valCategoria->getTipo())==nullptr){
    this->categorias.push_back(valCategoria);
  }
}
Turno* Empresa::getTurno(string valTurno){
  for(auto it : this->turnos){
    if(it->getPeriodo() == valTurno){
      return it;
    }
  }
  return nullptr;
}

vector<Turno*> Empresa::getTurnos(){
  return this->turnos;
}
void Empresa::excluiFuncionario(Funcionario *valFuncionario){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.excluiFuncionario"))
  {
      PermissaoNegada * b = new PermissaoNegada("excluiFuncionario", "Empresa");
      string a = "Acesso negado a Empresa.excluiFuncionario.";
      throw (a);
  }
  else
  {
    for(auto it = funcionarios.begin(); it != funcionarios.end(); it++){
      if(*it == valFuncionario){
        funcionarios.erase(it);
        break;
      }
    }
  }
}

Veiculo* Empresa::getVeiculo(Turno* valTurno){
  for(auto it : this->veiculos){
    if(it->getTurno() == valTurno){
      return it;
    }
  }
  return nullptr;
}

vector<Veiculo*> Empresa::getVeiculos(){
  return this->veiculos;
}

void Empresa::setTurno(Turno* valTurno){
  this->turnos.push_back(valTurno);
}

void Empresa::setTurnos(vector<Turno*> valTurnos){
  this->turnos = valTurnos;
}

void Empresa::setVeiculo(Veiculo* valVeiculo){
  this->veiculos.push_back(valVeiculo);
}

void Empresa::setVeiculos(vector<Veiculo*> valVeiculos){
  this->veiculos = valVeiculos;
}

void Empresa::setDepartamento(Departamento *valDepartamento){
  empresa->departamentos.push_back(valDepartamento);
}

Cliente *Empresa::getCliente(string doc){

  for(auto it : clientes){
    if(it->getDocumento() == doc){
      return it;
    }
  }
  return nullptr;
}

void Empresa::setCliente(Cliente *valCliente){
  empresa->clientes.push_back(valCliente);
}

Funcionario *Empresa::getFuncionario(string doc){
  for(auto it : funcionarios){
    if( it->getDocumento() == doc){
      return it;
    }
  }
  return nullptr;
}

vector<Funcionario*> Empresa::getFuncionarios(){
  return this->funcionarios;
}

void Empresa::setFuncionario(Funcionario *valFuncionario){
  empresa->funcionarios.push_back(valFuncionario);
}

RegistroVendas *Empresa::getRegistroVendas(Data valData, Produto* valProduto, Cliente* valCliente){
  for(auto it : registrosVendas){
    if((it->getDataDeVenda() == valData) && (it->getProduto() == valProduto) && (it->getCliente()== valCliente)){
      return it;
    }
  }
  return nullptr;
}


void Empresa::setRegistroVendas(RegistroVendas *valRegistro){
  empresa->registrosVendas.push_back(valRegistro);
}
