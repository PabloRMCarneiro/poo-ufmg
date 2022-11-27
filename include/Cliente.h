#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "Pessoa.h"

class Cliente:public Pessoa{
    private:
        string tipoCliente;
    public:
        Cliente();
        Cliente(string valNome, Endereco valEndereco, string valEmail, string valDocumento, long int valTelefone);
        void setTipoCliente(string tc);
        string getTipoCliente();
};

#endif 