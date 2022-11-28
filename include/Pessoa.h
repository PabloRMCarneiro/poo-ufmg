#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED
#include <string>
#include "Endereco.h"
using namespace std;

class Pessoa{
    private:
        string nome;
        Endereco endereco;
        string email;
        string documento;
        long int telefone;
    public:
        Pessoa();
        Pessoa(string valNome, Endereco valEndereco, string valEmail, string valDocumento, long int valTelefone);
        string getNome();
        Endereco getEndereco();
        string getEmail();
        string getDocumento();
        long int getTelefone();
        void setNome(string valNome);
        void setEndereco(Endereco valEndereco);
        void setEmail(string valEmail);
        void setDocumento(string valDocumento);
        void setTelefone(long int valTelefone);
        bool validaDocumento(string valDocumento);
};

#endif