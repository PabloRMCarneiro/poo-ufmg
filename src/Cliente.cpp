#include "../include/Cliente.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"
#include "../include/PermissaoNegada.h"

using namespace std;

Cliente::Cliente() : Pessoa()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cliente.Cliente"))
    {
        PermissaoNegada *permissaoNegada = new PermissaoNegada("Cliente", "Cliente");
        string mensagem = "Acesso negado a Cliente.Cliente";
        throw mensagem;
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
        PermissaoNegada *a = new PermissaoNegada("Cliente", "Cliente");
        string mensagem = "Acesso negado a Cliente.Cliente";
        throw mensagem;
    }
    else
    {
        this->setTipoCliente(valDocumento);
    }
}

void Cliente::setTipoCliente(string tc)
{   
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cliente.setTipoCliente"))
    {
        PermissaoNegada *a = new PermissaoNegada("setTipoCliente", "Cliente");
        string mensagem = "Acesso negado a Cliente.setTipoCliente";
        throw mensagem;
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
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Cliente.getTipoCliente"))
    {
        PermissaoNegada *a = new PermissaoNegada("getTipoCliente", "Cliente");
        string mensagem = "Acesso negado a Cliente.getTipoCliente";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("tipoCliente", "Cliente");
        return this->tipoCliente;
    }
}