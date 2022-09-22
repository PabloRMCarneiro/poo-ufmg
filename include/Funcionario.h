#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED
#include "Pessoa.h"
#include "Salario.h"
#include "Departamento.h"
#include "Cargo.h"
#include <string>
#include <vector>

/* Relacionamentos:
   1 - Funcionario tem 1 Salario
   2 - Departamento tem 1 ou mais Funcionarios
   3 - Cargo tem 1 ou mais Funcionarios  
*/

using namespace std;

class Funcionario : public Pessoa
{
  private:
    Departamento departamento;
    Data dataNascimento;
    Salario salario;
    vector <Data> registro;
    Cargo cargo;
    bool estadoAtivo;

    
  public:
    Funcionario();
    Funcionario(Departamento valDepartamento, Data valDataNascimento, Salario valSalario, vector <Data> valRegistro,Cargo valCargo, bool valEstadoAtivo);
    virtual ~Funcionario();

    //Metodos get:
    Departamento getDepartamento();
    Data getDataNascimento();
    Salario getSalario();
    vector <Data> getRegistro();
    Cargo getCargo();
    bool getEstadoAtivo();

    //Metodos set:
    void setDepartamento(Departamento valDepartamento);
    void setDataNascimento(Data valDataNascimento);
    void setSalario(Salario valSalario);
    void setRegistro(vector <Data> valRegistro);
    void setCargo(Cargo valCargo);
    void setEstadoAtivo(bool valEstadoAtivo);

    //Metodos:  
    void alteraRegistro(Data valData);
    void demiteFuncionario();
    void alteraSalario(float valPercentual);  
  
};
 
#endif