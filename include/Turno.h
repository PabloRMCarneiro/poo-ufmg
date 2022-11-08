#ifndef TURNO_H_INCLUDED
#define TURNO_H_INCLUDED
#include <string>
#include "data.h"
using namespace std;

class Turno{
    private:
        string periodo;
        Data entradaHora;
        Data saidaHora;
        double jornada;

    public:
    //construtor
        Turno(string valPeriodo, Data valEntradaHora, Data valSaidaHora, double valJornada);
        Turno();
    //metodos set
        void setPeriodo(string valPeriodo);
        void setEntradaHora(Data valEntradaHora);
        void setSaidaHora(Data valSaidaHora);
        void setJornada(double valJornada);
    //metodos get
        string getPeriodo();
        Data getEntradaHora();
        Data getSaidaHora();
        double getJornada();
};
#endif //TURNO_H_INCLUDED