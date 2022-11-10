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
void Veiculo::setTempoDeRota(int valTempoDeRota){
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
    return (valDistancia/VELOCIDADE)*3600;
}
void Veiculo::setHoraSaida(){
    int tempoTotal, horaDoBusaoSair, horaturno, hora, minuto, segundo;
    Data valInicioTurno = this->turno->getEntradaHora();
    horaturno = valInicioTurno.getHora()*3600+ valInicioTurno.getMin()*60 + valInicioTurno.getSeg();
    horaDoBusaoSair = horaturno -600 - this->tempoDeRota; //hora do turno -10 min -tempodeRota
    hora = int(horaDoBusaoSair/3600);
    minuto = int((horaDoBusaoSair%3600)/60);
    segundo = horaDoBusaoSair-(hora*3600 + minuto*60);
    this->horaSaida =  Data(0,0,0, hora, minuto, segundo);
}
Data tempoEmpresaCasa(int valTempo, Data valLocal){
    int tempoTotal, horaEntrada, horaturno, hora, minuto, segundo;
    hora = valLocal.getHora()*3600+ valLocal.getMin()*60 + valLocal.getSeg();
}
void Veiculo::calculaRota(Endereco valEndereco){
    double distanciaDaEmpresa = 0.0, distanciaTotal = 0.0;
    int tempoAteEmpresa = 0, tempoTot = 0;
    if(this->rota.empty()){
        distanciaDaEmpresa = valEndereco.getDistancia(0, 0); // em km
        distanciaTotal = distanciaDaEmpresa*2; // em km
        tempoTot = int(this->calculaTempo(distanciaTotal)); // em segundos
        this->setTempoDeRota(tempoTot);
        this->setHoraSaida();
        tempoAteEmpresa = int(this->calculaTempo(distanciaDaEmpresa));
        Data horaCasa1 = tempoEmpresaCasa(tempoAteEmpresa, this->horaSaida);
        rota[valEndereco.getEndereco()] = horaCasa1;
    }
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
int Veiculo::getTempoDeRota(){
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