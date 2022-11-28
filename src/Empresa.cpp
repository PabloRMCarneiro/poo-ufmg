#include "../include/Empresa.h"
#include "../include/LogEscrita.h"
#include "../include/LogLeitura.h"
#include "../include/UsuarioLogado.h"

using namespace std;

Empresa *Empresa::empresa = nullptr;

Empresa::Empresa(){}

Empresa *Empresa::getEmpresa(){

  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getEmpresa"))
  {
    PermissaoNegada *a = new PermissaoNegada("getEmpresa", "Empresa");
    string mensagem = "Acesso negado a Empresa.getEmpresa";
    throw mensagem;
  }
  else{
    if(empresa ==nullptr){
      empresa = new Empresa;
    }
    return empresa;
  }
}

vector <LogEscrita*> Empresa::getlogsEscrita(){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getlogsEscrita"))
  {
    PermissaoNegada *a = new PermissaoNegada("getlogsEscrita", "Empresa");
    string mensagem = "Acesso negado a Empresa.getlogsEscrita";
    throw mensagem;
  }
  else{
    LogLeitura *a = new LogLeitura("logsEscrita", "Empresa");
    return this->logsEscrita;
  }
}
vector<RegistroVendas*> Empresa::getRegistrosVendas(){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getRegistrosVendas"))
  {
    PermissaoNegada *a = new PermissaoNegada("getRegistrosVendas", "Empresa");
    string mensagem = "Acesso negado a Empresa.getRegistrosVendas";
    throw mensagem;
  }
  else{
    LogLeitura *a = new LogLeitura("registrosVendas", "Empresa");
    return this->registrosVendas;
  }
}
vector <LogLeitura*> Empresa::getlogsLeitura(){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getlogsLeitura"))
  {
    PermissaoNegada *a = new PermissaoNegada("getlogsLeitura", "Empresa");
    string mensagem = "Acesso negado a Empresa.getlogsLeitura";
    throw mensagem;
  }
  else{
    LogLeitura *a = new LogLeitura("logsLeitura", "Empresa");
    return this->logsLeitura;
  }
}
void Empresa::setlogAcessoNegado(PermissaoNegada* valPermissaoNegada){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setlogAcessoNegado"))
  {
    PermissaoNegada *a = new PermissaoNegada("setlogAcessoNegado", "Empresa");
    string mensagem = "Acesso negado a Empresa.setlogAcessoNegado";
    throw mensagem;
  }
  else{
    this->logsAcessoNegado.push_back(valPermissaoNegada);
  }
}
vector<PermissaoNegada*> Empresa::getLogAcesso(){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getLogAcesso"))
  {
    PermissaoNegada *a = new PermissaoNegada("getLogAcesso", "Empresa");
    string mensagem = "Acesso negado a Empresa.getLogAcesso";
    throw mensagem;
  }
  else{
    LogLeitura *a = new LogLeitura("logsAcessoNegado", "Empresa");
    return this->logsAcessoNegado;
  }
}
MateriaPrima* Empresa::getMateriaPrima(string valMateriaPrima){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getMateriaPrima"))
  {
    PermissaoNegada *a = new PermissaoNegada("getMateriaPrima", "Empresa");
    string mensagem = "Acesso negado a Empresa.getMateriaPrima";
    throw mensagem;
  }
  else{
    for(auto it : this->materiaPrimaLista){
    if(it->getNome() == valMateriaPrima){
        LogLeitura *a = new LogLeitura("materiaPrima", "Empresa");
        return it;
      }
    }
    return nullptr;
  }
  
}

vector<MateriaPrima*> Empresa::getMateriaPrimaLista(){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getMateriaPrimaLista"))
  {
    PermissaoNegada *a = new PermissaoNegada("getMateriaPrimaLista", "Empresa");
    string mensagem = "Acesso negado a Empresa.getMateriaPrimaLista";
    throw mensagem;
  }
  else{
    LogLeitura *a = new LogLeitura("materiaPrimaLista", "Empresa");
    return this->materiaPrimaLista;
  }
}

void Empresa::setMateriaPrima(MateriaPrima* valMateriaPrima){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setMateriaPrima"))
  {
    PermissaoNegada *a = new PermissaoNegada("setMateriaPrima", "Empresa");
    string mensagem = "Acesso negado a Empresa.setMateriaPrima";
    throw mensagem;
  }
  else{
    this->materiaPrimaLista.push_back(valMateriaPrima);
  }
}

