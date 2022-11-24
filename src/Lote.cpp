#include "../include/Lote.h"
#include "../include/UsuarioLogado.h"

Lote::Lote()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.Lote"))
    {
        throw "Acesso negado a Lote.Lote";
    }
    else
    {
        numLote = 0;
        quantidadeProduzida = 0;
        quantidadeAtual = 0;
        produto = "";
        dataProd = Data();
    }
}

Lote::Lote(int nl)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.Lote"))
    {
        throw "Acesso negado a Lote.Lote";
    }
    else
    {
        this->setNumLote(nl);
    }
}

Lote::Lote(Data d, int nl, int qp, string p)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.Lote"))
    {
        throw "Acesso negado a Lote.Lote";
    }
    else
    {
        this->setNumLote(nl);
        this->setProduto(p);
        this->setQuantidadeAtual(qp);
        this->setQuantidadeProduzida(qp);
        this->setDataProd(d);
    }
}

void Lote::setDataProd(Data d)
{
    this->dataProd = d;
}

void Lote::setNumLote(int nl)
{
    this->numLote = nl;
}

void Lote::setProduto(string p)
{
    this->produto = p;
}

void Lote::setQuantidadeAtual(int qa)
{
    this->quantidadeAtual = qa;
}

void Lote::setQuantidadeProduzida(int qp)
{
    this->quantidadeProduzida = qp;
}

Data Lote::getDataProd()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getDataProd"))
    {
        throw "Acesso negado a Lote.getDataProd";
    }
    else
    {
        return this->dataProd;
    }
}
int Lote::getNumLote()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getNumLote"))
    {
        throw "Acesso negado a Lote.getNumLote";
    }
    else
    {
        return this->numLote;
    }
}
string Lote::getProduto()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getProduto"))
    {
        throw "Acesso negado a Lote.getProduto";
    }
    else
    {
        return this->produto;
    }
}
int Lote::getQuantidadeAtual()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getQuantidadeAtual"))
    {
        throw "Acesso negado a Lote.getQuantidadeAtual";
    }
    else
    {
        return this->quantidadeAtual;
    }
}
int Lote::getQuantidadeProduzida()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getQuantidadeProduzida"))
    {
        throw "Acesso negado a Lote.getQuantidadeProduzida";
    }
    else
    {
        return this->quantidadeProduzida;
    }
}

void Lote::imprimeRegistro()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.imprimeRegistro"))
    {
        throw "Acesso negado a Lote.imprimeRegistro";
    }
    else
    {
        cout << "Lote: " << this->getNumLote() << endl;
        cout << "Produto: " << this->getProduto() << endl;
        cout << "Data de producao: " << this->getDataProd().getDia() << "/" << this->getDataProd().getMes() << "/" << this->getDataProd().getAno() << endl;
        cout << "Quantidade produzida: " << this->getQuantidadeProduzida() << endl;
        cout << "Quantidade atual: " << this->getQuantidadeAtual() << endl;
    }
}

int Lote::vende(int q)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.vende"))
    {
        throw "Acesso negado a Lote.vende";
    }
    else
    {
        if (q <= this->getQuantidadeAtual())
        {
            this->setQuantidadeAtual(this->quantidadeAtual - q);
            return this->getQuantidadeAtual();
        }
        else
        {
            this->setQuantidadeAtual(0);
            return q - this->getQuantidadeAtual();
        }
    }
}
