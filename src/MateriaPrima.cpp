#include "../include/MateriaPrima.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"
#include "../include/OrdemDeCompra.h"

MateriaPrima::MateriaPrima()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.MateriaPrima"))
    {
        PermissaoNegada *a = new PermissaoNegada("MateriaPrima", "MateriaPrima");
        string mensagem = "Acesso negado a MateriaPrima.MateriaPrima";
        throw mensagem;
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
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.MateriaPrima"))
    {
        PermissaoNegada *a = new PermissaoNegada("MateriaPrima", "MateriaPrima");
        string mensagem = "Acesso negado a MateriaPrima.MateriaPrima";
        throw mensagem;
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
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.geraOrdemDeCompra"))
    {
        PermissaoNegada *a = new PermissaoNegada("geraOrdemDeCompra", "MateriaPrima");
        string mensagem = "Acesso negado a MateriaPrima.geraOrdemDeCompra";
        throw mensagem;
    }
    else
    {
        OrdemDeCompra *nova = new OrdemDeCompra(this);
        // Empresa::getEmpresa()->setOrdemDeCompra(nova);
    }
}

double MateriaPrima::getEstoque()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.getEstoque"))
    {
        PermissaoNegada *a = new PermissaoNegada("getEstoque", "MateriaPrima");
        string mensagem = "Acesso negado a MateriaPrima.getEstoque";
        throw mensagem;
    }
    else
    {
        return this->estoque;
    }
}

string MateriaPrima::getUnidadeMedida()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.getUnidadeMedida"))
    {
        PermissaoNegada *a = new PermissaoNegada("getUnidadeMedida", "MateriaPrima");
        string mensagem = "Acesso negado a MateriaPrima.getUnidadeMedida";
        throw mensagem;
    }
    else
    {
        return this->unidadeDeMedida;
    }
}

double MateriaPrima::getEstoqueMinimo()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.getEstoqueMinimo"))
    {
        PermissaoNegada *a = new PermissaoNegada("getEstoqueMinimo", "MateriaPrima");
        string mensagem = "Acesso negado a MateriaPrima.getEstoqueMinimo";
        throw mensagem;
    }
    else
    {
        return this->estoqueMinimo;
    }
}

string MateriaPrima::getNome()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.getNome"))
    {
        PermissaoNegada *a = new PermissaoNegada("getNome", "MateriaPrima");
        string mensagem = "Acesso negado a MateriaPrima.getNome";
        throw "Acesso negado a MateriaPrima.getNome";
    }
    else
    {
        return this->nome;
    }
}

void MateriaPrima::setEstoqueMin(double valEstoqueMinimo)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.setEstoqueMin"))
    {
        PermissaoNegada *a = new PermissaoNegada("setEstoqueMin", "MateriaPrima");
        string mensagem = "Acesso negado a MateriaPrima.setEstoqueMin";
        throw mensagem;
    }
    else
    {
        this->estoqueMinimo = valEstoqueMinimo;
    }
}

void MateriaPrima::setEstoque(double valEstoque, Data valData)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.setEstoque"))
    {
        PermissaoNegada *a = new PermissaoNegada("setEstoque", "MateriaPrima");
        string mensagem = "Acesso negado a MateriaPrima.setEstoque";
        throw mensagem;
    }
    else
    {
        this->estoque = valEstoque + this->estoque;
        if (this->estoque < this->estoqueMinimo)
        {
            this->geraOrdemDeCompra(valData);
        }
    }
}

void MateriaPrima::setNome(string valNome)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.setNome"))
    {
        PermissaoNegada *a = new PermissaoNegada("setNome", "MateriaPrima");
        string mensagem = "Acesso negado a MateriaPrima.setNome";
        throw mensagem;
    }
    else
    {
        this->nome = valNome;
    }
}

void MateriaPrima::setUnidadeDeMedida(string valUnidadeDeMedida)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("MateriaPrima.setUnidadeDeMedida"))
    {
        PermissaoNegada *a = new PermissaoNegada("setUnidadeDeMedida", "MateriaPrima");
        string mensagem = "Acesso negado a MateriaPrima.setUnidadeDeMedida";
        throw mensagem;
    }
    else
    {
        this->unidadeDeMedida = valUnidadeDeMedida;
    }
}