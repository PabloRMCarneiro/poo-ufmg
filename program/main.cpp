#include <iostream>
#include "../include/data.h"
#include "../include/Endereco.h"
using namespace std;

int main() {
  cout << "Teste" << endl;
  Endereco a("rua basoda", 2, 3);
  Data b(0,0,0);
  string matutino = "matutino";
  cout << b.getDia() << endl;
   //cout << a.getPeriodo() << " - "<< a.getJornada()  << " - " << a.getEntradaHora().getData() << " - " << a.getSaidaHora().getData() << endl;
}