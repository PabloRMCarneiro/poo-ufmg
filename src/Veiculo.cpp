#include "../include/Veiculo.h"
#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"
#include "../include/PermissaoNegada.h"
#include <string>

Veiculo::Veiculo()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.Veiculo"))
    {
        PermissaoNegada *a = new PermissaoNegada("Veiculo", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.Veiculo";
        throw mensagem;
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
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.Veiculo"))
    {
        PermissaoNegada *a = new PermissaoNegada("Veiculo", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.Veiculo";
        throw mensagem;
    }
    else
    {
        this->setId(valId);
        this->setCapacidade(valCapacidade);
        this->setTurno(valTurno);
        this->atual = 0;
        this->tempoDeRota = 0;
        LogEscrita *a = new LogEscrita("atual", "indefinido", "0", "Veiculo");
        LogEscrita *b = new LogEscrita("tempoDeRota", "indefinido", "0", "Veiculo");
    }
}

void Veiculo::setId(int valId)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.setId"))
    {
        PermissaoNegada *a = new PermissaoNegada("setId", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.setId";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("id", "indefinido", to_string(valId), "Veiculo");
        this->id = valId;
    }
}

void Veiculo::setCapacidade(int valCapacidade)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.setCapacidade"))
    {
        PermissaoNegada *a = new PermissaoNegada("setCapacidade", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.setCapacidade";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("capacidade", "indefinido", to_string(valCapacidade), "Veiculo");
        this->capacidade = valCapacidade;
    }
}

bool Veiculo::setAtual(int valAtual)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.setAtual"))
    {
        PermissaoNegada *a = new PermissaoNegada("setAtual", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.setAtual";
        throw mensagem;
    }
    else
    {
        bool adicionar;
        if (this->getAtual() == this->getCapacidade())
            {
            adicionar = false;
            }
        else
            {
            LogEscrita *a = new LogEscrita("atual", to_string(atual), to_string(atual+valAtual), "Veiculo");
            this->atual= this->getAtual() + valAtual;
            adicionar = true;
            }
        return adicionar;
    }
    
}

void Veiculo::setTempoDeRota(int valTempoDeRota)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.setTempoDeRota"))
    {
        PermissaoNegada *a = new PermissaoNegada("setTempoDeRota", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.setTempoDeRota";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("tempoDeRota", to_string(tempoDeRota), to_string(tempoDeRota + valTempoDeRota), "Veiculo");
        this->tempoDeRota = this->tempoDeRota + valTempoDeRota;
        this->setHoraSaida();
    }
}

void Veiculo::setTurno(Turno *valTurno)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.setTurno"))
    {
        PermissaoNegada *a = new PermissaoNegada("setTurno", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.setTurno";
        throw mensagem;
    }
    else
    {
        LogEscrita *a = new LogEscrita("turno", "indefinido", valTurno->getPeriodo(), "Veiculo");
        this->turno = valTurno;
        this->setHoraSaida();
    }
}

void Veiculo::setRota(map<int, Endereco> valRota)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.setRota"))
    {
        PermissaoNegada *a = new PermissaoNegada("setRota", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.setRota";
        throw mensagem;
    }
    else
    {
        this->rota = valRota;
    }
}

void Veiculo::setPosicaoRota(Endereco valEndereco, Data valHora)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.setPosicaoRota"))
    {
        PermissaoNegada *a = new PermissaoNegada("setPosicaoRota", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.setPosicaoRota";
        throw mensagem;
    }
    else
    {
        this->rota[auxiliarTempoSegundos(valHora)] = valEndereco;
    }
}

double Veiculo::calculaTempo(double valDistancia)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.calculaTempo"))
    {
        PermissaoNegada *a = new PermissaoNegada("calculaTempo", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.calculaTempo";
        throw mensagem;
    }
    else
    {
        return (valDistancia / VELOCIDADE) * 3600;
    }
}

void Veiculo::setHoraSaida()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.setHoraSaida"))
    {
        PermissaoNegada *a = new PermissaoNegada("setHoraSaida", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.setHoraSaida";
        throw mensagem;
    }
    else
    {
        int tempoTotal, horaDoBusaoSair, horaturno, hora, minuto, segundo;
        Data valInicioTurno = this->getTurno()->getEntradaHora();
        horaturno = this->auxiliarTempoSegundos(valInicioTurno);
        horaDoBusaoSair = horaturno - 600 - this->getTempoDeRota();
        this->horaSaida = this->auxiliarTempoHora(horaDoBusaoSair);
    }
}

int Veiculo::auxiliarTempoSegundos(Data valHora)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.auxiliarTempoSegundos"))
    {
        PermissaoNegada *a = new PermissaoNegada("auxiliarTempoSegundos", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.auxiliarTempoSegundos";
        throw mensagem;
    }
    else
    {
        int tempo;
        tempo = valHora.getHora() * 3600 + valHora.getMin() * 60 + valHora.getSeg(); 
        return tempo;
    }
}

Data Veiculo::auxiliarTempoHora(int valHora)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.auxiliarTempoHora"))
    {
        PermissaoNegada *a = new PermissaoNegada("auxiliarTempoHora", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.auxiliarTempoHora";
        throw mensagem;
    }
    else
    {
        int hora, minuto, segundo;
        hora = int(valHora / 3600);
        minuto = int((valHora % 3600) / 60);
        segundo = valHora - (hora * 3600 + minuto * 60);
        return Data(0, 0, 0, hora, minuto, segundo);
    }
    
}

int Veiculo::tempoEmpresaCasa(int valTempo)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.tempoEmpresaCasa"))
    {
        PermissaoNegada *a = new PermissaoNegada("tempoEmpresaCasa", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.tempoEmpresaCasa";
        throw mensagem;
    }
    else
    {
        int tempoTotal, horaDeSaida, horaturno, hora, minuto, segundo;
        Data valLocal = this->getHoraSaida();
        horaDeSaida = valLocal.getHora() * 3600 + valLocal.getMin() * 60 + valLocal.getSeg();
        tempoTotal = horaDeSaida + valTempo;
        return tempoTotal;
    }
}

void Veiculo::calculaRota(Endereco valEndereco)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.calculaRota"))
    {
        PermissaoNegada *a = new PermissaoNegada("calculaRota", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.calculaRota";
        throw mensagem;
    }
    else
    {
        double distanciaDaEmpresa = 0.0, distanciaTotal = 0.0, distanciaAteEndereco1 = 0.0;
        int tempoAteEmpresa = 0, tempoTot = 0, horaCasa1 = 0;
        if (this->rota.empty())
        {
            distanciaDaEmpresa = valEndereco.getDistancia(Empresa::getEmpresa()->getEndereco().getX(), Empresa::getEmpresa()->getEndereco().getY()); 
            distanciaTotal = distanciaDaEmpresa * 2;             
            tempoTot = int(this->calculaTempo(distanciaTotal));  
            this->setTempoDeRota(tempoTot);
            tempoAteEmpresa = int(this->calculaTempo(distanciaDaEmpresa)); 
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
}

void Veiculo::excluiPassageiro(Funcionario *valPassageiro)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.excluiPassageiro"))
    {
        PermissaoNegada *a = new PermissaoNegada("excluiPassageiro", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.excluiPassageiro";
        throw mensagem;
    }
    else
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
}

bool Veiculo::setPassageiros(vector<Funcionario *> valPassageiros)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.setPassageiros"))
    {
        PermissaoNegada *a = new PermissaoNegada("setPassageiros", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.setPassageiros";
        throw mensagem;
    }
    else
    {
        bool adicionar = false;
        try
        {
            if (valPassageiros.size() <= this->getCapacidade())
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
}

bool Veiculo::setPassageiro(Funcionario *valPassageiro)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.setPassageiro"))
    {
        PermissaoNegada *a = new PermissaoNegada("setPassageiro", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.setPassageiro";
        throw mensagem;
    }
    else
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
}

int Veiculo::getId()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.getId"))
    {
        PermissaoNegada *a = new PermissaoNegada("getId", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.getId";
        throw mensagem;
    }
    else
    {
        LogLeitura *logLeitura = new LogLeitura("id", "Veiculo");
        return this->id;
    }
}

int Veiculo::getCapacidade()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.getCapacidade"))
    {
        PermissaoNegada *a = new PermissaoNegada("getCapacidade", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.getCapacidade";
        throw mensagem;
    }
    else
    {
        LogLeitura *logLeitura = new LogLeitura("capacidade", "Veiculo");
        return this->capacidade;
    }
}

int Veiculo::getAtual()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.getAtual"))
    {
        PermissaoNegada *a = new PermissaoNegada("getAtual", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.getAtual";
        throw mensagem;
    }
    else
    {
        LogLeitura *logLeitura = new LogLeitura("atual", "Veiculo");
        return this->atual;
    }
}

int Veiculo::getTempoDeRota()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.getTempoDeRota"))
    {
        PermissaoNegada *a = new PermissaoNegada("getTempoDeRota", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.getTempoDeRota";
        throw mensagem;
    }
    else
    {
        LogLeitura *logLeitura = new LogLeitura("tempoDeRota", "Veiculo");
        return this->tempoDeRota;
    }
}

Turno *Veiculo::getTurno()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.getTurno"))
    {
        PermissaoNegada *a = new PermissaoNegada("getTurno", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.getTurno";
        throw mensagem;
    }
    else
    {
        LogLeitura *logLeitura = new LogLeitura("turno", "Veiculo");
        return this->turno;
    }
}

map<int, Endereco> Veiculo::getRota()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.getRota"))
    {
        PermissaoNegada *a = new PermissaoNegada("getRota", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.getRota";
        throw mensagem;
    }
    else
    {
        LogLeitura *logLeitura = new LogLeitura("rota", "Veiculo");
        return this->rota;
    }
}

Data Veiculo::getHoraPosicao(Funcionario *valPassageiro)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.getHoraPosicao"))
    {
        PermissaoNegada *a = new PermissaoNegada("getHoraPosicao", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.getHoraPosicao";
        throw mensagem;
    }
    else
    {
        int hora; // em segundos;
        for (auto it : this->getRota())
        {
            if (it.second.getEndereco() == valPassageiro->getEndereco().getEndereco())
            {
                hora = it.first;
            }
        }
        return this->auxiliarTempoHora(hora);
    }
}

vector<Funcionario *> Veiculo::getPassageiros()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.getPassageiros"))
    {
        PermissaoNegada *a = new PermissaoNegada("getPassageiros", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.getPassageiros";
        throw mensagem;
    }
    else
    {
        LogLeitura *logLeitura = new LogLeitura("passageiros", "Veiculo");
        return this->passageiros;
    }
}
Data Veiculo::getHoraSaida()
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.getHoraSaida"))
    {
        PermissaoNegada *a = new PermissaoNegada("getHoraSaida", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.getHoraSaida";
        throw mensagem;
    }
    else
    {
        LogLeitura *logLeitura = new LogLeitura("horaSaida", "Veiculo");
        return this->horaSaida;
    }
}
Funcionario *Veiculo::getPassageiro(Endereco valEndereco)
{
    if (!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Veiculo.getPassageiro"))
    {
        PermissaoNegada *a = new PermissaoNegada("getPassageiro", "Veiculo");
        string mensagem = "Acesso negado a Veiculo.getPassageiro";
        throw mensagem;
    }
    else
    {
        Funcionario *encontrado = new Funcionario;
        for (auto it : this->getPassageiros())
        {
            if (it->getEndereco().getEndereco() == valEndereco.getEndereco())
            {
                encontrado = it;
            }
        }
        LogLeitura *logLeitura = new LogLeitura("encontrado", "Veiculo");
        return encontrado;
    }
    
}