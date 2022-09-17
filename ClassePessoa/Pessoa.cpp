#include "Pessoa.h"
#include <string>

using namespace std;

bool validaCPF(string Cpf)
{   
    if (Cpf == "00000000000" || 
        Cpf == "11111111111" || 
        Cpf == "22222222222" || 
        Cpf == "33333333333" || 
        Cpf == "44444444444" || 
        Cpf == "55555555555" || 
        Cpf == "66666666666" || 
        Cpf == "77777777777" || 
        Cpf == "88888888888" || 
        Cpf == "99999999999")
        return false;
      
    int i, j, digito1, digito2, resto, soma;
    string nDigResult;
    soma = 0;
    digito1 = 0;
    digito2 = 0;
    resto = 0;
    for (i=1; i<=9; i++)
        soma = soma + (stoi(Cpf.substr(i-1,1)) * (11 - i));
    resto = (soma * 10) % 11;
    if ((resto == 10) || (resto == 11))
        resto = 0;
    digito1 = resto;
    soma = 0;
    for (i = 1; i <= 10; i++)
        soma = soma + (stoi(Cpf.substr(i-1,1)) * (12 - i));
    resto = (soma * 10) % 11;
    if ((resto == 10) || (resto == 11))
        resto = 0;
    digito2 = resto;
    nDigResult = Cpf.substr(9,2);
    if ((nDigResult == to_string(digito1) + to_string(digito2)))
        return true;
    else
        return false;
}


bool validaCNPJ(string Cnpj)
{
    if (Cnpj == "00000000000000" || 
        Cnpj == "11111111111111" || 
        Cnpj == "22222222222222" || 
        Cnpj == "33333333333333" || 
        Cnpj == "44444444444444" || 
        Cnpj == "55555555555555" || 
        Cnpj == "66666666666666" || 
        Cnpj == "77777777777777" || 
        Cnpj == "88888888888888" || 
        Cnpj == "99999999999999")
        return false;

    int tamanho = Cnpj.length() - 2;
    string numeros = Cnpj.substr(0,tamanho);
    string digitos = Cnpj.substr(tamanho);
    int soma = 0;
    int pos = tamanho - 7;

    for (int i = tamanho; i >= 1; i--) {
        soma += stoi(numeros.substr(tamanho - i,1)) * pos--;
        if (pos < 2)
            pos = 9;
    }

    int resultado = soma % 11 < 2 ? 0 : 11 - soma % 11;
    if (resultado != stoi(digitos.substr(0,1)))
        return false;
  
    tamanho = tamanho + 1; 
    numeros = Cnpj.substr(0,tamanho);
    soma = 0;
    pos = tamanho - 7;
    for (int i = tamanho; i >= 1; i--) {
        soma += stoi(numeros.substr(tamanho - i,1)) * pos--;
        if (pos < 2)
            pos = 9;
    }

    resultado = soma % 11 < 2 ? 0 : 11 - soma % 11;
    if (resultado != stoi(digitos.substr(1,1)))
        return false;
    return true;
    
}

Pessoa::Pessoa()
{
  this->nome = "";
  this->endereco = "";
  this->email = "";
  this->documento = "";
  this->telefone = 0;
}

Pessoa::Pessoa(string Nome, string Endereco, string Email, string Documento, int Telefone)
{
  this->nome = Nome;
  this->endereco = Endereco;
  this->email = Email;
  this->documento = Documento;
  this->telefone = Telefone;
}

Pessoa::~Pessoa() {}

// Metodos get:

string Pessoa::getNome()
{
  return this->nome;
}

string Pessoa::getEndereco()
{
  return this->endereco;
}

string Pessoa::getEmail()
{
  return this->email;
}

string Pessoa::getDocumento()
{
  return this->documento;
}

int Pessoa::getTelefone()
{
  return this->telefone;
}

// Metodos set:

void Pessoa::setNome(string Nome)
{
  this->nome = Nome;
}

void Pessoa::setEndereco(string Endereco)
{
  this->endereco = Endereco;
}

void Pessoa::setEmail(string Email)
{
  this->email = Email;
}

void Pessoa::setDocumento(string Documento)
{
  this->documento = Documento;
}

void Pessoa::setTelefone(int Telefone)
{
  this->telefone = Telefone;
}

// Método valida documento (CPF ou CNPJ)

bool Pessoa::validaDocumento(string Documento)
{
  if(Documento.length() == 11)
  {
    return validaCPF(Documento);
  }
  if(Documento.length() == 14)
  {
    return validaCNPJ(Documento);
  }
  else
    return false;
}