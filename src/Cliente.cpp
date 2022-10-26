#include "../include/Cliente.h"
#include "../include/Empresa.h"
#include "../include/PermissaoNegada.h"

using namespace std;

Cliente::Cliente():Pessoa(){
    if(!Empresa::getEmpresa()->getAcesso("Cliente.Cliente"))
    {
        throw acessoNegadoCliente();
    }
    else
    {   
        this->cliente = Pessoa();
        this->tipoCliente = "";
    }

}
Cliente::Cliente(string valNome, string valEndereco, string valEmail, string valDocumento, long int valTelefone):Pessoa(valNome, valEndereco, valEmail, valDocumento, valTelefone){
    if(!Empresa::getEmpresa()->getAcesso("Cliente.Cliente"))
    {
        throw acessoNegadoCliente();
    }
    else
    {   
        this->cliente = Pessoa(valNome, valEndereco, valEmail, valDocumento, valTelefone);
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
    if(!Empresa::getEmpresa()->getAcesso("Cliente.getTipoCliente"))
    {
        throw acessoNegadoGetCliente();
    }
    else
    {   
        return this->tipoCliente;
    }
}
