#include "../include/MateriaPrima.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"
#include "../include/OrdemDeCompra.h"

MateriaPrima::MateriaPrima()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.MateriaPrima"))
    {
        throw "Acesso negado a MateriaPrima.MateriaPrima";
    }
    else
    {
        this->setNome("");
        this->estoque = 0.0;
        this->setEstoqueMin(0.0);
        this->setUnidadeDeMedida("");
    }
}

MateriaPrima::MateriaPrima(string valNome, string valUnidadeDeMedida, double valEstoqueMinimo)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.MateriaPrima"))
    {
        throw "Acesso negado a MateriaPrima.MateriaPrima";
    }
    else
    {
        this->setNome(valNome);
        this->estoque = 0.0;
        this->setEstoqueMin(valEstoqueMinimo);
        this->setUnidadeDeMedida(valUnidadeDeMedida);
    }
}

void MateriaPrima::geraOrdemDeCompra(Data valData)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.geraOrdemDeCompra"))
    {
        throw "Acesso negado a MateriaPrima.geraOrdemDeCompra";
    }
    else
    {
        OrdemDeCompra *nova = new OrdemDeCompra(this);
        //Empresa::getEmpresa()->setOrdemDeCompra(nova);
    }
}

double MateriaPrima::getEstoque()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.getEstoque"))
    {
        throw "Acesso negado a MateriaPrima.getEstoque";
    }
    else
    {
        return this->estoque;
    }
}

string MateriaPrima::getUnidadeMedida()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.getUnidadeMedida"))
    {
        throw "Acesso negado a MateriaPrima.getUnidadeMedida";
    }
    else
    {
        return this->unidadeDeMedida;
    }
}

double MateriaPrima::getEstoqueMinimo()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.getEstoqueMinimo"))
    {
        throw "Acesso negado a MateriaPrima.getEstoqueMinimo";
    }
    else
    {
        return this->estoqueMinimo;
    }
}

string MateriaPrima::getNome()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.getNome"))
    {
        throw "Acesso negado a MateriaPrima.getNome";
    }
    else
    {
        return this->nome;
    }
}

void MateriaPrima::setEstoqueMin(double valEstoqueMinimo)
{
    this->estoqueMinimo = valEstoqueMinimo;
}

void MateriaPrima::setEstoque(double valEstoque, Data valData)
{
    this->estoque = valEstoque + this->estoque;
    if (this->estoque < this->estoqueMinimo)
    {
        this->geraOrdemDeCompra(valData);
    }
}

void MateriaPrima::setNome(string valNome)
{
    this->nome = valNome;
}

void MateriaPrima::setUnidadeDeMedida(string valUnidadeDeMedida)
{
    this->unidadeDeMedida = valUnidadeDeMedida;
}