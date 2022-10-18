#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../include/Cliente.h"

using namespace std;

/* TEST_CASE("Construtor da class Cliente"){
  Cliente *c = new Cliente();
  CHECK(c->getPessoa().getNome() == "");
  CHECK(c->getPessoa().getEndereco() == "");
  CHECK(c->getPessoa().getEmail() == "");
  CHECK(c->getPessoa().getDocumento() == "");
  CHECK(c->getPessoa().getTelefone() == 0);
  CHECK(c->getTipoCliente() == "");
} */

TEST_CASE("Getter e Setter da class Cliente"){
  Cliente *c = new Cliente();
  c->setTipoCliente("Cliente 1");
  CHECK(c->getTipoCliente() == "Cliente 1");
}