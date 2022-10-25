#include "../include/Permissao.h"

Permissao::Permissao(){
    this->setMetodo("");
}

Permissao::Permissao(string valMetodo){
    this->setMetodo(valMetodo);
}

void Permissao::setMetodo(string valMetodo){
    this->metodo = valMetodo;
}

string Permissao::getMetodo(){
    return this->metodo;
}