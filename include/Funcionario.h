#ifndef FUNCIONARIO_H_INCLUDED
#define FUNCIONARIO_H_INCLUDED
#include "Pessoa.h"
#include "Salario.h"
#include "Departamento.h"
#include "Turno.h"
#include "Cargo.h"
#include <string>
#include <vector>
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
    Turno* jornada;
    int idVeiculo;


  public:
    Funcionario();
    Funcionario(string valNome, Endereco valEndereco, string valEmail, string valDocumento, long int valTelefone, Departamento valDepartamento, Data valDataNascimento, Salario valSalario, vector <Data> valRegistro,Cargo valCargo, bool valEstadoAtivo);
    Departamento getDepartamento();
    Data getDataNascimento();
    Salario getSalario();
    vector <Data> getRegistro();
    Cargo getCargo();
    bool getEstadoAtivo();
    Turno* getJornada();
    int getIdVeiculo();

    void setJornada(Turno* valJornada);
    void setIdVeiculo(int valIdVeiculo);
    void setDepartamento(Departamento valDepartamento);
    void setDataNascimento(Data valDataNascimento);
    void setSalario(Data valData, Salario valSalario);
    void setRegistro(vector <Data> valRegistro);
    void setCargo(Cargo valCargo);
    void setEstadoAtivo(bool valEstadoAtivo);
    
    void alteraRegistro(Data valData);
    void demiteFuncionario();
    void promocao(Data valData, float valPercentual); 
    void reajuste(Data valData, float valDissidio);
};
 
#endif