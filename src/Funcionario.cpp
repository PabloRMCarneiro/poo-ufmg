#include "../include/Funcionario.h"
#include "../include/Pessoa.h"
#include "../include/data.h"
#include "../include/Salario.h"
#include "../include/Cargo.h"
#include "../include/Departamento.h"
#include <string>
#include <vector>

using namespace std;

/**
 * Funcionario::Funcionario()
 * 
 * This is a constructor for the class Funcionario. It initializes the class attributes to default
 * values
 */
Funcionario::Funcionario()
{
  this->departamento = Departamento();
  this->dataNascimento = Data();
  this->salario = Salario();
  this->registro = vector <Data>();
  this->cargo = Cargo();
  this->estadoAtivo = false;
}
/**
 * Funcionario::Funcionario(Departamento valDepartamento, Data valDataNascimento, Salario valSalario,
 * vector <Data> valRegistro,Cargo valCargo, bool valEstadoAtivo)
 * 
 * @param valDepartamento
 * @param valDataNascimento
 * @param valSalario
 * @param valRegistro
 * @param valCargo enum
 * @param valEstadoAtivo
 */
Funcionario::Funcionario(Departamento valDepartamento, Data valDataNascimento, Salario valSalario, vector <Data> valRegistro,Cargo valCargo, bool valEstadoAtivo)
{
  this->departamento = valDepartamento;
  this->dataNascimento = valDataNascimento;
  this->salario = valSalario;
  this->registro = valRegistro;
  this->cargo = valCargo;
  this->estadoAtivo = valEstadoAtivo;
}
/**
 * The destructor is called when the object is destroyed
 */
Funcionario::~Funcionario()
{
}
/**
 * It returns the department of the employee.
 * 
 * @return the value of the attribute departamento.
 */
Departamento Funcionario::getDepartamento()
{
  return this->departamento;
}
/**
 * It returns the dataNascimento variable.
 * 
 * @return The dataNascimento variable.
 */
Data Funcionario::getDataNascimento()
{
  return this->dataNascimento;
}
/**
 * It returns the salary of the employee.
 * 
 * @return The salary of the employee.
 */
Salario Funcionario::getSalario()
{
  return this->salario;
}
/**
 * It returns the vector of Data objects.
 * 
 * @return A vector of Data objects.
 */
vector <Data> Funcionario::getRegistro()
{
  return this->registro;
}
/**
 * It returns the cargo of the employee.
 * 
 * @return A Cargo object.
 */
Cargo Funcionario::getCargo()
{
  return this->cargo;
}
/**
 * It returns the value of the variable estadoAtivo.
 * 
 * @return the value of the variable estadoAtivo.
 */
bool Funcionario::getEstadoAtivo()
{
  return this->estadoAtivo;
}
/**
 * The function sets the name of the department of the employee
 * 
 * @param valDepartamento
 */
void Funcionario::setDepartamento(Departamento valDepartamento)
{
  this->departamento.setNome(valDepartamento.getNome());
}
/**
 * `void Funcionario::setDataNascimento(Data valDataNascimento)`
 * 
 * This function is a member of the class Funcionario. It is a public function. It returns nothing. It
 * takes one parameter, a Data object. It sets the dataNascimento member of the class to the value of
 * the parameter
 * 
 * @param valDataNascimento 
 */
void Funcionario::setDataNascimento(Data valDataNascimento)
{
  this->dataNascimento = valDataNascimento;
}
/**
 * `void Funcionario::setSalario(Salario valSalario)`
 * 
 * The function is called `setSalario` and it takes one parameter of type `Salario` called
 * `valSalario`. The function returns nothing (`void`)
 * 
 * @param valSalario The value of the salary
 */
void Funcionario::setSalario(Salario valSalario)
{
  this->salario = valSalario;
}
/**
 * It sets the value of the vector registro.
 * 
 * @param valRegistro
 */
void Funcionario::setRegistro(vector <Data> valRegistro)
{
  this->registro = valRegistro;
}
/**
 * `void Funcionario::setCargo(Cargo valCargo)`
 * 
 * The function is called `setCargo` and it takes one parameter of type `Cargo` called `valCargo`. The
 * function returns nothing (`void`)
 * 
 * @param valCargo
 */
void Funcionario::setCargo(Cargo valCargo)
{
  this->cargo = valCargo;
}
/**
 * It sets the value of the variable estadoAtivo to the value of the variable valEstadoAtivo.
 * 
 * @param valEstadoAtivo
 */
void Funcionario::setEstadoAtivo(bool valEstadoAtivo)
{
  this->estadoAtivo = valEstadoAtivo;
}
/**
 * It adds a new Data object to the vector of Data objects
 * 
 * @param valData a struct that contains a date and a string
 */
void Funcionario::alteraRegistro(Data valData)
{
  this->registro.push_back(valData);
}
/**
 * It sets the state of the employee to inactive.
 */
void Funcionario::demiteFuncionario()
{
  this->estadoAtivo = false;
}
/**
 * It takes a float value and adds it to the current salary value
 * 
 * @param valPercentual the percentage of the salary increase
 */
void Funcionario::alteraSalario(float valPercentual)
{
  this->salario.setValor(this->salario.getValor() + (this->salario.getValor() * valPercentual));
}



