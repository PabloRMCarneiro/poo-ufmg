#include "../include/data.h"

/**
 * Data::Data()
 * 
 * This is a constructor for the class Data. It initializes the class variables to default values
 */

Data::Data()
{
    ano= 1970;
    mes= 1;
    dia= 1;
    hora= 0;
    minuto= 0;
    segundo= 0;
}
/**
 * Data::Data(int valAno, int valMes, int valDia, int valHora, int valMin, int valSeg)
 * 
 * The above function is a constructor for the class Data. It takes 6 integer parameters and assigns
 * them to the class variables ano, mes, dia, hora, minuto, and segundo
 * 
 * @param valAno year
 * @param valMes Month
 * @param valDia Day of the month
 * @param valHora 0
 * @param valMin 0
 * @param valSeg seconds
 */

Data::Data(int valAno, int valMes, int valDia, int valHora, int valMin, int valSeg)
{
    ano= valAno;
    mes= valMes;
    dia= valDia;
    hora= valHora;
    minuto= valMin;
    segundo= valSeg;
}
/**
 * It returns the value of the variable ano.
 * 
 * @return The value of the variable ano.
 */
int Data::getAno()
{
    return ano;
}

/**
 * It returns the value of the variable mes.
 * 
 * @return The value of the variable mes.
 */
int Data::getMes()
{
    return mes;
}
/**
 * It returns the value of the variable dia.
 * 
 * @return The value of the variable dia.
 */
int Data::getDia()
{
    return dia;
}
/**
 * It returns the value of the variable hora.
 * 
 * @return The value of the variable hora.
 */
int Data::getHora()
{
    return hora;
}
/**
 * It returns the value of the variable minuto.
 * 
 * @return The minute.
 */
int Data::getMin()
{
    return minuto;
}
/**
 * It returns the value of the variable segundo.
 * 
 * @return The value of the variable segundo.
 */
int Data::getSeg()
{
    return segundo;
}
/**
 * It sets the value of the variable ano to the value of the variable valAno.
 * 
 * @param valAno the value of the year
 */
void Data::setAno(int valAno)
{
    ano= valAno;
}
/**
 * This function sets the value of the variable mes to the value of the parameter valMes.
 * 
 * @param valMes the value of the month
 */
void Data::setMes(int valMes)
{
    mes= valMes;
}
/**
 * The function setDia() sets the value of the private variable dia to the value of the parameter
 * valDia
 * 
 * @param valDia The value of the day
 */
void Data::setDia(int valDia)
{
    dia= valDia;
}
/**
 * It sets the value of the variable hora to the value of the variable valHora.
 * 
 * @param valHora the value of the hour
 */
void Data::setHora(int valHora)
{
    hora= valHora;
}
/**
 * It sets the value of the minute.
 * 
 * @param valMin the minute
 */
void Data::setMin(int valMin)
{
    minuto= valMin;
}
/**
 * This function sets the value of the variable segundo to the value of the variable valSeg.
 * 
 * @param valSeg the value of the second
 */
/**
 * This function sets the value of the variable segundo to the value of the variable valSeg.
 * 
 * @param valSeg the value of the second
 */
void Data::setSeg(int valSeg)
{
    segundo= valSeg;
}
/**
 * It returns a string with the date and time in the format "dd/mm/yyyy-hh:mm:ss"
 * 
 * @return A string with the date and time.
 */
string Data::getData() {

    return (to_string(dia) + "/" + to_string(mes) + "/" + to_string(ano) + "-" + to_string(hora) + ":" + to_string(minuto) + ":" + to_string(segundo) + "\n");
}
bool Data::operator<(Data &d2)
/* Comparing the values of the variables ano, mes, dia, hora, minuto, and segundo. */
{
	return ((ano<d2.ano)||(ano==d2.ano && mes<d2.mes)||(ano==d2.ano && mes==d2.mes && dia<d2.dia)||
           (ano==d2.ano && mes==d2.mes && dia==d2.dia && hora<d2.hora)||(ano==d2.ano && mes==d2.mes&&
           dia==d2.dia && hora==d2.hora && minuto<d2.minuto)||(ano==d2.ano && mes==d2.mes && dia==d2.dia &&
           hora==d2.hora && minuto==d2.minuto && segundo<d2.segundo));
}
/**
 * The function returns true if the two dates are equal, and false otherwise
 * 
 * @param d2 Data object
 * 
 * @return The return value is a boolean value.
 */
bool Data::operator==(Data &d2)
{
	return ((ano == d2.ano)&&(mes == d2.mes)&&(dia == d2.dia)&&(hora == d2.hora)&&
           (minuto == d2.minuto)&&(segundo == d2.segundo));
}