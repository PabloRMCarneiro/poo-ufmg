#include "../include/OrdemDeProducao.h"
#include "../include/Empresa.h"

OrdemDeProducao::OrdemDeProducao(){
    if(!Empresa::getEmpresa()->getAcesso("OrdemDeProducao.OrdemDeProducao"))
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
OrdemDeProducao::OrdemDeProducao(Data dO, string p, int q){

    if(!Empresa::getEmpresa()->getAcesso("OrdemDeProducao.OrdemDeProducao"))
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

void OrdemDeProducao::setDataOrdem(Data dO){
    this->dataOrdem = dO;
}
void OrdemDeProducao::setProduto(string p){
    this->produto = p;
}
void OrdemDeProducao::setQuantidade(int q){
    this->quantidade = q;
}

Data OrdemDeProducao::getDataOrdem(){
    if(!Empresa::getEmpresa()->getAcesso("OrdemDeProducao.getDataOrdem"))
    {
        throw "Acesso negado a OrdemDeProducao.getDataOrdem";
    }
    else
    {
        return this->dataOrdem;
    }
}
string OrdemDeProducao::getProduto(){
    if(!Empresa::getEmpresa()->getAcesso("OrdemDeProducao.getProduto"))
    {
        throw "Acesso negado a OrdemDeProducao.getProduto";
    }
    else
    {
        return this->produto;
    }
}
int OrdemDeProducao::getQuantidade(){
    if(!Empresa::getEmpresa()->getAcesso("OrdemDeProducao.getQuantidade"))
    {
        throw "Acesso negado a OrdemDeProducao.getQuantidade";
    }
    else
    {
        return this->quantidade;
    }
}

void OrdemDeProducao::getOrdem(){

    if(!Empresa::getEmpresa()->getAcesso("OrdemDeProducao.OrdemDeProducao"))
    {
        throw "Acesso negado a OrdemDeProducao.OrdemDeProducao";
    }
    else 
    {
        cout << "Data da Ordem: " << this->getDataOrdem().getDia() << "/" << this->getDataOrdem().getMes() << "/" << this->getDataOrdem().getAno() << endl;
        cout << "Produto: " << this->getProduto() << endl;
        cout << "Quantidade: " << this->getQuantidade() << endl;
    }
}