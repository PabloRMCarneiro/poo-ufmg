#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Departamento.h"

using namespace std;

TEST_CASE("Construtor padrão da classe Departamento")
{
  Departamento *d = new Departamento();
  CHECK(d->getNome() == "");
}

TEST_CASE("Construtor classe Departamento")
{
  Departamento *departamento = new Departamento("Departamento de Informática");
  CHECK(departamento->getNome() == "Departamento de Informática");
}

TEST_CASE("Getters e Setters da classe Departamento")
{
  Departamento *departamento = new Departamento();
  departamento->setNome("Departamento de Informática");
  CHECK(departamento->getNome() == "Departamento de Informática");
}

