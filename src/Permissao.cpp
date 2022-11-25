#include "../include/PermissaoNegada.h"

PermissaoNegada::PermissaoNegada() {
    this->metodo = "";
}

PermissaoNegada::PermissaoNegada(string valMetodo, string entidade) {
    this->metodo = valMetodo;
    this->setEntidade(entidade);
}
void PermissaoNegada::setMetodo(string valMetodo) {
    this->metodo = valMetodo;
}

string PermissaoNegada::getMetodo() { 
    return this->metodo;
}