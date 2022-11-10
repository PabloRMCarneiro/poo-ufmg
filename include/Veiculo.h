#ifndef VEICULO_H_INCLUDED
#define VEICULO_H_INCLUDED
#include "Funcionario.h"
#include <map>
#define VELOCIDADE 18

class Veiculo{
    private:
        int id;
        int capacidade;
        int atual;
        int tempoDeRota; //segundos
        Data horaSaida;
        Turno* turno;
        map<string, Data> rota;
        vector<Funcionario*> passageiros;
    public:
    //construtor
        Veiculo();
        Veiculo(int valId, int valCapacidade, Turno* valTurno);
    //metodos set
        void setId(int valId);
        void setCapacidade(int valCapacidade);
        void setAtual(int valAtual);
        void setTempoDeRota(int valTempoDeRota);
        void setTurno(Turno* valTurno);
        void setRota(map<string, Data> valRota);
        void setPosicaoRota(string valEndereco, Data valHora);
        void setPassageiros(vector<Funcionario*> valPassageiros);
        void setPassageiro(Funcionario* valPassageiro);
        void setHoraSaida();
    //metodos get
        int getId();
        int getCapacidade();
        int getAtual();
        int getTempoDeRota();
        Data getHoraSaida();
        Turno* getTurno();
        map<string, Data> getRota();
        Data getHoraPosicao(Funcionario* valPassageiro);
        vector<Funcionario*> getPassageiros();
        Funcionario* getPassageiro(string valEndereco);
        void calculaRota(Endereco valEndereco);
        double calculaTempo(double valDistancia);
        
};
#endif //VEICULO_H_INCLUDED