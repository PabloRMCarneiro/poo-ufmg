#include "../include/Pessoa.h"
#include "../include/UsuarioLogado.h"
#include "../include/PermissaoNegada.h"
#include "../include/Empresa.h"
#include <iostream>
#include <string>

using namespace std;

bool validaCPF(string Cpf)
{
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

bool validaCNPJ(string Cnpj)
{
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

  for (int i = tamanho; i >= 1; i--)
  {
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
  for (int i = tamanho; i >= 1; i--)
  {
    soma += stoi(numeros.substr(tamanho - i, 1)) * pos--;
    if (pos < 2)
      pos = 9;
  }

  resultado = soma % 11 < 2 ? 0 : 11 - soma % 11;
  if (resultado != stoi(digitos.substr(1, 1)))
    return false;
  return true;
}

Pessoa::Pessoa()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Pessoa.Pessoa"))
  {
        PermissaoNegada *a = new PermissaoNegada("Pessoa", "Pessoa");
        string mensagem = "Acesso negado a Pessoa.Pessoa";
        throw mensagem;
  }
  else
  {
    this->nome = "";
    this->endereco = Endereco();
    this->email = "";
    this->documento = "";
    this->telefone = 0;
  }
}

Pessoa::Pessoa(string valNome, Endereco valEndereco, string valEmail,
               string valDocumento, long int valTelefone)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Pessoa.Pessoa"))
  {
        PermissaoNegada *a = new PermissaoNegada("Pessoa", "Pessoa");
        string mensagem = "Acesso negado a Pessoa.Pessoa";
        throw mensagem;
  }  
  else
  {
    this->setNome(valNome);
    this->endereco = valEndereco;
    this->email = valEmail;
    this->telefone = valTelefone;
    LogEscrita *a = new LogEscrita("endereco", "indefinido", valEndereco.getEndereco(), "Pessoa");
    LogEscrita *b = new LogEscrita("email", "indefinido", valEmail, "Pessoa");
    LogEscrita *c = new LogEscrita("telefone", "indefinido", to_string(valTelefone), "Pessoa");
    this->setDocumento(valDocumento);
  }
}

string Pessoa::getNome()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Pessoa.getNome"))
  {
        PermissaoNegada *a = new PermissaoNegada("getNome", "Pessoa");
        string mensagem = "Acesso negado a Pessoa.getNome";
        throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("nome", "Pessoa");
    return this->nome;
  }
}

Endereco Pessoa::getEndereco()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Pessoa.getEndereco"))
  {
        PermissaoNegada *a = new PermissaoNegada("getEndereco", "Pessoa");
        string mensagem = "Acesso negado a Pessoa.getEndereco";
        throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("endereco", "Pessoa");
    return this->endereco;
  }
}

string Pessoa::getEmail()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Pessoa.getEmail"))
  {
        PermissaoNegada *a = new PermissaoNegada("getEmail", "Pessoa");
        string mensagem = "Acesso negado a Pessoa.getEmail";
        throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("email", "Pessoa");
    return this->email;
  }
}

string Pessoa::getDocumento()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Pessoa.getDocumento"))
  {
        PermissaoNegada *a = new PermissaoNegada("getDocumento", "Pessoa");
        string mensagem = "Acesso negado a Pessoa.getDocumento";
        throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("documento", "Pessoa");
    return this->documento;
  }
}

long int Pessoa::getTelefone()
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Pessoa.getTelefone"))
  {
        PermissaoNegada *a = new PermissaoNegada("getTelefone", "Pessoa");
        string mensagem = "Acesso negado a Pessoa.getTelefone";
        throw mensagem;
  }
  else
  {
    LogLeitura *logLeitura = new LogLeitura("telefone", "Pessoa");
    return this->telefone;
  }
}

void Pessoa::setNome(string valNome)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Pessoa.setNome"))
  {
        PermissaoNegada *a = new PermissaoNegada("setNome", "Pessoa");
        string mensagem = "Acesso negado a Pessoa.setNome";
        throw mensagem;
  }
  else
  {
    LogEscrita *c = new LogEscrita("nome", "indefinido", valNome, "Pessoa");
    this->nome = valNome;
  }
}

void Pessoa::setEndereco(Endereco valEndereco)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Pessoa.setEndereco"))
  {
        PermissaoNegada *a = new PermissaoNegada("setEndereco", "Pessoa");
        string mensagem = "Acesso negado a Pessoa.setEndereco";
        throw mensagem;
  }
  else
  {
    LogEscrita *c = new LogEscrita("endereco", endereco.getEndereco(), valEndereco.getEndereco(), "Pessoa");
    this->endereco = valEndereco;
  }
}

void Pessoa::setEmail(string valEmail)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Pessoa.setEmail"))
  {
        PermissaoNegada *a = new PermissaoNegada("setEmail", "Pessoa");
        string mensagem = "Acesso negado a Pessoa.setEmail";
        throw mensagem;
  }
  else
  {
    LogEscrita *c = new LogEscrita("email", "indefinido", valEmail, "Pessoa");
    this->email = valEmail;
  }
}

void Pessoa::setDocumento(string valDocumento)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Pessoa.setDocumento"))
  {
        PermissaoNegada *a = new PermissaoNegada("setDocumento", "Pessoa");
        string mensagem = "Acesso negado a Pessoa.setDocumento";
        throw mensagem;
  }
  else
  {
      if (this->validaDocumento(valDocumento))
      {
        this->documento = valDocumento;
        LogEscrita *c = new LogEscrita("documento", "indefinido", valDocumento, "Pessoa");
      }
      else
        cout << "Documento inválido." << endl;
  }
  
}

void Pessoa::setTelefone(long int valTelefone)
{
  if(!UsuarioLogado::getUsuarioLogado()->getUsuario()->getPermissoes("Pessoa.setTelefone"))
  {
        PermissaoNegada *a = new PermissaoNegada("setTelefone", "Pessoa");
        string mensagem = "Acesso negado a Pessoa.setTelefone";
        throw mensagem;
  }
  else
  {
    LogEscrita *c = new LogEscrita("telefone", to_string(telefone), to_string(valTelefone), "Pessoa");
    this->telefone = valTelefone;
  }
}

bool Pessoa::validaDocumento(string valDocumento)
{
  if (valDocumento.length() == 11)
  {
    return validaCPF(valDocumento);
  }
  if (valDocumento.length() == 14)
  {
    return validaCNPJ(valDocumento);
  }
  else
    return false;
}