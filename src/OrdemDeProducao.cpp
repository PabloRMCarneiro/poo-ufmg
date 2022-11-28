#include "../include/OrdemDeProducao.h"
#include "../include/Empresa.h"
#include "../include/UsuarioLogado.h"

OrdemDeProducao::OrdemDeProducao()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.OrdemDeProducao"))
    {
    PermissaoNegada *a = new PermissaoNegada("OrdemDeProducao", "OrdemDeProducao");
    string menssagem = "Acessa negado a OrdemDeProducao.OrdemDeProducao";
    throw menssagem;
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
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.OrdemDeProducao"))
    {
    PermissaoNegada *a = new PermissaoNegada("OrdemDeProducao", "OrdemDeProducao");
    string menssagem = "Acessa negado a OrdemDeProducao.OrdemDeProducao";
    throw menssagem;
    }
    else
    {
        this->setDataOrdem(dO);
        this->setProduto(p);
        this->setQuantidade(q);
        Empresa::getEmpresa()->setOrdemDeProducao(this);
    }
}

void OrdemDeProducao::setDataOrdem(Data dO)
{   
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.setDataOrdem"))
    {
    PermissaoNegada *a = new PermissaoNegada("setDataOrdem", "OrdemDeProducao");
    string menssagem = "Acessa negado a OrdemDeProducao.setDataOrdem";
    throw menssagem;
    }
    else{
    this->dataOrdem = dO;
    LogEscrita *a = new LogEscrita("dataOrdem", "indefinido", dataOrdem.getData(), "OrdemDeProducao");
    }
}

void OrdemDeProducao::setProduto(string p)
{   
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.setProduto"))
    {
    PermissaoNegada *a = new PermissaoNegada("setProduto", "OrdemDeProducao");
    string menssagem = "Acessa negado a OrdemDeProducao.setProduto";
    throw menssagem;
    }
    else{
    this->produto = p;
    LogEscrita *a = new LogEscrita("produto", "indefinido", p, "OrdemDeProducao");
    }
}

void OrdemDeProducao::setQuantidade(int q)
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.setQuantidade"))
    {
    PermissaoNegada *a = new PermissaoNegada("setQuantidade", "OrdemDeProducao");
    string menssagem = "Acessa negado a OrdemDeProducao.setQuantidade";
    throw menssagem;
    }
    else{
    LogEscrita *a = new LogEscrita("quantidade", "indefinido", to_string(q), "OrdemDeProducao");
    this->quantidade = q;
    }
}

Data OrdemDeProducao::getDataOrdem()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.getDataOrdem"))
    {
    PermissaoNegada *a = new PermissaoNegada("getDataOrdem", "OrdemDeProducao");
    string menssagem = "Acessa negado a OrdemDeProducao.getDataOrdem";
    throw menssagem;
    }
    else
    {
        LogLeitura *logLeitura = new LogLeitura("dataOrdem", "OrdemDeProducao");
        return this->dataOrdem;
    }
}

string OrdemDeProducao::getProduto()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.getProduto"))
    {
    PermissaoNegada *a = new PermissaoNegada("getProduto", "OrdemDeProducao");
    string menssagem = "Acessa negado a OrdemDeProducao.getProduto";
    throw menssagem;
    }
    else
    {
        LogLeitura *logLeitura = new LogLeitura("produto", "OrdemDeProducao");
        return this->produto;
    }
}

int OrdemDeProducao::getQuantidade()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.getQuantidade"))
    {
    PermissaoNegada *a = new PermissaoNegada("getQuantidade", "OrdemDeProducao");
    string menssagem = "Acessa negado a OrdemDeProducao.getQuantidade";
    throw menssagem;
    }
    else
    {
        LogLeitura *logLeitura = new LogLeitura("quantidade", "OrdemDeProducao");
        return this->quantidade;
    }
}

void OrdemDeProducao::getOrdem()
{
    if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeProducao.getOrdem"))
    {
    PermissaoNegada *a = new PermissaoNegada("getOrdem", "OrdemDeProducao");
    string menssagem = "Acessa negado a OrdemDeProducao.getOrdem";
    throw menssagem;
    }
    else
    {
        cout << "Data da Ordem: " << this->getDataOrdem().getDia() << "/" << this->getDataOrdem().getMes() << "/" << this->getDataOrdem().getAno() << endl;
        cout << "Produto: " << this->getProduto() << endl;
        cout << "Quantidade: " << this->getQuantidade() << endl;
    }
}