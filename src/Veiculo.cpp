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
double Veiculo::calculaTempo(double valDistancia){
    return (valDistancia/VELOCIDADE)*60;
}
Data Veiculo::horaSaida(double valTempo){
    valTempo = valTempo*60; // em segundos
    int tempoTotal, horaEntrada, horaturno, hora, minuto, segundo;
    Data a;// = this->turno->getEntradaHora();
    horaturno = a.getHora()*3600+ a.getMin()*60 + a.getSeg();
    horaEntrada = horaturno -600 - valTempo;
    hora = int(horaEntrada/3600);
    minuto = int((horaEntrada%3600)/60);
    segundo = horaEntrada-(hora*3600 + minuto*60);
    return Data(0,0,0, hora, minuto, segundo);
}
void Veiculo::calculaRota(Endereco valEndereco){
    // double distancia, distanciaTotal = 0, tempoTot = 0;
    // if(this->rota.empty()){
    //     distancia = valEndereco.getDistancia(0, 0);
    //     distanciaTotal = distancia*2;
    //     tempoTot = this->calculaTempo(distanciaTotal);
    //     Data a = horaSaida(tempoTot);
    //     this->setTempoDeRota(tempoTot);

    // }
    // Funcionario* anterior = new Funcionario;
    // for(auto it = passageiros.begin(); it!= passageiros.end(); ){
    //     anterior = *it;
    //     it++;
    //     if(it != passageiros.end()){
    //         distancia=anterior->getEndereco().getDistancia((*it)->getEndereco().getX(), (*it)->getEndereco().getY());
    //         tempoTot = tempoTot + distancia;
    //     } else {
    //         distancia=anterior->getEndereco().getDistancia(0, 0);
    //         tempoTot = tempoTot + distancia;
    //     }
    // }
}
void Veiculo::setPassageiros(vector<Funcionario*> valPassageiros){
    for(auto it : valPassageiros){
        this->setPassageiro(it);
    }
}
void Veiculo::setPassageiro(Funcionario* valPassageiro){
    this->passageiros.push_back(valPassageiro);
    this->calculaRota(valPassageiro->getEndereco());
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
    return this->rota[valPassageiro->getEndereco().getEndereco()];
}
vector<Funcionario*> Veiculo::getPassageiros(){
    return this->passageiros;
}
Funcionario* Veiculo::getPassageiro(string valEndereco){
    Funcionario* encontrado = new Funcionario;
    for(auto it : passageiros){
        if(it->getEndereco().getEndereco() == valEndereco){
            encontrado = it;
        }
    }
    return encontrado;
}