void Empresa::setMateriaPrimaLista(vector<MateriaPrima*> valMateriaPrima){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setMateriaPrimaLista"))
  {
    PermissaoNegada *a = new PermissaoNegada("setMateriaPrimaLista", "Empresa");
    string mensagem = "Acesso negado a Empresa.setMateriaPrimaLista";
    throw mensagem;
  }
  else{
    this->materiaPrimaLista = valMateriaPrima;
  }
}

void Empresa::setOrdemDeCompra(OrdemDeCompra* valOrdemDeCompra){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setOrdemDeCompra"))
  {
    PermissaoNegada *a = new PermissaoNegada("setOrdemDeCompra", "Empresa");
    string mensagem = "Acesso negado a Empresa.setOrdemDeCompra";
    throw mensagem;
  }
  else{
    this->ordemDeCompraLista.push_back(valOrdemDeCompra);
  }
}

void Empresa::setOrdemDeProducao(OrdemDeProducao* valOrdemDeProducao){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setOrdemDeProducao"))
  {
    PermissaoNegada *a = new PermissaoNegada("setOrdemDeProducao", "Empresa");
    string mensagem = "Acesso negado a Empresa.setOrdemDeProducao";
    throw mensagem;
  }
  else{
    this->ordemDeProducaoLista.push_back(valOrdemDeProducao);
  }
}

vector<OrdemDeCompra*> Empresa::getOrdemDeCompraLista(){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getOrdemDeCompraLista"))
  {
    PermissaoNegada *a = new PermissaoNegada("getOrdemDeCompraLista", "Empresa");
    string mensagem = "Acesso negado a Empresa.getOrdemDeCompraLista";
    throw mensagem;
  }
  else{
    LogLeitura *a = new LogLeitura("ordemDeCompraLista", "Empresa");
    return this->ordemDeCompraLista;
  }
}

vector<OrdemDeProducao*> Empresa::getOrdemDeProducaoLista(){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getOrdemDeCompraLista"))
  {
    PermissaoNegada *a = new PermissaoNegada("getOrdemDeCompraLista", "Empresa");
    string mensagem = "Acesso negado a Empresa.getOrdemDeCompraLista";
    throw mensagem;
  }
  else{
    LogLeitura *a = new LogLeitura("ordemDeProducaoLista", "Empresa");
    return this->ordemDeProducaoLista;
  }
}

 Cargo * Empresa::getCargo(string valCargo){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getCargo"))
  {
    PermissaoNegada *a = new PermissaoNegada("getCargo", "Empresa");
    string mensagem = "Acesso negado a Empresa.getCargo";
    throw mensagem;
  }
  else{
    for (int i = 0; i < empresa->cargos.size(); i++)
    {
    if (empresa->cargos[i]->getNome() == valCargo)
      {
      LogLeitura *a = new LogLeitura("cargo", "Empresa");
      return empresa->cargos[i];
      }
    }
    return nullptr;
  }
  
}

UsuarioLogado* Empresa::getUsuario(){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getUsuario"))
  {
    PermissaoNegada *a = new PermissaoNegada("getUsuario", "Empresa");
    string mensagem = "Acesso negado a Empresa.getUsuario";
    throw mensagem;
  }
  else{
    LogLeitura *a = new LogLeitura("usuarioLogado", "Empresa");
    return this->usuarioLogado;
  }
}

void Empresa::login(UsuarioLogado* valUsuario){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.login"))
  {
    PermissaoNegada *a = new PermissaoNegada("login", "Empresa");
    string mensagem = "Acesso negado a Empresa.login";
    throw mensagem;
  }
  else{
    this->usuarioLogado = valUsuario;
  }
}

void Empresa::setlogEscrita(LogEscrita* valLogEscrita){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setlogEscrita"))
  {
    PermissaoNegada *a = new PermissaoNegada("setlogEscrita", "Empresa");
    string mensagem = "Acesso negado a Empresa.setlogEscrita";
    throw mensagem;
  }
  else{
    this->logsEscrita.push_back(valLogEscrita);
  }
}

void Empresa::setlogLeitura(LogLeitura* valLogLeitura){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setlogLeitura"))
  {
    PermissaoNegada *a = new PermissaoNegada("setlogLeitura", "Empresa");
    string mensagem = "Acesso negado a Empresa.setlogLeitura";
    throw mensagem;
  }
  else{
    this->logsLeitura.push_back(valLogLeitura);
  }
}

