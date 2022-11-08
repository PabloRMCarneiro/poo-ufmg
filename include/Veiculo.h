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
        double tempoDeRota;
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
        void setTempoDeRota(double valTempoDeRota);
        void setTurno(Turno* valTurno);
        void setRota(map<string, Data> valRota);
        void setPosicaoRota(string valEndereco, Data valHora);
        void setPassageiros(vector<Funcionario*> valPassageiros);
        void setPassageiro(Funcionario* valPassageiro);
    //metodos get
        int getId();
        int getCapacidade();
        int getAtual();
        double getTempoDeRota();
        Turno* getTurno();
        map<string, Data> getRota();
        Data getHoraPosicao(Funcionario* valPassageiro);
        vector<Funcionario*> getPassageiros();
        Funcionario* getPassageiro(string valEndereco);
};
#endif //VEICULO_H_INCLUDED