#include <iostream>
#include "../include/data.h"

using namespace std;

int main() {
   cout << "Teste" << endl;
   Data data = Data(2000, 3, 2);
   cout << data.getDia() << endl;
   string periodo = "periodo";
   Turno a = Turno(periodo, data, data, 8.0);
   cout << a.getPeriodo() << " - "<< a.getJornada()  << " - " << a.getEntradaHora().getData() << " - " << a.getSaidaHora().getData() << endl;
}