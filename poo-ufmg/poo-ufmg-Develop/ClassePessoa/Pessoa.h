#ifndef PESSOA_H_INCLUDED
#define PESSOA_H_INCLUDED
#include <string>

using namespace std;

class Pessoa
{
private:
    string nome;
    string endereco;
    string email;
    string documento;
    int telefone;
    
public:
    Pessoa();
    Pessoa(string valNome, string valEndereco, string valEmail, string valDocumento, int valTelefone);
    virtual ~Pessoa();
    
    //Metodos get:
    string getNome();
    string getEndereco();
    string getEmail();
    string getDocumento();
    int getTelefone();
    
    //Metodos set:
    void setNome(string valNome);
    void setEndereco(string valEndereco);
    void setEmail(string valEmail);
    void setDocumento(string valDocumento);
    void setTelefone(int valTelefone);


    //Método valida documento (CPF ou CNPJ)
    bool validaDocumento(string valDocumento);
};

#endif