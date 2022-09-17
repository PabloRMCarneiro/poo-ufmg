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
    Pessoa(string Nome, string Endereco, string Email, string Documento, int Telefone);
    virtual ~Pessoa();
    
    //Metodos get:
    string getNome();
    string getEndereco();
    string getEmail();
    string getDocumento();
    int getTelefone();
    
    //Metodos set:
    void setNome(string Nome);
    void setEndereco(string Endereco);
    void setEmail(string Email);
    void setDocumento(string Documento);
    void setTelefone(int Telefone);


    //Método valida documento (CPF ou CNPJ)
    bool validaDocumento(string valDocumento);
};

#endif