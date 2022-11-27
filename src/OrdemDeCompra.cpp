#include "../include/OrdemDeCompra.h"
#include "../include/UsuarioLogado.h"
#include "../include/PermissaoNegada.h"

OrdemDeCompra::OrdemDeCompra()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.OrdemDeCompra"))
    {
        PermissaoNegada *a = new PermissaoNegada("OrdemDeCompra", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.OrdemDeCompra";
        throw mensagem;
    }
    else
    {
        this->setData(Data());
        this->valorTotal = 0.0;
    }
}

OrdemDeCompra::OrdemDeCompra(MateriaPrima *valMateriaPrima)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.OrdemDeCompra"))
    {
        PermissaoNegada *a = new PermissaoNegada("OrdemDeCompra", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.OrdemDeCompra";
        throw mensagem;
    }
    else
    {
        this->setData(Data::dataDeHoje);
        this->setMateriaPrima(valMateriaPrima);
        this->valorTotal = 0.0;
    }
}

void OrdemDeCompra::setMateriaPrimaLista(vector<MateriaPrima *> valMateriaPrima)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.setMateriaPrimaLista"))
    {
        PermissaoNegada *a = new PermissaoNegada("setMateriaPrimaLista", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.setMateriaPrimaLista";
        throw mensagem;
    }
    else
    {
        for (auto it : valMateriaPrima)
        {
            this->setMateriaPrima(it);
        }
    }
}

void OrdemDeCompra::setMateriaPrima(MateriaPrima *valMateriaPrima)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.setMateriaPrima"))
    {
        PermissaoNegada *a = new PermissaoNegada("setMateriaPrima", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.setMateriaPrima";
        throw mensagem;
    }
    else
    {
        this->materiaPrimaLista.push_back(valMateriaPrima);
    }
}

void OrdemDeCompra::setData(Data valData)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.setData"))
    {
        PermissaoNegada *a = new PermissaoNegada("setData", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.setData";
        throw mensagem;
    }
    else
    {
        this->dataOrdem = valData;
    }
}

void OrdemDeCompra::setValorTotal(double valValorTotal)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.setValorTotal"))
    {
        PermissaoNegada *a = new PermissaoNegada("setValorTotal", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.setValorTotal";
        throw mensagem;
    }
    else
    {
        this->valorTotal = this->valorTotal + valValorTotal;
    }
}

void OrdemDeCompra::setOrcamento()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.setOrcamento"))
    {
        PermissaoNegada *a = new PermissaoNegada("setOrcamento", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.setOrcamento";
        throw mensagem;
    }
    else
    {
        vector<pair<string, double>> valItens;
        for (auto it : materiaPrimaLista)
        {
            valItens.push_back(make_pair(it->getNome(), it->getEstoqueMinimo()));
        }
        for (auto it : Fornecedor::fornecedorList)
        {
            Orcamento *novo = new Orcamento(false, valItens, Data::dataDeHoje, it);
            this->orcamentos.push_back(novo);
        }
    }
}

void OrdemDeCompra::gerarPedidos()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.gerarPedidos"))
    {
        PermissaoNegada *a = new PermissaoNegada("gerarPedidos", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.gerarPedidos";
        throw mensagem;
    }
    else
    {
        for (auto it : melhoresPrecos)
        {
            this->setCompra(it.first->vende(it.second, it.second->getEstoqueMinimo(), Data::dataDeHoje));
        }
    }
}

void OrdemDeCompra::setMelhoresPrecos()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.setMelhoresPrecos"))
    {
        PermissaoNegada *a = new PermissaoNegada("setMelhoresPrecos", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.setMelhoresPrecos";
        throw mensagem;
    }
    else
    {
        double menorPreco = 0.0, precoAtual = 0.0;
        Fornecedor *forneceMenorPreco;
        for (auto it : materiaPrimaLista)
        {
            for (auto it2 : this->orcamentos)
            {
                for (auto it3 : it2->getPrecos())
                {
                    if (it3.first == it->getNome())
                    {
                        if (menorPreco == 0.0)
                        {
                            menorPreco = it3.second;
                        }
                        else if (menorPreco > it3.second)
                        {
                            menorPreco = it3.second;
                            forneceMenorPreco = it2->getFornecedor();
                        }
                    }
                }
            }
            this->melhoresPrecos.push_back(make_pair(forneceMenorPreco, it));
            this->setValorTotal(menorPreco);
        }
    }
}

void OrdemDeCompra::setCompra(bool valCompra)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.setCompra"))
    {
        PermissaoNegada *a = new PermissaoNegada("setCompra", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.setCompra";
        throw mensagem;
    }
    else
    {
        this->compra = valCompra;
    }
}