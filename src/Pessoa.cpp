#include "../include/Pessoa.h"
#include "../include/Empresa.h"
#include <iostream>
#include <string>

using namespace std;
/**
 * It validates a CPF number.
 *
 * @param Cpf The CPF number to be validated.
 *
 * @return A boolean value.
 */
bool validaCPF(string Cpf) {
  if (Cpf == "00000000000" || Cpf == "11111111111" || Cpf == "22222222222" ||
      Cpf == "33333333333" || Cpf == "44444444444" || Cpf == "55555555555" ||
      Cpf == "66666666666" || Cpf == "77777777777" || Cpf == "88888888888" ||
      Cpf == "99999999999")
    return false;

  int i, digito1, digito2, resto, soma;
  string nDigResult;
  soma = 0;
  digito1 = 0;
  digito2 = 0;
  resto = 0;
  for (i = 1; i <= 9; i++)
    soma = soma + (stoi(Cpf.substr(i - 1, 1)) * (11 - i));
  resto = (soma * 10) % 11;
  if ((resto == 10) || (resto == 11))
    resto = 0;
  digito1 = resto;
  soma = 0;
  for (i = 1; i <= 10; i++)
    soma = soma + (stoi(Cpf.substr(i - 1, 1)) * (12 - i));
  resto = (soma * 10) % 11;
  if ((resto == 10) || (resto == 11))
    resto = 0;
  digito2 = resto;
  nDigResult = Cpf.substr(9, 2);
  if ((nDigResult == to_string(digito1) + to_string(digito2)))
    return true;
  else
    return false;
}
/**
 * It validates a CNPJ number.
 *
 * @param Cnpj The CNPJ number to be validated.
 *
 * @return A boolean value.
 */
bool validaCNPJ(string Cnpj) {
  if (Cnpj == "00000000000000" || Cnpj == "11111111111111" ||
      Cnpj == "22222222222222" || Cnpj == "33333333333333" ||
      Cnpj == "44444444444444" || Cnpj == "55555555555555" ||
      Cnpj == "66666666666666" || Cnpj == "77777777777777" ||
      Cnpj == "88888888888888" || Cnpj == "99999999999999")
    return false;

  int tamanho = Cnpj.length() - 2;
  string numeros = Cnpj.substr(0, tamanho);
  string digitos = Cnpj.substr(tamanho);
  int soma = 0;
  int pos = tamanho - 7;

  for (int i = tamanho; i >= 1; i--) {
    soma += stoi(numeros.substr(tamanho - i, 1)) * pos--;
    if (pos < 2)
      pos = 9;
  }

  int resultado = soma % 11 < 2 ? 0 : 11 - soma % 11;
  if (resultado != stoi(digitos.substr(0, 1)))
    return false;

  tamanho = tamanho + 1;
  numeros = Cnpj.substr(0, tamanho);
  soma = 0;
  pos = tamanho - 7;
  for (int i = tamanho; i >= 1; i--) {
    soma += stoi(numeros.substr(tamanho - i, 1)) * pos--;
    if (pos < 2)
      pos = 9;
  }

  resultado = soma % 11 < 2 ? 0 : 11 - soma % 11;
  if (resultado != stoi(digitos.substr(1, 1)))
    return false;
  return true;
}
/**
 * Pessoa::Pessoa()
 */
Pessoa::Pessoa() {
  if (!Empresa::getEmpresa()->getAcesso("Pessoa.Pessoa")) {
    throw "Acesso negado Pessoa.Pessoa";
  } else {
    this->nome = "";
    this->endereco = "";
    this->email = "";
    this->documento = "";
    this->telefone = 0;
  }
}
/**
 * The constructor for the Pessoa class
 *
 * @param valNome
 * @param valEndereco Rua dos Bobos, 0
 * @param valEmail
 * @param valDocumento CPF
 * @param valTelefone
 */
Pessoa::Pessoa(string valNome, string valEndereco, string valEmail,
               string valDocumento, long int valTelefone) {
  if (!Empresa::getEmpresa()->getAcesso("Pessoa.Pessoa")) {
    throw "Acesso negado Pessoa.Pessoa";
  } else {
    this->nome = valNome;
    this->endereco = valEndereco;
    this->email = valEmail;
    this->telefone = valTelefone;
    this->setDocumento(valDocumento);
  }
}
/**
 * The destructor is called when the object is destroyed
 */
Pessoa::~Pessoa() {}
/**
 * It returns the name of the person.
 *
 * @return The name of the person.
 */
string Pessoa::getNome() {
  if (!Empresa::getEmpresa()->getAcesso("Pessoa.getNome")) {
    throw "Acesso negado - getNome";
  } else
    return this->nome;
}

/* Returning the address of the person. */
string Pessoa::getEndereco() {
  if (!Empresa::getEmpresa()->getAcesso("Pessoa.getEndereco")) {
    throw "Acesso negado - getEndereco";
  } else
    return this->endereco;
}
/**
 * It returns the email of the person.
 *
 * @return The email of the person.
 */
string Pessoa::getEmail() {
  if (!Empresa::getEmpresa()->getAcesso("Pessoa.getEmail")) {
    throw "Acesso negado - getEmail";
  } else
    return this->email;
}
/**
 * It returns the documento variable.
 *
 * @return The documento attribute of the object.
 */
string Pessoa::getDocumento() {
  if (!Empresa::getEmpresa()->getAcesso("Pessoa.getDocumento")) {
    throw "Acesso negado - getDocumento";
  } else
    return this->documento;
}
/**
 * It returns the value of the private variable telefone.
 *
 * @return The value of the variable telefone.
 */
long int Pessoa::getTelefone() {
  if (!Empresa::getEmpresa()->getAcesso("Pessoa.getTelefone")) {
    throw "Acesso negado - getTelefone";
  } else
    return this->telefone;
}
/**
 * This function sets the value of the private variable nome to the value of the
 * parameter valNome
 *
 * @param valNome The value of the name that will be assigned to the object.
 */
void Pessoa::setNome(string valNome) { this->nome = valNome; }
/**
 * It sets the value of the endereco variable.
 *
 * @param valEndereco The value of the address
 */
void Pessoa::setEndereco(string valEndereco) { this->endereco = valEndereco; }
/**
 * It sets the value of the email variable.
 *
 * @param valEmail The value of the email
 */
void Pessoa::setEmail(string valEmail) { this->email = valEmail; }
/**
 * It sets the value of the documento variable.
 *
 * @param valDocumento The value of the documento
 */
void Pessoa::setDocumento(string valDocumento) {
  if (this->validaDocumento(valDocumento)) {
    this->documento = valDocumento;
  } else
    cout << "Documento inválido." << endl;
}
/**
 * It sets the value of the telefone variable.
 *
 * @param valTelefone The value of the telefone
 */
void Pessoa::setTelefone(long int valTelefone) { this->telefone = valTelefone; }
/**
 * It prints the attributes of the object.
 */
bool Pessoa::validaDocumento(string valDocumento) {
  if (valDocumento.length() == 11) {
    return validaCPF(valDocumento);
  }
  if (valDocumento.length() == 14) {
    return validaCNPJ(valDocumento);
  } else
    return false;
}