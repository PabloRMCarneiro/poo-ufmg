#include "../third_party/doctest.h"
#include "../include/Pessoa.h"

using namespace std;

TEST_CASE("Construtor padrão da classe Pessoa")
{
  Pessoa *p = new Pessoa();
  CHECK(p->getNome() == "");
  CHECK(p->getEndereco() == "");
  CHECK(p->getEmail() == "");
  CHECK(p->getDocumento() == "");
  CHECK(p->getTelefone() == 0);
}

TEST_CASE("Construtor classe Pessoa")
{
  Pessoa *pessoa = new Pessoa("Joao", "Rua 1", "teste@gmail.com", "66862964062", 99999999999);

  CHECK(pessoa->getNome() == "Joao");
  CHECK(pessoa->getEndereco() == "Rua 1");
  CHECK(pessoa->getEmail() == "teste@gmail.com");
  CHECK(pessoa->getDocumento() == "66862964062");
  CHECK(pessoa->getTelefone() == 99999999999);
}

TEST_CASE("Getters e Setters da classe Pessoa")
{
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
  Pessoa *pessoa = new Pessoa();

  CHECK(pessoa->validaDocumento("66862964062") == true);
  CHECK(pessoa->validaDocumento("66862964061") == false);
}

TEST_CASE("Validação de CNPJ da classe Pessoa")
{
  Pessoa *pessoa = new Pessoa();

  CHECK(pessoa->validaDocumento("03133845000143") == true);
  CHECK(pessoa->validaDocumento("03133845000142") == false);
}