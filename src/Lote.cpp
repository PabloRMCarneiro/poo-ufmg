#include "../include/Lote.h"
#include "../include/Empresa.h"
// construtores
Lote::Lote()
{
    if(!Empresa::getEmpresa()->getAcesso("Lote.Lote"))
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
    if(!Empresa::getEmpresa()->getAcesso("Lote.Lote"))
    {
        throw "Acesso negado a Lote.Lote";
    }
    else
        this->setNumLote(nl);
}
Lote::Lote(Data d, int nl, int qp, string p)
{
    if(!Empresa::getEmpresa()->getAcesso("Lote.Lote"))
    {
        throw "Acesso negado a Lote.Lote ";
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

// metodos set
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

// metodos set
Data Lote::getDataProd()
{
    if(!Empresa::getEmpresa()->getAcesso("Lote.getDataProd"))
    {
        throw "Acesso negado a Lote.getDataProd";
    }
    else
        return this->dataProd;
}
int Lote::getNumLote()
{
    if(!Empresa::getEmpresa()->getAcesso("Lote.getNumLote"))
    {
        throw "Acesso negado a Lote.getNumLote";
    }
    else
        return this->numLote;
}
string Lote::getProduto()
{
    if(!Empresa::getEmpresa()->getAcesso("Lote.getProduto"))
    {
        throw "Acesso negado a Lote.getProduto";
    }
    else
        return this->produto;
}
int Lote::getQuantidadeAtual()
{
    if(!Empresa::getEmpresa()->getAcesso("Lote.getQuantidadeAtual"))
    {
        throw "Acesso negado a Lote.getQuantidadeAtual";
    }
    else
        return this->quantidadeAtual;
}
int Lote::getQuantidadeProduzida()
{
    if(!Empresa::getEmpresa()->getAcesso("Lote.getQuantidadeProduzida"))
    {
        throw "Acesso negado a Lote.getQuantidadeProduzida";
    }
    else
        return this->quantidadeProduzida;
}
// para imprimir registro de producao
void Lote::imprimeRegistro()
{  
    if(!Empresa::getEmpresa()->getAcesso("Lote.imprimeRegistro"))
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
// para realizar venda -> retorna quantidade que não foi possivel vender neste lote
int Lote::vende(int q)
{
    if(!Empresa::getEmpresa()->getAcesso("Lote.vende"))
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
