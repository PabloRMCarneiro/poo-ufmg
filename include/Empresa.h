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

using namespace std;

class Empresa
{
  static Empresa* empresa;
  static Empresa* getEmpresa();
  static bool getAcesso(string, Usuario*);

  private:
    Usuario* usuarioLogado;
    vector <Departamento> departamentos;
    vector <Funcionario> funcionarios;
    vector <Cliente> clientes;
    vector <Cargo> cargos;
    vector <RegistroVendas> registrosVendas;
    Empresa();

  public:
    void login(Usuario* valUsuario);
    Usuario* getUsuario();
    Cargo* getCargo();
    Departamento* getDepartamento();
    Cliente* getCliente();
    Funcionario* getFuncionario();
    RegistroVendas* getRegistroVendas();

    void setUsuario();
    void setCargo(string valCargo);
    void setDepartamento(string valDepartamento);
    void setCliente(string valCliente);
    void setFuncionario(string valFuncionario);
    void setRegistroVendas(Data valData, Produto* valProduto, Cliente* valCliente);

};


#endif