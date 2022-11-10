#include "../include/Fornecedor.h"
//construtor
Fornecedor::Fornecedor():Pessoa(){
    this->tipoFornecedor = "";
}
Fornecedor::Fornecedor(string valNome, Endereco valEndereco, string valEmail, string valDocumento, long int valTelefone):Pessoa(valNome, valEndereco, valEmail, valDocumento, valTelefone){
    this->setTipoFornecedor(valDocumento);
}
//metodos set
void Fornecedor::setPrecos(vector<pair<MateriaPrima*, double>> valPrecos){
    for(auto it : valPrecos){
        this->setPreco(make_pair(it.first, it.second));
    }
}
void Fornecedor::setPreco(pair<MateriaPrima*, double> valMateriaPrima){
    this->precos.push_back(valMateriaPrima);
}
void Fornecedor::setTipoFornecedor(string valTipoFornecedor){
    if(valTipoFornecedor.length() == 11){
        this->tipoFornecedor = "Pessoa física";
    }
    if(valTipoFornecedor.length() == 14){
        this->tipoFornecedor = "Pessoa jurídica";
    }
}
//metodos get
string Fornecedor::getTipoFornecedor(string valTipoFornecedor){
    return this->tipoFornecedor;
}
double Fornecedor::getPreco(MateriaPrima* valMateriaPrima){
    for(auto it : precos){
        if(it.first == valMateriaPrima){
            return it.second;
            break;
        }
    }
}
vector <pair<MateriaPrima*, double>> Fornecedor::getPrecos(){
    return this->precos;
}
bool Fornecedor::vende(MateriaPrima* valMateriaPrima, double valQuantidade, Data valData){
    valMateriaPrima->setEstoque(valQuantidade, valData);
}