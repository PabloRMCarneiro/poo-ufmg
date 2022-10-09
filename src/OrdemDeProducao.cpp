#include "../include/OrdemDeProducao.h"

OrdemDeProducao::OrdemDeProducao(){
    
}
OrdemDeProducao::OrdemDeProducao(Data dO, string p, int q){
    this->setDataOrdem(dO);
    this->setProduto(p);
    this->setQuantidade(q);
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
void OrdemDeProducao::getOrdem(){
    cout << "Em " << this->dataOrdem.getData() << " foi feita uma ordem de producao de "; 
    cout << this->quantidade << " unidades de " << this->produto << "." << endl;
}