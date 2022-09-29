#include "../include/Cliente.h"

Cliente::Cliente(){
    Pessoa();
    this->tipoCliente = " ";
}
Cliente::Cliente(string valNome, string valEndereco, string valEmail, string valDocumento, long int valTelefone):Pessoa(valNome, valEndereco, valEmail, valDocumento, valTelefone){
    this->setTipoCliente(valDocumento);
}
void Cliente::setTipoCliente(string tc){
    if(tc.length() == 11){
        this->tipoCliente = "Pessoa física";
    }
    if(tc.length() == 14){
        this->tipoCliente = "Pessoa jurídica";
    }
}
string Cliente::getTipoCliente(){
    return this->tipoCliente;
}
