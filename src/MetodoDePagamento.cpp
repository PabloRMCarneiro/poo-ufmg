#include "../include/MetodoDePagamento.h"

MetodoDePagamento::MetodoDePagamento() {
    
    this->tipoDePagamento = "";
    this->quantidadeDeParcelas = 0;
    this->parcelamento = {0};
    this->data = Data();
}

MetodoDePagamento::~MetodoDePagamento() {
    
}

MetodoDePagamento::MetodoDePagamento(string valTipoDePagamento, int valQuantidadeDeParcelas, vector<float> valParcelamento, Data valData) {

    this->tipoDePagamento = valTipoDePagamento;
    this->quantidadeDeParcelas = valQuantidadeDeParcelas;
    this->parcelamento = valParcelamento;
    this->data = valData;
}

string MetodoDePagamento::getTipoDePagamento() {
    return tipoDePagamento;
}

int MetodoDePagamento::getQuantidadeDeParcelas() {
    return quantidadeDeParcelas;
}

vector<float> MetodoDePagamento::getParcelamento() {
    return parcelamento;
}

Data MetodoDePagamento::getData() {
    return data;
}

void MetodoDePagamento::setTipoDePagamento(string valTipoDePagamento) {
    this->tipoDePagamento = valTipoDePagamento;
}

void MetodoDePagamento::setQuantidadeDeParcelas(int valQuantidadeDeParcelas) {
    this->quantidadeDeParcelas = valQuantidadeDeParcelas;
}

void MetodoDePagamento::setParcelamento(vector<float> valParcelamento) {
    this->parcelamento = valParcelamento;
}

void MetodoDePagamento::setData(Data valData) {
    this->data = valData;
}