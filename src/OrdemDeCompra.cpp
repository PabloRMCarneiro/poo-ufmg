#include "../include/OrdemDeCompra.h"
#include "../include/UsuarioLogado.h"
#include "../include/PermissaoNegada.h"
#include "../include/Empresa.h"

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
        LogEscrita *d = new LogEscrita("valorTotal", "indefinido", to_string(valorTotal), "OrdemDeCompra");
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
        LogEscrita *d = new LogEscrita("dataOrdem", "indefinido", dataOrdem.getData(), "OrdemDeCompra");
        
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
        string valor =to_string(valorTotal);
        this->valorTotal = this->valorTotal + valValorTotal;
        LogEscrita *d = new LogEscrita("valorTotal", valor, to_string(valorTotal), "OrdemDeCompra");
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
        for (auto it : this->getMateriaPrimaLista())
        {
            valItens.push_back(make_pair(it->getNome(), it->getEstoqueMinimo()));
        }
        for (auto it : Fornecedor::fornecedorList)
        {
            Orcamento *novo = new Orcamento(false, valItens, Data::dataDeHoje, it);
            this->orcamentos.push_back(novo);
        }
        LogLeitura *d = new LogLeitura("forncedorList", "Fornecedor");
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
        for (auto it : this->getMelhoresPrecos())
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
        for (auto it : this->getMateriaPrimaLista())
        {
            for (auto it2 : this->getOrcamentos())
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
        LogEscrita *d = new LogEscrita("compra", to_string(compra), to_string(valCompra), "OrdemDeCompra");
        this->compra = valCompra;
    }
}
Data OrdemDeCompra::getDatOrdem(){
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.getDatOrdem"))
    {
        PermissaoNegada *a = new PermissaoNegada("getDatOrdem", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.getDatOrdem";
        throw mensagem;
    }
    else
    {
        LogLeitura *d = new LogLeitura("dataOrdem", "OrdemDeCompra");
        return this->dataOrdem;
    }
}
double OrdemDeCompra::getValorTotal(){
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.setCompra"))
    {
        PermissaoNegada *a = new PermissaoNegada("setCompra", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.setCompra";
        throw mensagem;
    }
    else
    {
        LogLeitura *d = new LogLeitura("valorTotal", "OrdemDeCompra");
        return this->valorTotal;
    }
}
vector <Orcamento*> OrdemDeCompra::getOrcamentos(){
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.getOrcamentos"))
    {
        PermissaoNegada *a = new PermissaoNegada("getOrcamentos", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.getOrcamentos";
        throw mensagem;
    }
    else
    {
        LogLeitura *d = new LogLeitura("orcamentos", "OrdemDeCompra");
        return this->orcamentos;
    }
}
vector<MateriaPrima*> OrdemDeCompra::getMateriaPrimaLista(){
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.getMateriaPrimaLista"))
    {
        PermissaoNegada *a = new PermissaoNegada("getMateriaPrimaLista", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.getMateriaPrimaLista";
        throw mensagem;
    }
    else
    {
        LogLeitura *d = new LogLeitura("materiaPrimaLista", "OrdemDeCompra");
        return this->materiaPrimaLista;
    }
}
vector <pair<Fornecedor*, MateriaPrima*>> OrdemDeCompra::getMelhoresPrecos(){
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.getMelhoresPrecos"))
    {
        PermissaoNegada *a = new PermissaoNegada("getMelhoresPrecos", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.getMelhoresPrecos";
        throw mensagem;
    }
    else
    {
        LogLeitura *d = new LogLeitura("melhoresPrecos", "OrdemDeCompra");
        return this->melhoresPrecos;
    }
}
bool OrdemDeCompra::getComprou(){
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("OrdemDeCompra.getComprou"))
    {
        PermissaoNegada *a = new PermissaoNegada("getComprou", "OrdemDeCompra");
        string mensagem = "Acesso negado a OrdemDeCompra.getComprou";
        throw mensagem;
    }
    else
    {
        LogLeitura *d = new LogLeitura("compra", "OrdemDeCompra");
        return this->compra;
    }
}