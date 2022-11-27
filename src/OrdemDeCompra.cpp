#include "../include/OrdemDeCompra.h"
#include "../include/UsuarioLogado.h"

OrdemDeCompra::OrdemDeCompra()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.OrdemDeCompra"))
    {
        throw "Acesso negado a OrdemDeCompra.OrdemDeCompra";
    }
    else
    {
        this->setData(Data());
        this->valorTotal = 0.0;
    }
}

OrdemDeCompra::OrdemDeCompra(MateriaPrima *valMateriaPrima)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.OrdemDeCompra"))
    {
        throw "Acesso negado a OrdemDeCompra.OrdemDeCompra";
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
    for (auto it : valMateriaPrima)
    {
        this->setMateriaPrima(it);
    }
}

void OrdemDeCompra::setMateriaPrima(MateriaPrima *valMateriaPrima)
{
    this->materiaPrimaLista.push_back(valMateriaPrima);
}

void OrdemDeCompra::setData(Data valData)
{
    this->dataOrdem = valData;
}

void OrdemDeCompra::setValorTotal(double valValorTotal)
{
    this->valorTotal = this->valorTotal + valValorTotal;
}

void OrdemDeCompra::setOrcamento()
{    
    vector<pair<string, double>> valItens;
    for(auto it : materiaPrimaLista){
        valItens.push_back(make_pair(it->getNome(), it->getEstoqueMinimo()));
    }
    for(auto it : Fornecedor::fornecedorList){
        Orcamento * novo = new Orcamento(false, valItens, Data::dataDeHoje, it);
        this->orcamentos.push_back(novo);
    }
}

void OrdemDeCompra::gerarPedidos()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.gerarPedidos"))
    {
        throw "Acesso negado a OrdemDeCompra.gerarPedidos";
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
                    if (menorPreco = 0.0)
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

void OrdemDeCompra::setCompra(bool valCompra)
{
    this->compra = valCompra;
}