void Empresa::setCargo(Cargo *valCargo){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setCargo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setCargo", "Empresa");
    string mensagem = "Acesso negado a Empresa.setCargo";
    throw mensagem;
  }
  else{
    this->cargos.push_back(valCargo);
  }
}

void Empresa::setEndereco(Endereco valEndereco){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setEndereco"))
  {
    PermissaoNegada *a = new PermissaoNegada("setEndereco", "Empresa");
    string mensagem = "Acesso negado a Empresa.setEndereco";
    throw mensagem;
  }
  else{
    this->endereco = valEndereco;
  }
}

Endereco Empresa::getEndereco(){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getEndereco"))
  {
    PermissaoNegada *a = new PermissaoNegada("getEndereco", "Empresa");
    string mensagem = "Acesso negado a Empresa.getEndereco";
    throw mensagem;
  }
  else{
    LogLeitura *a = new LogLeitura("endereco", "Empresa");
    return this->endereco;
  }
}

Departamento *Empresa::getDepartamento(string name){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getDepartamento"))
  {
    PermissaoNegada *a = new PermissaoNegada("getDepartamento", "Empresa");
    string mensagem = "Acesso negado a Empresa.getDepartamento";
    throw mensagem;
  }
  else{ 
    for(auto it : departamentos){
      if(it->getNome() == name){
        LogLeitura *a = new LogLeitura("departamento", "Empresa");
        return it;
      }
    }
    return nullptr;
  }
}

Categoria* Empresa::getCategoria(string valCategoria){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getCategoria"))
  {
    PermissaoNegada *a = new PermissaoNegada("getCategoria", "Empresa");
    string mensagem = "Acesso negado a Empresa.getCategoria";
    throw mensagem;
  }
  else{
    for(auto it : categorias){
      if(it->getTipo()==valCategoria){
        LogLeitura *a = new LogLeitura("categoria", "Empresa");
        return it;
      }
    }
    return nullptr;
  }
}

void Empresa::setCategoria(Categoria* valCategoria){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setCategoria"))
  {
    PermissaoNegada *a = new PermissaoNegada("setCategoria", "Empresa");
    string mensagem = "Acesso negado a Empresa.setCategoria";
    throw mensagem;
  }
  else{
    if(getCategoria(valCategoria->getTipo())==nullptr){
      this->categorias.push_back(valCategoria);
    }
  }
}

Turno* Empresa::getTurno(string valTurno){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getTurno"))
  {
    PermissaoNegada *a = new PermissaoNegada("getTurno", "Empresa");
    string mensagem = "Acesso negado a Empresa.getTurno";
    throw mensagem;
  }
  else{
    for(auto it : this->turnos){
      if(it->getPeriodo() == valTurno){
        LogLeitura *a = new LogLeitura("turno", "Empresa");
        return it;
      }
    }
    return nullptr;
  }
}

vector<Turno*> Empresa::getTurnos(){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getTurnos"))
  {
    PermissaoNegada *a = new PermissaoNegada("getTurnos", "Empresa");
    string mensagem = "Acesso negado a Empresa.getTurnos";
    throw mensagem;
  }
  else{
    LogLeitura *a = new LogLeitura("turnos", "Empresa");
    return this->turnos;
  }
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
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getVeiculo"))
  {
    PermissaoNegada *a = new PermissaoNegada("getVeiculo", "Empresa");
    string mensagem = "Acesso negado a Empresa.getVeiculo";
    throw mensagem;
  }
  else{
    for(auto it : this->veiculos){
      if(it->getTurno() == valTurno){
        LogLeitura *a = new LogLeitura("veiculo", "Empresa");
        return it;
      }
    }
    return nullptr;
  }
}

vector<Veiculo*> Empresa::getVeiculos(){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getVeiculos"))
  {
    PermissaoNegada *a = new PermissaoNegada("getVeiculos", "Empresa");
    string mensagem = "Acesso negado a Empresa.getVeiculos";
    throw mensagem;
  }
  else{
    LogLeitura *a = new LogLeitura("veiculos", "Empresa");
    return this->veiculos;
  }
}

void Empresa::setTurno(Turno* valTurno){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setTurno"))
  {
    PermissaoNegada *a = new PermissaoNegada("setTurno", "Empresa");
    string mensagem = "Acesso negado a Empresa.setTurno";
    throw mensagem;
  }
  else{
    this->turnos.push_back(valTurno);
  }
}

