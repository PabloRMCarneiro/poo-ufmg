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
  LogLeitura *a = new LogLeitura("registrosVendas", "Empresa");
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
      LogLeitura *a = new LogLeitura("MateriaPrima", "Empresa");
      return it;
    }
  }
  return nullptr;
}

vector<MateriaPrima*> Empresa::getMateriaPrimaLista(){
  LogLeitura *a = new LogLeitura("materiaPrimaLista", "Empresa");
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
  LogLeitura *a = new LogLeitura("ordemDeCompraLista", "Empresa");
  return this->ordemDeCompraLista;
}

vector<OrdemDeProducao*> Empresa::getOrdemDeProducaoLista(){
  LogLeitura *a = new LogLeitura("ordemDeProduçãoLista", "Empresa");
  return this->ordemDeProducaoLista;
}

 Cargo * Empresa::getCargo(string valCargo){
  for (int i = 0; i < empresa->cargos.size(); i++)
  {
    if (empresa->cargos[i]->getNome() == valCargo)
    {
      LogLeitura *a = new LogLeitura("cargos", "Empresa");
      return empresa->cargos[i];
    }
  }
  return nullptr;
}

UsuarioLogado* Empresa::getUsuario(){
  LogLeitura *a = new LogLeitura("usuarioLogado", "Empresa");
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
  LogLeitura *a = new LogLeitura("endereco", "Empresa");
  return this->endereco;
}

Departamento *Empresa::getDepartamento(string name){
  for(auto it : departamentos){
    if(it->getNome() == name){
      LogLeitura *a = new LogLeitura("departamento", "Empresa");
      return it;
    }
  }
  return nullptr;
}
Categoria* Empresa::getCategoria(string valCategoria){
  for(auto it : categorias){
    if(it->getTipo()==valCategoria){
      LogLeitura *a = new LogLeitura("categoria", "Empresa");
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
      LogLeitura *a = new LogLeitura("turno", "Empresa");
      return it;
    }
  }
  return nullptr;
}

vector<Turno*> Empresa::getTurnos(){
  LogLeitura *a = new LogLeitura("turnos", "Empresa");
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
      LogLeitura *a = new LogLeitura("veiculo", "Empresa");
      return it;
    }
  }
  return nullptr;
}

vector<Veiculo*> Empresa::getVeiculos(){
  LogLeitura *a = new LogLeitura("veiculos", "Empresa");
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
      LogLeitura *a = new LogLeitura("cliente", "Empresa");
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
      LogLeitura *a = new LogLeitura("funcionario", "Empresa");
      return it;
    }
  }
  return nullptr;
}

vector<Funcionario*> Empresa::getFuncionarios(){
  LogLeitura *a = new LogLeitura("funcionarios", "Empresa");
  return this->funcionarios;
}

void Empresa::setFuncionario(Funcionario *valFuncionario){
  empresa->funcionarios.push_back(valFuncionario);
}

RegistroVendas *Empresa::getRegistroVendas(Data valData, Produto* valProduto, Cliente* valCliente){
  for(auto it : registrosVendas){
    if((it->getDataDeVenda() == valData) && (it->getProduto() == valProduto) && (it->getCliente()== valCliente)){
      LogLeitura *a = new LogLeitura("registroVendas", "Empresa");
      return it;
    }
  }
  return nullptr;
}


void Empresa::setRegistroVendas(RegistroVendas *valRegistro){
  empresa->registrosVendas.push_back(valRegistro);
}
