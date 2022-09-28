#include <iostream>
#include <string>
/* #include "../include/Pessoa.h"
#include "../include/Salario.h" */
#include "../include/Categoria.h"
// #include "./ClasseCargo/Cargo.h"
// #include "./ClasseDepartamento/Departamento.h"
// #include "./ClasseFuncionario/Funcionario.h"
// #include "./ClasseData/Data.h"
// #include "./ClasseData/Formato.h"
// #include "./ClasseData/ExecaoCustomizada.h"
#include <vector>

using namespace std;

int main(){
  
  Categoria categoria("Professor");

  
  cout << categoria.getTipo() << endl;

  return 0;
}