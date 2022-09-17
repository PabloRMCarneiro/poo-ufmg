#include <iostream>
#include <string>
#include "./ClassePessoa/Pessoa.h"
using namespace std;

int main(){
    string nome = "Teste";
    string endereco = "Rua 1";
    string email = "teste@gmail.com";
    string documento = "57180015000104"; /* Exemplo de CPNJ*/
  /*string documento = "44078910092" */  /* Exemplo de CPF*/
    int telefone = 123456789;

    Pessoa p1(nome, endereco, email, documento, telefone);

    cout << p1.getNome() << endl;
    cout << p1.getEndereco() << endl;
    cout << p1.getEmail() << endl;
    cout << p1.getDocumento() << endl;
    cout << p1.getTelefone() << endl;
    cout << p1.validaDocumento(p1.getDocumento()) << endl;

  return 0;
}