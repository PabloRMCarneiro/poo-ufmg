#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED
#include <vector>
#include <string>

#include "UsuarioLogado.h"
#include "Departamento.h"
#include "Funcionario.h"
#include "Cliente.h"
#include "Cargo.h"
#include "RegistroVendas.h"
#include "data.h"
#include "LogEscrita.h" 
#include "LogLeitura.h"
#include "Turno.h"
#include "Veiculo.h"
#include "MateriaPrima.h"
#include "OrdemDeCompra.h"
#include "PermissaoNegada.h"
#include "OrdemDeProducao.h"
#include "Categoria.h"

using namespace std;

class Empresa
{
  private:
    static Empresa* empresa;
    UsuarioLogado* usuarioLogado;
    Endereco endereco;
    vector <Cargo*> cargos;
    vector <Categoria*> categorias;
    vector <Departamento*> departamentos;
    vector <Cliente*> clientes;
    vector <Funcionario*> funcionarios;
    vector <RegistroVendas*> registrosVendas;
    vector <LogEscrita*> logsEscrita;
    vector <LogLeitura*> logsLeitura;
    vector <Turno*> turnos;
    vector <Veiculo*> veiculos; 
    vector <MateriaPrima*> materiaPrimaLista;
    vector <OrdemDeCompra*> ordemDeCompraLista;
    vector <OrdemDeProducao*> ordemDeProducaoLista;
    vector <PermissaoNegada*> logsAcessoNegado; 

    Empresa();

  public:
    static Empresa* getEmpresa();
    void login(UsuarioLogado* valUsuario);
    
    Categoria* getCategoria(string valCategoria);
    void excluiFuncionario(Funcionario *valFuncionario);
    MateriaPrima* getMateriaPrima(string valMateriaPrima);
    vector<MateriaPrima*> getMateriaPrimaLista();
    Turno* getTurno(string valTurno);
    vector<Turno*> getTurnos();
    Veiculo* getVeiculo(Turno* valTurno);
    vector<Veiculo*> getVeiculos();
    UsuarioLogado* getUsuario();
    Cargo* getCargo(string valCargo);
    Departamento* getDepartamento(string name);
    Cliente* getCliente(string doc);
    Funcionario* getFuncionario(string doc);
    vector<Funcionario*> getFuncionarios();
    RegistroVendas* getRegistroVendas(Data valData, Produto* valProduto, Cliente* valCliente);
    vector <LogEscrita*> getlogsEscrita();
    vector <LogLeitura*> getlogsLeitura();
    Endereco getEndereco();
    vector<OrdemDeCompra*> getOrdemDeCompraLista();
    vector<OrdemDeProducao*> getOrdemDeProducaoLista();
    vector<LogLeitura*> getLogLeitura();
    vector<LogEscrita*> getLogEscrita();
    vector<PermissaoNegada*> getLogAcesso(); 
    vector<RegistroVendas*> getRegistrosVendas();

    void setCategoria(Categoria* valCategoria);
    void setOrdemDeCompra(OrdemDeCompra* valOrdemDeCompra);
    void setOrdemDeProducao(OrdemDeProducao* valOrdemDeProducao);
    void setMateriaPrima(MateriaPrima* valMateriaPrima);
    void setMateriaPrimaLista(vector<MateriaPrima*> valMateriaPrima);
    void setEndereco(Endereco valEndereco);
    void setTurno(Turno* valTurno);
    void setTurnos(vector<Turno*> valTurnos);
    void setVeiculo(Veiculo* valVeiculo);
    void setVeiculos(vector<Veiculo*> valVeiculos);
    void setlogEscrita(LogEscrita* valLogEscrita);
    void setlogLeitura(LogLeitura* valLogLeitura);
    void setlogAcessoNegado(PermissaoNegada* valPermissaoNegada);
    void setCargo(Cargo* valCargo);
    void setDepartamento(Departamento* valDepartamento);
    void setCliente(Cliente* valCliente);
    void setFuncionario(Funcionario* valFuncionario);
    void setRegistroVendas(RegistroVendas* valRegistro);  
};


#endif