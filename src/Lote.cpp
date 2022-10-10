#include "../include/Lote.h"
#include "../include/Empresa.h"
// construtores
Lote::Lote()
{
    if(!Empresa::getEmpresa()->getAcesso("Lote.Lote"))
    {
        throw "Acesso negado";
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
        throw "Acesso negado";
    }
    else
        this->setNumLote(nl);
}
Lote::Lote(Data d, int nl, int qp, string p)
{
    if(!Empresa::getEmpresa()->getAcesso("Lote.Lote"))
    {
        throw "Acesso negado";
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
    return this->dataProd;
}
int Lote::getNumLote()
{
    return this->numLote;
}
string Lote::getProduto()
{
    return this->produto;
}
int Lote::getQuantidadeAtual()
{
    return this->quantidadeAtual;
}
int Lote::getQuantidadeProduzida()
{
    return this->quantidadeProduzida;
}
// para imprimir registro de producao
void Lote::imprimeRegistro()
{
    cout << "Registro de producao de/o/a " << this->getProduto() << ":" << endl;
    cout << "Produziu-se " << this->getQuantidadeProduzida() << " unidades em ";
    cout << this->getDataProd().getData() << endl;
}
// para realizar venda -> retorna quantidade que não foi possivel vender neste lote
int Lote::vende(int q)
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
        return (falta);
    }
}
