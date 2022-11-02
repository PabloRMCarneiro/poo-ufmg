#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/Pessoa.h"
#include "../include/Empresa.h"
#include "../include/Usuario.h"

using namespace std;

vector<string> permissao() {
  vector<string> permissoes;
  permissoes.push_back("Pessoa.Pessoa");
  permissoes.push_back("Pessoa.getNome");
  permissoes.push_back("Pessoa.getDocumento");
  permissoes.push_back("Pessoa.getTelefone");
  permissoes.push_back("Pessoa.getEndereco");
  permissoes.push_back("Pessoa.getEmail");

  return permissoes;
}

TEST_CASE("Construtor padrão da classe Pessoa")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Pessoa *p = new Pessoa();
  CHECK(p->getNome() == "");
  CHECK(p->getEndereco() == "");
  CHECK(p->getEmail() == "");
  CHECK(p->getDocumento() == "");
  CHECK(p->getTelefone() == 0);
}

TEST_CASE("Construtor classe Pessoa")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Pessoa *pessoa = new Pessoa("Joao", "Rua 1", "teste@gmail.com", "66862964062", 99999999999);

  CHECK(pessoa->getNome() == "Joao");
  CHECK(pessoa->getEndereco() == "Rua 1");
  CHECK(pessoa->getEmail() == "teste@gmail.com");
  CHECK(pessoa->getDocumento() == "66862964062");
  CHECK(pessoa->getTelefone() == 99999999999);
}

TEST_CASE("Getters e Setters da classe Pessoa")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Pessoa *pessoa = new Pessoa();

  pessoa->setNome("Joao");
  pessoa->setEndereco("Rua 1");
  pessoa->setEmail("teste@gmail.com");
  pessoa->setDocumento("66862964062");
  pessoa->setTelefone(99999999999);

  CHECK(pessoa->getNome() == "Joao");
  CHECK(pessoa->getEndereco() == "Rua 1");
  CHECK(pessoa->getEmail() == "teste@gmail.com");
  CHECK(pessoa->getDocumento() == "66862964062");
  CHECK(pessoa->getTelefone() == 99999999999);
}

TEST_CASE("Validação de CPF da classe Pessoa")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Pessoa *pessoa = new Pessoa();

  CHECK(pessoa->validaDocumento("66862964062") == true);
  CHECK(pessoa->validaDocumento("66862964061") == false);
}

TEST_CASE("Validação de CNPJ da classe Pessoa")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Pessoa *pessoa = new Pessoa();

  CHECK(pessoa->validaDocumento("03133845000143") == true);
  CHECK(pessoa->validaDocumento("03133845000142") == false);
}