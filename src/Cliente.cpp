#include "../include/Cliente.h"
#include "../include/Empresa.h"

Cliente::Cliente():Pessoa(){
    if(!Empresa::getEmpresa()->getAcesso("Cliente.Cliente"))
    {
        throw "Acesso negado";
    }
    else
    {
        this->tipoCliente = "";
    }

}
Cliente::Cliente(string valNome, string valEndereco, string valEmail, string valDocumento, long int valTelefone):Pessoa(valNome, valEndereco, valEmail, valDocumento, valTelefone){
    if(!Empresa::getEmpresa()->getAcesso("Cliente.Cliente"))
    {
        throw "Acesso negado";
    }
    else
    {
        this->setTipoCliente(valDocumento);
    }
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
