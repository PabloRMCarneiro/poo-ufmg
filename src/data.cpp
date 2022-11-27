#include "../include/data.h"

Data Data::dataDeHoje;

Data::Data()
{
    ano = 0;
    mes = 0;
    dia = 0;
    hora = 0;
    minuto = 0;
    segundo = 0;
}
Data::Data(int valDia, int valMes, int valAno){
    ano = valAno;
    mes = valMes;
    dia = valDia;
    hora = 0;
    minuto = 0;
    segundo = 0;
}
Data::Data(int valDia, int valMes, int valAno, int valHora, int valMin, int valSeg )
{
    ano = valAno;
    mes = valMes;
    dia = valDia;
    hora= valHora;
    minuto= valMin;
    segundo= valSeg;
}

int Data::getAno()
{
    return ano;
}

int Data::getMes()
{
    return mes;
}

int Data::getDia()
{
    return dia;
}

int Data::getHora()
{
    return hora;
}

int Data::getMin()
{
    return minuto;
}

int Data::getSeg()
{
    return segundo;
}

void Data::setAno(int valAno)
{
    ano = valAno;
}

void Data::setMes(int valMes)
{
    mes = valMes;
}

void Data::setDia(int valDia)
{
    dia = valDia;
}

void Data::setHora(int valHora)
{
    hora = valHora;
}

void Data::setMin(int valMin)
{
    minuto = valMin;
}

void Data::setSeg(int valSeg)
{
    segundo = valSeg;
}
string help(int num){
    if(num <10){
        return ("0"+to_string(num));
    }
    return to_string(num);
}
string Data::getData()
{   
    string sDia = help(dia), sMes = help(mes), sAno = help(ano);
    string sHora = help(hora), sMinuto = help(minuto), sSegundo = help(segundo);
    return (sDia + "/" + sMes + "/" + sAno + " às " + sHora + ":" + sMinuto + ":" + sSegundo);
}
string Data::getHorario(){
    string sHora = help(hora), sMinuto = help(minuto), sSegundo = help(segundo);
    return (sHora + ":" + sMinuto + ":" + sSegundo);
}
bool Data::operator<(Data &d2)

{
    return ((ano < d2.ano) || (ano == d2.ano && mes < d2.mes) || (ano == d2.ano && mes == d2.mes && dia < d2.dia) ||
            (ano == d2.ano && mes == d2.mes && dia == d2.dia && hora < d2.hora) || (ano == d2.ano && mes == d2.mes && dia == d2.dia && hora == d2.hora && minuto < d2.minuto) || (ano == d2.ano && mes == d2.mes && dia == d2.dia && hora == d2.hora && minuto == d2.minuto && segundo < d2.segundo));
}

bool Data::operator==(Data &d2)
{
    return ((ano == d2.ano) && (mes == d2.mes) && (dia == d2.dia) /* && (hora == d2.hora) &&
            (minuto == d2.minuto) && (segundo == d2.segundo) */);
}