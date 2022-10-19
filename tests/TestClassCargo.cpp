#include "../third_party/doctest.h"
#include "../include/Cargo.h"

using namespace std;

TEST_CASE("Construtor padrão da classe Cargo")
{
  Cargo *c = new Cargo();
  CHECK(c->getNome() == "");
}

TEST_CASE("Construtor classe Cargo")
{
  Cargo *cargo = new Cargo("Gerente");
  CHECK(cargo->getNome() == "Gerente");
}

TEST_CASE("Getters e Setters da classe Cargo")
{
  Cargo *cargo = new Cargo();
  cargo->setNome("Gerente");
  CHECK(cargo->getNome() == "Gerente");
}

