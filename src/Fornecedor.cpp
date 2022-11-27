#include "../include/Fornecedor.h"
#include "../include/UsuarioLogado.h"

vector<Fornecedor *> Fornecedor::fornecedorList;

Fornecedor::Fornecedor() : Pessoa(){
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Fornecedor.Fornecedor"))
    {
        throw "Acesso negado a Fornecedor.Fornecedor";
    }
    else
    {
        this->tipoFornecedor = "";
    }
}

Fornecedor::Fornecedor(string valNome, Endereco valEndereco, string valEmail, string valDocumento, long int valTelefone) : Pessoa(valNome, valEndereco, valEmail, valDocumento, valTelefone)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Fornecedor.Fornecedor"))
    {
        throw "Acesso negado a Fornecedor.Fornecedor";
    }
    else
    {
        this->setTipoFornecedor(valDocumento);
    }
}

void Fornecedor::setPrecos(vector<pair<MateriaPrima *, double>> valPrecos)
{
    for (auto it : valPrecos)
    {
        this->setPreco(make_pair(it.first, it.second));
    }
}

void Fornecedor::setPreco(pair<MateriaPrima *, double> valMateriaPrima)
{
    this->precos.push_back(valMateriaPrima);
}

void Fornecedor::setTipoFornecedor(string valTipoFornecedor)
{
    if (valTipoFornecedor.length() == 11)
    {
        this->tipoFornecedor = "Pessoa física";
    }
    if (valTipoFornecedor.length() == 14)
    {
        this->tipoFornecedor = "Pessoa jurídica";
    }
}

string Fornecedor::getTipoFornecedor(string valTipoFornecedor)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Fornecedor.getTipoFornecedor"))
    {
        throw "Acesso negado a Fornecedor.getTipoFornecedor";
    }
    else
    {
        return this->tipoFornecedor;
    }
}

double Fornecedor::getPreco(MateriaPrima *valMateriaPrima)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Fornecedor.getPreco"))
    {
        throw "Acesso negado a Fornecedor.getPreco";
    }
    else
    {
        for (auto it : precos)
        {
            if (it.first == valMateriaPrima)
            {
                return it.second;
                break;
            }
        }
        return 0.0;
    }
}

vector<pair<MateriaPrima *, double>> Fornecedor::getPrecos()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Fornecedor.getPrecos"))
    {
        throw "Acesso negado a Fornecedor.getPrecos";
    }
    else
    {
        return this->precos;
    }
}

bool Fornecedor::vende(MateriaPrima *valMateriaPrima, double valQuantidade, Data valData)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Fornecedor.vende"))
    {
        throw "Acesso negado a Fornecedor.vende";
    }
    else
    {
        valMateriaPrima->setEstoque(valQuantidade, valData);
        return true;
    }
}