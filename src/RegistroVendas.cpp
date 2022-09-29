#include "../include/RegistroVendas.h"
//construtores
RegistroVendas::RegistroVendas(Data dv, string p, int q){
    this->setDataDeVenda(dv);
    this->setProduto(p);
    this->setQuantidadeVenda(q);
}
RegistroVendas::RegistroVendas(Data dv, Produto* p, int q){
    this->setDataDeVenda(dv);
    this->setProduto(p);
    this->setQuantidadeVenda(q);
}
//metodos get
Data RegistroVendas::getDataDeVenda(){
    return this->dataDeVenda;
}
vector<int> RegistroVendas::getNumeroDoLote(){
    return this->lote;
}
Produto* RegistroVendas::getProduto(){
    return this->produto;
}
int RegistroVendas::getQuantidadeVenda(){
    return this->quantidadeVenda;
}
//metodos set
void RegistroVendas::setDataDeVenda(Data v){
    this->dataDeVenda = v;
}
void RegistroVendas::setNumeroDoLote(int nl){
    this->lote.push_back(nl);
}
void RegistroVendas::setProduto(string p){
    this->produto = Produto::getProduto(p);
}
void RegistroVendas::setProduto(Produto* p){
    this->produto = p;
}
void RegistroVendas::setQuantidadeVenda(int qvenda){
    this->quantidadeVenda = qvenda;
    if(this->validaVenda(qvenda)){
        pair<int, int> a = this->produto->realizaVenda(qvenda, this->dataDeVenda);
        this->lote.push_back(a.first);
        while(a.second > 0){
        pair<int, int> a = this->produto->realizaVenda(qvenda, this->dataDeVenda);
        this->lote.push_back(a.first);
        }
    }
}
bool RegistroVendas::validaVenda(int q){
    this->vendido = this->produto->temEstoque(q);
    return this->vendido;
}