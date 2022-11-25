#include "../include/PermissaoNegada.h"

PermissaoNegada::PermissaoNegada() {
    this->metodo = "";
}

PermissaoNegada::PermissaoNegada(string valMetodo, string valEntidade) : Log(valEntidade){
    this->metodo = valMetodo;
}
void PermissaoNegada::setMetodo(string valMetodo) {
    this->metodo = valMetodo;
}

string PermissaoNegada::getMetodo() { 
    return this->metodo;
}