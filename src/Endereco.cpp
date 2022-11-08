#include "../include/Endereco.h"
#include <math.h>
//construtor
Endereco::Endereco(){
    this->setEndereco("");
    this->setX(0);
    this->setY(0);
}
Endereco::Endereco(string valEndereco, double valX, double valY){
    this->setEndereco(valEndereco);
    this->setX(valX);
    this->setY(valY);
}
//metodos set
void Endereco::setEndereco(string valEndereco){
    this->endereco = valEndereco;
}
void Endereco::setX(double valX){
    this->x = valX;
}
void Endereco::setY(double valY){
    this->y = valY;
}
//metodos get
string Endereco::getEndereco(){
    return this->endereco;
}
double Endereco::getX(){
    return this->x;
}
double Endereco::getY(){
    return this->y;
}
double Endereco::getDistancia(double x2, double y2){
    return 110.57 * sqrt(pow(x2-this->x, 2) + pow(y2-this->y, 2));
}