#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED
#include <vector>
#include <string>
#include "./Departamento.h"
#include "./Funcionario.h"
#include "./Cliente.h"
#include "./Cargo.h"
#include "./RegistroVendas.h"
#include "./Usuario.h"
#include "./data.h"
#include "./Log.h"

using namespace std;

class Empresa
{
  private:
    static Empresa* empresa;
    Usuario* usuarioLogado;
    vector <Departamento*> departamentos;
    vector <Funcionario*> funcionarios;
    vector <Cliente*> clientes;
    vector <Cargo*> cargos;
    vector <RegistroVendas*> registrosVendas;
    vector <Log> logsEscrita;
    vector <Log> logsLeitura;
    vector <Log> logsAcessoNegado;

    Empresa();

  public:
    static bool getAcesso(string valFuncoes) ;
    static Empresa* getEmpresa();
    void login(Usuario* valUsuario);
    
    Usuario* getUsuario();
    Cargo* getCargo(string name);
    Departamento* getDepartamento(string name);
    Cliente* getCliente(string doc);
    Funcionario* getFuncionario(string doc);
    vector<Funcionario*> getFuncionario();
    RegistroVendas* getRegistroVendas(Data valData, Produto* valProduto, Cliente* valCliente);
    vector<Log> getLogLeitura();
    vector<Log> getLogEscrita();
    vector<Log> getLogAcesso();

    void setUsuario();
    void setCargo(Cargo* valCargo);
    void setDepartamento(Departamento* valDepartamento);
    void setCliente(Cliente* valCliente);
    void setFuncionario(Funcionario* valFuncionario);
    void setRegistroVendas(RegistroVendas* valRegistro);

};


#endif