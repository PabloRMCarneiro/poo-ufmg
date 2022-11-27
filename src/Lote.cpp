#include "../include/Lote.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"
//LogEscrita *a = new LogEscrita("tipoCliente", "indefinido", this->tipoCliente, "Lote");
//LogLeitura *a = new LogLeitura("tipoCliente", "Lote");
Lote::Lote()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.Lote"))
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
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.Lote"))
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
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.Lote"))
    {
        throw "Acesso negado a Lote.Lote";
    }
    else
    {
        this->setNumLote(nl);
        this->setProduto(p);
        this->quantidadeAtual = qp;
        LogEscrita *a = new LogEscrita("quantidadeAtual", "indefinido", to_string(qp), "Lote");
        this->setQuantidadeProduzida(qp);
        this->setDataProd(d);
    }
}

void Lote::setDataProd(Data d)
{
    this->dataProd = d;
    LogEscrita *a = new LogEscrita("tipoCliente", "indefinido", d.getData(), "Lote");
}

void Lote::setNumLote(int nl)
{
    this->numLote = nl;
    LogEscrita *a = new LogEscrita("tipoCliente", "indefinido", to_string(nl), "Lote");
}

void Lote::setProduto(string p)
{
    LogEscrita *a = new LogEscrita("tipoCliente", "indefinido", p, "Lote");
    this->produto = p;
}

void Lote::setQuantidadeAtual(int qa)
{
    LogEscrita *a = new LogEscrita("tipoCliente", to_string(quantidadeAtual), to_string(qa), "Lote");
    this->quantidadeAtual = qa;
}

void Lote::setQuantidadeProduzida(int qp)
{
    LogEscrita *a = new LogEscrita("tipoCliente", to_string(quantidadeProduzida), to_string(qp), "Lote");
    this->quantidadeProduzida = qp;
}

Data Lote::getDataProd()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getDataProd"))
    {
        throw "Acesso negado a Lote.getDataProd";
    }
    else
    {
        LogLeitura *a = new LogLeitura("DataProd", "Lote");
        return this->dataProd;
    }
}
int Lote::getNumLote()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getNumLote"))
    {
        throw "Acesso negado a Lote.getNumLote";
    }
    else
    {
        LogLeitura *a = new LogLeitura("NumLote", "Lote");
        return this->numLote;
    }
}
string Lote::getProduto()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getProduto"))
    {
        throw "Acesso negado a Lote.getProduto";
    }
    else
    {
        LogLeitura *a = new LogLeitura("Produto", "Lote");
        return this->produto;
    }
}
int Lote::getQuantidadeAtual()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getQuantidadeAtual"))
    {
        throw "Acesso negado a Lote.getQuantidadeAtual";
    }
    else
    {
        LogLeitura *a = new LogLeitura("QuantidadeAtual", "Lote");
        return this->quantidadeAtual;
    }
}
int Lote::getQuantidadeProduzida()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getQuantidadeProduzida"))
    {
        throw "Acesso negado a Lote.getQuantidadeProduzida";
    }
    else
    {
        LogLeitura *a = new LogLeitura("QuantidadeProduzida", "Lote");
        return this->quantidadeProduzida;
    }
}

void Lote::imprimeRegistro()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.imprimeRegistro"))
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
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.vende"))
    {
        throw "Acesso negado a Lote.vende";
    }
    else
    {
        if (q <= this->getQuantidadeAtual())
        {
            this->setQuantidadeAtual(this->quantidadeAtual - q);
            return 0;
        }
        else
        {   
            int falta = q - this->getQuantidadeAtual();
            this->setQuantidadeAtual(0);
            return falta;
        }
    }
}