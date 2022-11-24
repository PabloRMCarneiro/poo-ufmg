#include "../include/Fornecedor.h"
#include "../include/UsuarioLogado.h"

vector<Fornecedor *> Fornecedor::fornecedorList;

Fornecedor::Fornecedor() : Pessoa()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Fornecedor.Fornecedor"))
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
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Fornecedor.Fornecedor"))
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
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Fornecedor.getTipoFornecedor"))
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
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Fornecedor.getPreco"))
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
    }
}

vector<pair<MateriaPrima *, double>> Fornecedor::getPrecos()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Fornecedor.getPrecos"))
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
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Fornecedor.vende"))
    {
        throw "Acesso negado a Fornecedor.vende";
    }
    else
    {
        /* for (auto it : precos)
        {
            if (it.first == valMateriaPrima)
            {
                if (it.second * valQuantidade <= Empresa::getEmpresa()->getCaixa())
                {
                    Empresa::getEmpresa()->setCaixa(Empresa::getEmpresa()->getCaixa() - (it.second * valQuantidade));
                    Empresa::getEmpresa()->getEstoque()->adicionar(valMateriaPrima, valQuantidade, valData);
                    return true;
                    break;
                }
                else
                {
                    return false;
                    break;
                }
            }
        } */
        valMateriaPrima->setEstoque(valQuantidade, valData);
    }
}