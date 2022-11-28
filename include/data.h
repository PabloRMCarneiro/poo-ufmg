#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

class Data{
     
    private:
        int ano;
        int mes;
        int dia;
        int hora;
        int minuto;
        int segundo;
    public:
        static Data dataDeHoje;
        Data();
        Data(int valDia, int valMes, int valAno);
        Data(int valDia, int valMes, int valAno , int valHora, int valMin, int valSeg );
        int getAno();
        int getMes();
        int getDia();
        int getHora();
        int getMin();
        int getSeg();
        void setAno(int valAno);
        void setMes(int valMes);
        void setDia(int valDia);
        void setHora(int valHora);
        void setMin(int valMin);
        void setSeg(int valSeg);
        bool operator<(Data &d2);       
        bool operator==(Data &d2);      
        string getData(); 
        string getHorario();
        string help(int num);
};
#endif 