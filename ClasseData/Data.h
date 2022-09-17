#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <string>
#include "Formato.h"
#include "ExecaoCustomizada.h"

//Constantes de Conversao
#define YEAR_TO_SECONDS 31536000
#define DAY_TO_SECONDS 86400
#define HOURS_TO_SECONDS 3600
#define MINUTE_TO_SECONDS 60

using namespace std;

class Data
{
private:
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;
    int segundo;
    long ticks;     //Segundos desde 00:00:00 01/01/1970
    Formato formatoData;

    void ticksToDate();
    void dateToTicks();

public:
    Data();     //Construtor default(PT-BR)
    Data(Formato valFormato);       //Construtor default de formato de data especifico
    Data(int valAno, int valMes, int valDia, int valHora, int valMin, int valSeg);      //Construtor com argumentos e formato default
    Data(long valTicks);        //Construtor a partir de ticks
    virtual ~Data();        //Destrutor
    bool operator==(Data &d2);       //Sobrecarga do operador de comparacao eq
    bool operator<(Data &d2);        //Sobrecarga do operador de comparacao lt
    bool operator>(Data &d2);        //Sobrecarga do operator de comparacao gt
    Data operator-(Data &d2);         //Sobrecarga do operador de subtracao

    //Metodos get:
    int getAno();
    int getMes();
    int getDia();
    int getHora();
    int getMin();
    int getSeg();
    long getTicks();
    string getFormato();

    //Metodos set:
    void setAno(int valAno);
    void setMes(int valMes);
    void setDia(int valDia);
    void setHora(int valHora);
    void setMin(int valMin);
    void setSeg(int valSeg);
    void setTicks(long valTicks);
    void setFormato(Formato valFormato);

    bool validaData();      //Verifica se todos os valores dos atributos estao dentro dos limites possiveis
    Data dateNow();     //Retorna a data do presente momento
    void printData();       //Imprime a data na tela de acordo com o formato ja atribuido
    string getData();       //Retorna a data no formato de string
    int diffData(Data);    // Retorna a diferença entre duas datas em dias
};

#endif // DATA_H_INCLUDED
