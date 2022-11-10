#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED
#include <vector>
#include <string>

#include "./Usuario.h"
#include "./Departamento.h"
#include "./Funcionario.h"
#include "./Cliente.h"
#include "./Cargo.h"
#include "./RegistroVendas.h"
#include "./data.h"
#include "./LogEscrita.h" 
#include "./LogLeitura.h"
#include "./Turno.h"
#include "./Veiculo.h"

using namespace std;

class Empresa
{
  private:
    static Empresa* empresa;
    Usuario* usuarioLogado;
    vector <Cargo*> cargos;
    vector <Departamento*> departamentos;
    vector <Cliente*> clientes;
    vector <Funcionario*> funcionarios;
    vector <RegistroVendas*> registrosVendas;
    vector <LogEscrita*> logsEscrita;
    vector <LogLeitura*> logsLeitura;
    vector <Turno*> turnos;
    vector <Veiculo*> veiculos; 
    //vector <AcessoNegado*> logsAcessoNegado; 

    Empresa();

  public:
    static bool getAcesso(string valFuncoes) ;
    static Empresa* getEmpresa();
    void login(Usuario* valUsuario);
    
    Turno* getTurno(string valTurno);
    vector<Turno*> getTurnos();
    Veiculo* getVeiculo(Turno* valTurno);
    vector<Veiculo*> getVeiculos();
    Usuario* getUsuario();
    Cargo* getCargo(string valCargo);
    Departamento* getDepartamento(string name);
    Cliente* getCliente(string doc);
    Funcionario* getFuncionario(string doc);
    vector<Funcionario*> getFuncionario();
    RegistroVendas* getRegistroVendas(Data valData, Produto* valProduto, Cliente* valCliente);
    vector <LogEscrita*> getlogsEscrita();
    vector <LogLeitura*> getlogsLeitura();
    /* 
    vector<Log> getLogLeitura();
    vector<Log> getLogEscrita();
    vector<Log> getLogAcesso(); 
    */
    void setTurno(Turno* valTurno);
    void setTurnos(vector<Turno*> valTurnos);
    void setVeiculo(Veiculo* valVeiculo);
    void setVeiculos(vector<Veiculo*> valVeiculos);
    void setlogEscrita(map<string, string>, map<string, string>, Data, string);
    void setlogLeitura(string, Data, string);
    void setUsuario(Usuario* valUsuario);
    void setCargo(Cargo* valCargo);
    void setDepartamento(Departamento* valDepartamento);
    void setCliente(Cliente* valCliente);
    void setFuncionario(Funcionario* valFuncionario);
    void setRegistroVendas(RegistroVendas* valRegistro);  
};


#endif