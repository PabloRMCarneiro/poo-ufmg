#include "../include/Cliente.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"

using namespace std;

Cliente::Cliente() : Pessoa()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cliente.Cliente"))
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
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cliente.Cliente"))
    {
        PermissaoNegada *a = new PermissaoNegada("Cliente", "Cliente");
        throw "Acesso negado a Cliente.Cliente";
    }
    else
    {
        this->setTipoCliente(valDocumento);
    }
}

void Cliente::setTipoCliente(string tc)
{   
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cliente.Cliente"))
    {
        PermissaoNegada *a = new PermissaoNegada("setTipoCliente", "Cliente");
        throw "Acesso negado a setTipoCliente.Cliente";
    }
    else
    {
        if (tc.length() == 11)
        {
            this->tipoCliente = "Pessoa física";
        }else if (tc.length() == 14)
        {
            this->tipoCliente = "Pessoa jurídica";
        }
        LogEscrita *a = new LogEscrita("tipoCliente", "indefinido", this->tipoCliente, "Cliente");
    }
}
string Cliente::getTipoCliente()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cliente.getTipoCliente"))
    {
        PermissaoNegada *a = new PermissaoNegada("getTipoCliente", "Cliente");
        throw "Acesso negado a Cliente.getTipoCliente";
    }
    else
    {
        return this->tipoCliente;
        LogLeitura *a = new LogLeitura("tipoCliente", "Cliente");
    }
}