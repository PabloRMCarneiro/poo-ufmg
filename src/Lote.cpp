#include "../include/Lote.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"
#include "../include/PermissaoNegada.h"

Lote::Lote()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.Lote"))
    {
        PermissaoNegada *a = new PermissaoNegada("Lote", "Lote");
        string mensagem = "Acesso negado a Lote.Lote";
        throw mensagem;
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
        PermissaoNegada *a = new PermissaoNegada("Lote", "Lote");
        string mensagem = "Acesso negado a Lote.Lote";
        throw mensagem;
    }
    else
    {
        this->setNumLote(nl);
    }
}

Lote::Lote(Data d, int nl, int qp, string p)
{
    if (! UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.Lote"))
    {
        PermissaoNegada *a = new PermissaoNegada("Lote", "Lote");
        string mensagem = "Acesso negado a Lote.Lote";
        throw mensagem;
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
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.setDataProd"))
    {
        PermissaoNegada *a = new PermissaoNegada("setDataProd", "Lote");
        string mensagem = "Acesso negado a Lote.setDataProd";
        throw mensagem;
    }
    else
    {
        this->dataProd = d;
        LogEscrita *a = new LogEscrita("tipoCliente", "indefinido", d.getData(), "Lote");
    }
   
}

void Lote::setNumLote(int nl)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.setNumLote"))
    {
        PermissaoNegada *a = new PermissaoNegada("setNumLote", "Lote");
        string mensagem = "Acesso negado a Lote.setNumLote";
        throw mensagem;
    }
    else
    {
        this->numLote = nl;
        LogEscrita *a = new LogEscrita("tipoCliente", "indefinido", to_string(nl), "Lote");
    }
}

void Lote::setProduto(string p)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.setProduto"))
    {
        PermissaoNegada *a = new PermissaoNegada("setProduto", "Lote");
        string mensagem = "Acesso negado a Lote.setProduto";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("tipoCliente", "indefinido", p, "Lote");
        this->produto = p;
    }
}

void Lote::setQuantidadeAtual(int qa)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.setQuantidadeAtual"))
    {
        PermissaoNegada *a = new PermissaoNegada("setQuantidadeAtual", "Lote");
        string mensagem = "Acesso negado a Lote.setQuantidadeAtual";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("tipoCliente", to_string(quantidadeAtual), to_string(qa), "Lote");
        this->quantidadeAtual = qa;
    }
}

void Lote::setQuantidadeProduzida(int qp)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.setQuantidadeProduzida"))
    {
        PermissaoNegada *a = new PermissaoNegada("setQuantidadeProduzida", "Lote");
        string mensagem = "Acesso negado a Lote.setQuantidadeProduzida";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("tipoCliente", to_string(quantidadeProduzida), to_string(qp), "Lote");
        this->quantidadeProduzida = qp;
    }
}

Data Lote::getDataProd()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getDataProd"))
    {
        PermissaoNegada *a = new PermissaoNegada("getDataProd", "Lote");
        string mensagem = "Acesso negado a Lote.getDataProd";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("dataProd", "Lote");
        return this->dataProd;
    }
}
int Lote::getNumLote()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getNumLote"))
    {   
        PermissaoNegada *a = new PermissaoNegada("getNumLote", "Lote");
        string mensagem = "Acesso negado a Lote.getNumLote";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("numLote", "Lote");
        return this->numLote;
    }
}
string Lote::getProduto()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getProduto"))
    {
        PermissaoNegada *a = new PermissaoNegada("getProduto", "Lote");
        string mensagem = "Acesso negado a Lote.getProduto";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("produto", "Lote");
        return this->produto;
    }
}
int Lote::getQuantidadeAtual()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getQuantidadeAtual"))
    {
        PermissaoNegada *a = new PermissaoNegada("getQuantidadeAtual", "Lote");
        string mensagem = "Acesso negado a Lote.getQuantidadeAtual";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("quantidadeAtual", "Lote");
        return this->quantidadeAtual;
    }
}
int Lote::getQuantidadeProduzida()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.getQuantidadeProduzida"))
    {
        PermissaoNegada *a = new PermissaoNegada("getQuantidadeProduzida", "Lote");
        string mensagem = "Acesso negado a Lote.getQuantidadeProduzida";
        throw mensagem;
    }
    else
    {
        LogLeitura *a = new LogLeitura("quantidadeProduzida", "Lote");
        return this->quantidadeProduzida;
    }
}

void Lote::imprimeRegistro()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Lote.imprimeRegistro"))
    {
        PermissaoNegada *a = new PermissaoNegada("imprimeRegistro", "Lote");
        string mensagem = "Acesso negado a Lote.imprimeRegistro";
        throw mensagem;
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
        PermissaoNegada *a = new PermissaoNegada("vende", "Lote");
        string mensagem = "Acesso negado a Lote.vende";
        throw mensagem;
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