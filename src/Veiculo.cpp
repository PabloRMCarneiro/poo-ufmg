#include "../include/Veiculo.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"

Veiculo::Veiculo()
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.Veiculo"))
    {
        throw "Acesso negado a Veiculo.Veiculo";
    }
    else
    {
        this->setId(0);
        this->setCapacidade(0);
        this->atual = 0;
        this->tempoDeRota = 0;
        this->setTurno(nullptr);
    }
}

Veiculo::Veiculo(int valId, int valCapacidade, Turno *valTurno)
{
    if (false)//!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.Veiculo"))
    {
        throw "Acesso negado a Veiculo.Veiculo";
    }
    else
    {
        this->setId(valId);
        this->setCapacidade(valCapacidade);
        this->setTurno(valTurno);
        this->atual = 0;
        this->tempoDeRota = 0;
    }
}

void Veiculo::setId(int valId)
{
    this->id = valId;
}

void Veiculo::setCapacidade(int valCapacidade)
{
    this->capacidade = valCapacidade;
}

bool Veiculo::setAtual(int valAtual)
{
    bool adicionar;
    if (this->atual == this->capacidade)
    {
        adicionar = false;
    }
    else
    {
        this->atual = this->atual + valAtual;
        adicionar = true;
    }
    return adicionar;
}

void Veiculo::setTempoDeRota(int valTempoDeRota)
{
    this->tempoDeRota = this->tempoDeRota + valTempoDeRota;
    this->setHoraSaida();
}

void Veiculo::setTurno(Turno *valTurno)
{
    this->turno = valTurno;
    this->setHoraSaida();
}

void Veiculo::setRota(map<int, Endereco> valRota)
{
    this->rota = valRota;
}

void Veiculo::setPosicaoRota(Endereco valEndereco, Data valHora)
{
    int tempo = this->auxiliarTempoSegundos(valHora);
    this->rota[tempo] = valEndereco;
}

double Veiculo::calculaTempo(double valDistancia)
{
    return (valDistancia / VELOCIDADE) * 3600;
}

void Veiculo::setHoraSaida()
{
    int tempoTotal, horaDoBusaoSair, horaturno, hora, minuto, segundo;
    Data valInicioTurno = this->turno->getEntradaHora();
    horaturno = this->auxiliarTempoSegundos(valInicioTurno);
    horaDoBusaoSair = horaturno - 600 - this->tempoDeRota; // hora do turno -10 min -tempodeRota
    this->horaSaida = this->auxiliarTempoHora(horaDoBusaoSair);
}

int Veiculo::auxiliarTempoSegundos(Data valHora)
{
    int tempo;
    tempo = valHora.getHora() * 3600 + valHora.getMin() * 60 + valHora.getSeg(); // em segundos
    return tempo;
}

Data Veiculo::auxiliarTempoHora(int valHora)
{
    int hora, minuto, segundo;
    hora = int(valHora / 3600);
    minuto = int((valHora % 3600) / 60);
    segundo = valHora - (hora * 3600 + minuto * 60);
    return Data(0, 0, 0, hora, minuto, segundo);
}

int Veiculo::tempoEmpresaCasa(int valTempo)
{
    int tempoTotal, horaSaida, horaturno, hora, minuto, segundo;
    Data valLocal = this->horaSaida;
    horaSaida = valLocal.getHora() * 3600 + valLocal.getMin() * 60 + valLocal.getSeg();
    tempoTotal = horaSaida + valTempo;
    return tempoTotal;
}

void Veiculo::calculaRota(Endereco valEndereco)
{
    double distanciaDaEmpresa = 0.0, distanciaTotal = 0.0, distanciaAteEndereco1 = 0.0;
    int tempoAteEmpresa = 0, tempoTot = 0, horaCasa1 = 0;
    if (this->rota.empty())
    {
        distanciaDaEmpresa = valEndereco.getDistancia(Empresa::getEmpresa()->getEndereco().getX(), Empresa::getEmpresa()->getEndereco().getY()); // em km
        distanciaTotal = distanciaDaEmpresa * 2;             // em km
        tempoTot = int(this->calculaTempo(distanciaTotal));  // em segundos
        this->setTempoDeRota(tempoTot);
        tempoAteEmpresa = int(this->calculaTempo(distanciaDaEmpresa)); // tempo da empresa ate a nova casa 1
        horaCasa1 = this->tempoEmpresaCasa(tempoAteEmpresa);
        rota[horaCasa1] = valEndereco;
    }
    else
    {
        for (auto it : rota)
        {
            distanciaDaEmpresa = valEndereco.getDistancia(Empresa::getEmpresa()->getEndereco().getX(), Empresa::getEmpresa()->getEndereco().getY());
            distanciaAteEndereco1 = valEndereco.getDistancia(it.second.getX(), it.second.getY());
            distanciaTotal = distanciaDaEmpresa + distanciaAteEndereco1;
            tempoTot = int(this->calculaTempo(distanciaTotal));
            this->setTempoDeRota(tempoTot);
            tempoAteEmpresa = int(this->calculaTempo(distanciaDaEmpresa));
            horaCasa1 = this->tempoEmpresaCasa(tempoAteEmpresa);
            rota[horaCasa1] = valEndereco;
            break;
        }
    }
}

void Veiculo::excluiPassageiro(Funcionario *valPassageiro)
{
    vector<Funcionario *> listaSubstituta;
    for (auto it : this->passageiros)
    {
        if (it != valPassageiro)
        {
            listaSubstituta.push_back(it);
        }
    }
    this->setPassageiros(listaSubstituta);
}

bool Veiculo::setPassageiros(vector<Funcionario *> valPassageiros)
{
    bool adicionar = false;
    try
    {
        if (valPassageiros.size() <= this->capacidade)
        {   
            rota.clear();
            for (auto it : valPassageiros)
            {
                adicionar = this->setPassageiro(it);
            }
        }
        else
        {
            throw 1;
        }
    }
    catch (int e)
    {
        cout << "Erro: " << e << " - A capacidade do veiculo e menor que a quantidade de passageiros" << endl;
    }
    return adicionar;
}

bool Veiculo::setPassageiro(Funcionario *valPassageiro)
{
    bool adicionar = false;
    if (this->setAtual(1))
    {
        this->passageiros.push_back(valPassageiro);
        this->calculaRota(valPassageiro->getEndereco());
        adicionar = true;
    }
    return adicionar;
}

int Veiculo::getId()
{
    return this->id;
}

int Veiculo::getCapacidade()
{
    return this->capacidade;
}

int Veiculo::getAtual()
{
    return this->atual;
}

int Veiculo::getTempoDeRota()
{
    return this->tempoDeRota;
}

Turno *Veiculo::getTurno()
{
    return this->turno;
}

map<int, Endereco> Veiculo::getRota()
{
    return this->rota;
}

Data Veiculo::getHoraPosicao(Funcionario *valPassageiro)
{
    int hora; // em segundos;
    for (auto it : rota)
    {
        if (it.second.getEndereco() == valPassageiro->getEndereco().getEndereco())
        {
            hora = it.first;
        }
    }
    return this->auxiliarTempoHora(hora);
}

vector<Funcionario *> Veiculo::getPassageiros()
{
    return this->passageiros;
}
Data Veiculo::getHoraSaida(){
    return this->horaSaida;
}
Funcionario *Veiculo::getPassageiro(Endereco valEndereco)
{
    Funcionario *encontrado = new Funcionario;
    for (auto it : passageiros)
    {
        if (it->getEndereco().getEndereco() == valEndereco.getEndereco())
        {
            encontrado = it;
        }
    }
    return encontrado;
}