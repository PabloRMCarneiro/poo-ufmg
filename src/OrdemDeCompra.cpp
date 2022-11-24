#include "../include/OrdemDeCompra.h"

OrdemDeCompra::OrdemDeCompra(){
    this->setData(Data());
    this->valorTotal = 0.0;
}

OrdemDeCompra::OrdemDeCompra(Data valData, MateriaPrima* valMateriaPrima){
    this->setData(valData);
    this->setMateriaPrima(valMateriaPrima);
    this->valorTotal = 0.0;
}

void OrdemDeCompra::setMateriaPrimaLista(vector<MateriaPrima*> valMateriaPrima){
    for(auto it : valMateriaPrima){
        this->setMateriaPrima(it);
    }
}

void OrdemDeCompra::setMateriaPrima(MateriaPrima* valMateriaPrima){
    this->materiaPrimaLista.push_back(valMateriaPrima);
}

void OrdemDeCompra::setData(Data valData){
    this->dataOrdem = valData;
}

void OrdemDeCompra::setValorTotal(double valValorTotal){
    this->valorTotal = this->valorTotal + valValorTotal;
}

void OrdemDeCompra::setOrcamento(){
    this->valorTotal = this->valorTotal - this->dataOrdem;

}

void OrdemDeCompra::gerarPedidos(Data valData){
    for(auto it : melhoresPrecos){
        this->setCompra(it.first->vende(it.second, it.second->getEstoqueMinimo(), valData));
    }
}

void OrdemDeCompra::setMelhoresPrecos(){
    double menorPreco= 0.0, precoAtual = 0.0;
    Fornecedor * forneceMenorPreco;
    for(auto it : materiaPrimaLista){
        for(auto it2 : this->orcamento){
            for(auto it3 : it2->getHistoricoMateriaPrima()){
                if(it3.first == it){
                    if(menorPreco = 0.0){
                        menorPreco = it3.second;
                    }else if(menorPreco > it3.second){
                        menorPreco = it3.second;
                        forneceMenorPreco = it2->getFornecedor();
                    }
                }
            }
        }
        this->melhoresPrecos.push_back(make_pair(forneceMenorPreco, it));
    }
}

void OrdemDeCompra::setCompra(bool valCompra){
    this->compra = valCompra;
}