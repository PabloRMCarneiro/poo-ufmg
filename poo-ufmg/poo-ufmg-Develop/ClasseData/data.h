#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <iostream>
#include <string>
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
public:
    Data();
    Data(int valAno, int valMes, int valDia, int valHora, int valMin, int valSeg);
    //Metodos get:
    int getAno();
    int getMes();
    int getDia();
    int getHora();
    int getMin();
    int getSeg();
    //Metodos set:
    void setAno(int valAno);
    void setMes(int valMes);
    void setDia(int valDia);
    void setHora(int valHora);
    void setMin(int valMin);
    void setSeg(int valSeg);
    bool operator<(Data &d2);        //Sobrecarga do operador de comparacao lt
    bool operator==(Data &d2);       //Sobrecarga do operador de comparacao eq
    string getData(); 
};
#endif //DATA_H_INCLUDED