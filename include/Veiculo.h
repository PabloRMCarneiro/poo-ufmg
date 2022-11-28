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
        int tempoDeRota; 
        Data horaSaida;
        Turno* turno;
        map<int, Endereco> rota; 
        vector<Funcionario*> passageiros;
    public:
        Veiculo();
        Veiculo(int valId, int valCapacidade, Turno* valTurno);

        void setId(int valId);
        void setCapacidade(int valCapacidade);
        bool setAtual(int valAtual);
        void setTempoDeRota(int valTempoDeRota);
        void setTurno(Turno* valTurno);
        void setRota(map<int, Endereco> valRota);
        void setPosicaoRota(Endereco valEndereco, Data valHora);
        bool setPassageiros(vector<Funcionario*> valPassageiros);
        bool setPassageiro(Funcionario* valPassageiro);
        void setHoraSaida();

        int getId();
        int getCapacidade();
        int getAtual();
        int getTempoDeRota();
        Data getHoraSaida();
        Turno* getTurno();
        map<int, Endereco> getRota();
        Data getHoraPosicao(Funcionario* valPassageiro);
        vector<Funcionario*> getPassageiros();
        Funcionario* getPassageiro(Endereco valEndereco);
        void calculaRota(Endereco valEndereco);
        double calculaTempo(double valDistancia);
        int tempoEmpresaCasa(int valTempo);
        int auxiliarTempoSegundos(Data valHora); 
        Data auxiliarTempoHora(int valHora); 
        void excluiPassageiro(Funcionario* valPassageiro);
};
#endif 