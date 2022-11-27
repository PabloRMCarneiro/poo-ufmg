#include "../include/PermissaoNegada.h"
#include "../include/Empresa.h"

PermissaoNegada::PermissaoNegada() : Log(){
    this->setMetodo("");
}

PermissaoNegada::PermissaoNegada(string valMetodo, string valEntidade) : Log(valEntidade){
    this->metodo = valMetodo;
    Empresa::getEmpresa()->setlogAcessoNegado(this);
}
void PermissaoNegada::setMetodo(string valMetodo){
    this->metodo = valMetodo;
}

string PermissaoNegada::getMetodo(){
    return this->metodo;
}

void PermissaoNegada::imprime(){
  cout << "Em "<< this->getData().getData() << " - ";
  cout << "usuario " << this->getUsuario()->getEmail() << " teve acesso negado à função "<< this->getMetodo() << " da classe " << this->getEntidade() << "." << endl;
}