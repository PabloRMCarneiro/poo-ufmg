#include "../include/OrdemDeProducao.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"

OrdemDeProducao::OrdemDeProducao()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.OrdemDeProducao"))
    {
        throw "Acesso negado a OrdemDeProducao.OrdemDeProducao";
    }
    else
    {
        this->dataOrdem = Data();
        this->produto = "";
        this->quantidade = 0;
    }
}

OrdemDeProducao::OrdemDeProducao(Data dO, string p, int q)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.OrdemDeProducao"))
    {
        throw "Acesso negado a OrdemDeProducao.OrdemDeProducao";
    }
    else
    {
        this->setDataOrdem(dO);
        this->setProduto(p);
        this->setQuantidade(q);
    }
}

void OrdemDeProducao::setDataOrdem(Data dO)
{
    this->dataOrdem = dO;
}

void OrdemDeProducao::setProduto(string p)
{
    this->produto = p;
}

void OrdemDeProducao::setQuantidade(int q)
{
    this->quantidade = q;
}

Data OrdemDeProducao::getDataOrdem()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.getDataOrdem"))
    {
        throw "Acesso negado a OrdemDeProducao.getDataOrdem";
    }
    else
    {
        return this->dataOrdem;
    }
}

string OrdemDeProducao::getProduto()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.getProduto"))
    {
        throw "Acesso negado a OrdemDeProducao.getProduto";
    }
    else
    {
        return this->produto;
    }
}

int OrdemDeProducao::getQuantidade()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.getQuantidade"))
    {
        throw "Acesso negado a OrdemDeProducao.getQuantidade";
    }
    else
    {
        return this->quantidade;
    }
}

void OrdemDeProducao::getOrdem()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.getOrdem"))
    {
        throw "Acesso negado a OrdemDeProducao.getOrdem";
    }
    else
    {
        cout << "Data da Ordem: " << this->getDataOrdem().getDia() << "/" << this->getDataOrdem().getMes() << "/" << this->getDataOrdem().getAno() << endl;
        cout << "Produto: " << this->getProduto() << endl;
        cout << "Quantidade: " << this->getQuantidade() << endl;
    }
}