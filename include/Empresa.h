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

  private:
    static Empresa* empresa;
    Usuario* usuarioLogado;
    vector <Departamento> departamentos;
    vector <Funcionario> funcionarios;
    vector <Cliente> clientes;
    vector <Cargo> cargos;
    vector <RegistroVendas> registrosVendas;
    Empresa();

  public:
  static bool getAcesso(string, Usuario*);
  static Empresa* getEmpresa();
    void login(Usuario* valUsuario);
    Usuario* getUsuario();
    Cargo* getCargo();
    Departamento* getDepartamento();
    Cliente* getCliente();
    Funcionario* getFuncionario();
    RegistroVendas* getRegistroVendas();

    void setUsuario();
    void setCargo(Cargo* valCargo);
    void setDepartamento(Departamento* valDepartamento);
    void setCliente(Cliente* valCliente);
    void setFuncionario(Funcionario* valFuncionario);
    void setRegistroVendas(RegistroVendas* valRegistro)

};


#endif