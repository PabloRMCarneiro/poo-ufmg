#include "../include/Veiculo.h"
//construtor
Veiculo::Veiculo(){
    this->setId(0);
    this->setCapacidade(0);
    this->setAtual(0);
    this->setTempoDeRota(0);
    this->setTurno(nullptr);
}
Veiculo::Veiculo(int valId, int valCapacidade, Turno* valTurno){
    this->setId(valId);
    this->setCapacidade(valCapacidade);
    this->setTurno(valTurno);
    this->tempoDeRota = 0;
}
//metodos set
void Veiculo::setId(int valId){
    this->id = valId;
}
void Veiculo::setCapacidade(int valCapacidade){
    this->capacidade = valCapacidade;
}
void Veiculo::setAtual(int valAtual){
    this->atual = valAtual;
}
void Veiculo::setTempoDeRota(double valTempoDeRota){
    this->tempoDeRota = this->tempoDeRota + valTempoDeRota;
}
void Veiculo::setTurno(Turno* valTurno){
    this->turno = valTurno;
}
void Veiculo::setRota(map<string, Data> valRota){
    this->rota = valRota;
}
void Veiculo::setPosicaoRota(string valEndereco, Data valHora){
    this->rota[valEndereco] = valHora;
}
void Veiculo::setPassageiros(vector<Funcionario*> valPassageiros){
    this->passageiros = valPassageiros;
}
void Veiculo::setPassageiro(Funcionario* valPassageiro){
    this->passageiros.push_back(valPassageiro);
}
//metodos get
int Veiculo::getId(){
    return this->id;
}
int Veiculo::getCapacidade(){
    return this->capacidade;
}
int Veiculo::getAtual(){
    return this->atual;
}
double Veiculo::getTempoDeRota(){
    return this->tempoDeRota;
}
Turno* Veiculo::getTurno(){
    return this->turno;
}
map<string, Data> Veiculo::getRota(){
    return this->rota;
}
Data Veiculo::getHoraPosicao(Funcionario* valPassageiro){
    return this->rota[valPassageiro->getEndereco()];
}
vector<Funcionario*> Veiculo::getPassageiros(){
    return this->passageiros;
}
Funcionario* Veiculo::getPassageiro(string valEndereco){
    Funcionario* encontrado = new Funcionario;
    for(auto it : passageiros){
        if(it->getEndereco() == valEndereco){
            encontrado = it;
        }
    }
    return encontrado;
}