void Empresa::setTurnos(vector<Turno*> valTurnos){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setTurnos"))
  {
    PermissaoNegada *a = new PermissaoNegada("setTurnos", "Empresa");
    string mensagem = "Acesso negado a Empresa.setTurnos";
    throw mensagem;
  }
  else{
    this->turnos = valTurnos;
  }
}

void Empresa::setVeiculo(Veiculo* valVeiculo){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setVeiculo"))
  {
    PermissaoNegada *a = new PermissaoNegada("setVeiculo", "Empresa");
    string mensagem = "Acesso negado a Empresa.setVeiculo";
    throw mensagem;
  }
  else{
    this->veiculos.push_back(valVeiculo);
  }
}

void Empresa::setVeiculos(vector<Veiculo*> valVeiculos){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setVeiculos"))
  {
    PermissaoNegada *a = new PermissaoNegada("setVeiculos", "Empresa");
    string mensagem = "Acesso negado a Empresa.setVeiculos";
    throw mensagem;
  }
  else{
    this->veiculos = valVeiculos;
  }
}

void Empresa::setDepartamento(Departamento *valDepartamento){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setDepartamento"))
  {
    PermissaoNegada *a = new PermissaoNegada("setDepartamento", "Empresa");
    string mensagem = "Acesso negado a Empresa.setDepartamento";
    throw mensagem;
  }
  else{
    this->departamentos.push_back(valDepartamento);
  }
}

Cliente *Empresa::getCliente(string doc){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getCliente"))
  {
    PermissaoNegada *a = new PermissaoNegada("getCliente", "Empresa");
    string mensagem = "Acesso negado a Empresa.getCliente";
    throw mensagem;
  }
  else{
    for(auto it : clientes){
      if(it->getDocumento() == doc){
        LogLeitura *a = new LogLeitura("cliente", "Empresa");
        return it;
      }
    }
    return nullptr;
  }
}

void Empresa::setCliente(Cliente *valCliente){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setCliente"))
  {
    PermissaoNegada *a = new PermissaoNegada("setCliente", "Empresa");
    string mensagem = "Acesso negado a Empresa.setCliente";
    throw mensagem;
  }
  else{
    empresa->clientes.push_back(valCliente);
  }
}

Funcionario *Empresa::getFuncionario(string doc){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getFuncionario"))
  {
    PermissaoNegada *a = new PermissaoNegada("getFuncionario", "Empresa");
    string mensagem = "Acesso negado a Empresa.getFuncionario";
    throw mensagem;
  }
  else{
    for(auto it : funcionarios){
    if( it->getDocumento() == doc){
      LogLeitura *a = new LogLeitura("funcionario", "Empresa");
      return it;
      }
    }
    return nullptr;
  }
  
}

vector<Funcionario*> Empresa::getFuncionarios(){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getFuncionarios"))
  {
    PermissaoNegada *a = new PermissaoNegada("getFuncionarios", "Empresa");
    string mensagem = "Acesso negado a Empresa.getFuncionarios";
    throw mensagem;
  }
  else{
    LogLeitura *a = new LogLeitura("funcionarios", "Empresa");
    return this->funcionarios;
  }
}

void Empresa::setFuncionario(Funcionario *valFuncionario){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setFuncionario"))
  {
    PermissaoNegada *a = new PermissaoNegada("setFuncionario", "Empresa");
    string mensagem = "Acesso negado a Empresa.setFuncionario";
    throw mensagem;
  }
  else{
    empresa->funcionarios.push_back(valFuncionario);
  }
}

RegistroVendas *Empresa::getRegistroVendas(Data valData, Produto* valProduto, Cliente* valCliente){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.getRegistroVendas"))
  {
    PermissaoNegada *a = new PermissaoNegada("getRegistroVendas", "Empresa");
    string mensagem = "Acesso negado a Empresa.getRegistroVendas";
    throw mensagem;
  }
  else{
    for(auto it : registrosVendas){
      if((it->getDataDeVenda() == valData) && (it->getProduto() == valProduto) && (it->getCliente()== valCliente)){
        LogLeitura *a = new LogLeitura("registroVendas", "Empresa");
        return it;
      }
    }
    return nullptr;
  }
}


void Empresa::setRegistroVendas(RegistroVendas *valRegistro){
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Empresa.setRegistroVendas"))
  {
    PermissaoNegada *a = new PermissaoNegada("setRegistroVendas", "Empresa");
    string mensagem = "Acesso negado a Empresa.setRegistroVendas";
    throw mensagem;
  }
  else{
    empresa->registrosVendas.push_back(valRegistro);
  }
}