#include "../include/Cliente.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"

using namespace std;

Cliente::Cliente() : Pessoa()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cliente.Cliente"))
    {
        throw "Acesso negado a Cliente.Cliente";
    }
    else
    {
        this->tipoCliente = "";
    }
}

Cliente::Cliente(string valNome, Endereco valEndereco, string valEmail, string valDocumento, long int valTelefone) : Pessoa(valNome, valEndereco, valEmail, valDocumento, valTelefone)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cliente.Cliente"))
    {
        throw "Acesso negado a Cliente.Cliente";
    }
    else
    {
        this->setTipoCliente(valDocumento);
    }
}

void Cliente::setTipoCliente(string tc)
{
    if (tc.length() == 11)
    {
        this->tipoCliente = "Pessoa física";
    }
    if (tc.length() == 14)
    {
        this->tipoCliente = "Pessoa jurídica";
    }
}
string Cliente::getTipoCliente()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cliente.getTipoCliente"))
    {
        throw "Acesso negado a Cliente.getTipoCliente";
    }
    else
    {
        return this->tipoCliente;
    }
}
