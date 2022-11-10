#include <iostream>
// #include "../include/data.h"
// #include "../include/Endereco.h"
using namespace std;

int main() {
  cout << "Teste" << endl;
  double valTempo; // min
  int getHora, getMin, getSeg;
  cin >> getHora >> getMin >> getSeg >> valTempo;
  cout << valTempo << " - " << getHora << ":" << getMin << ":" << getSeg << endl;
  valTempo = valTempo; // em segundos
  int horaEntrada, horaturno, hora, minuto, segundo; 
  horaturno = getHora*3600+ getMin*60 + getSeg;
  horaEntrada = horaturno -600 - valTempo;
  hora = int(horaEntrada/3600);
  minuto = int((horaEntrada%3600)/60);
  segundo = horaEntrada-(hora*3600 + minuto*60);
  cout << hora << ":" << minuto << ":" << segundo << endl;
  return 0;
}