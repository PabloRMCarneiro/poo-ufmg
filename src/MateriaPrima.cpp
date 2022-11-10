#include "../include/MateriaPrima.h"
#include "../include/Empresa.h"

MateriaPrima::MateriaPrima(){
    this->setNome("");
    this->estoque = 0.0;
    this->setEstoqueMin(0.0);
    this->setUnidadeDeMedida("");
}
MateriaPrima::MateriaPrima(string valNome, string valUnidadeDeMedida, double valEstoqueMinimo){
    this->setNome(valNome);
    this->estoque = 0.0;
    this->setEstoqueMin(valEstoqueMinimo);
    this->setUnidadeDeMedida(valUnidadeDeMedida);
}
void MateriaPrima::geraOrdemDeCompra(Data valData){
    OrdemDeCompra *nova = new OrdemDeCompra(valData, this);
    Empresa::getEmpresa()->setOrdemDeCompra(nova);
}
        
double MateriaPrima::getEstoque(){
    return this->estoque;
}
string MateriaPrima::getUnidadeMedida(){
    return this->unidadeDeMedida;
}
double MateriaPrima::getEstoqueMinimo(){
    return this->estoqueMinimo;
}
string MateriaPrima::getNome(){
    return this->nome;
}
void MateriaPrima::setEstoqueMin(double valEstoqueMinimo){
    this->estoqueMinimo = valEstoqueMinimo;
}
void MateriaPrima::setEstoque(double valEstoque, Data valData){
    this->estoque = valEstoque + this->estoque;
    if(this->estoque < this->estoqueMinimo){
        this->geraOrdemDeCompra(valData);
    }
}
void MateriaPrima::setNome(string valNome){
    this->nome = valNome;
}
void MateriaPrima::setUnidadeDeMedida(string valUnidadeDeMedida){
    this->unidadeDeMedida = valUnidadeDeMedida;
}

