#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED
#include <string>
using namespace std;

class Pessoa{
    private:
        string nome;
        string endereco;
        string email;
        string documento;
        long int telefone;
    public:
        Pessoa();
        Pessoa(string valNome, string valEndereco, string valEmail, string valDocumento, long int valTelefone);
        virtual ~Pessoa();
        string getNome();
        string getEndereco();
        string getEmail();
        string getDocumento();
        long int getTelefone();
        void setNome(string valNome);
        void setEndereco(string valEndereco);
        void setEmail(string valEmail);
        void setDocumento(string valDocumento);
        void setTelefone(long int valTelefone);
        bool validaDocumento(string valDocumento);
};

#endif