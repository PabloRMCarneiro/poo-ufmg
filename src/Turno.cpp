#include "../include/Turno.h"

Turno::Turno(string valPeriodo, Data valEntradaHora, Data valSaidaHora, double valJornada){
    this->setEntradaHora(valEntradaHora);
    this->setJornada(valJornada);
    this->setPeriodo(valPeriodo);
    this->setSaidaHora(valSaidaHora);
}

Turno::Turno(){
    this->setEntradaHora(Data());
    this->setJornada(0.0);
    this->setPeriodo("");
    this->setSaidaHora(Data());
}

void Turno::setEntradaHora(Data valEntradaHora){
    this->entradaHora = valEntradaHora;
}

void Turno::setSaidaHora(Data valSaidaHora){
    this->saidaHora = valSaidaHora;
}

void Turno::setPeriodo(string valPeriodo){
    this->periodo = valPeriodo;
}

void Turno::setJornada(double valJornada){
    this->jornada = valJornada;
}

string Turno::getPeriodo(){
    return this->periodo;
}

Data Turno::getEntradaHora(){
    return this->entradaHora;
}

Data Turno::getSaidaHora(){
    return this->saidaHora;
}

double Turno::getJornada(){
    return this->jornada;
}