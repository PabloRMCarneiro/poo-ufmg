#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/Cargo.h"
#include "../include/Empresa.h"
#include "../include/Usuario.h"
#include "../third_party/doctest.h"

using namespace std;

TEST_CASE("Construtor padrão da classe Cargo") {

  Usuario *user = new Usuario("admin", "admin");
  vector<string> permissoes;

  permissoes.push_back("Cargo.Cargo");
  permissoes.push_back("Cargo.getNome");

  user->setPermissoes(permissoes);
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Cargo *c = new Cargo();
  CHECK(c->getNome() == "");
}

TEST_CASE("Construtor classe Cargo") {

  Usuario *user = new Usuario("admin", "admin");
  vector<string> permissoes;

  permissoes.push_back("Cargo.Cargo");
  permissoes.push_back("Cargo.getNome");

  user->setPermissoes(permissoes);
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Cargo *cargo = new Cargo("Gerente");
  CHECK(cargo->getNome() == "Gerente");
}

TEST_CASE("Getters e Setters da classe Cargo") {

  Usuario *user = new Usuario("admin", "admin");
  vector<string> permissoes;

  permissoes.push_back("Cargo.Cargo");
  permissoes.push_back("Cargo.getNome");

  user->setPermissoes(permissoes);
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);
  
  Cargo *cargo = new Cargo();
  cargo->setNome("Gerente");
  CHECK(cargo->getNome() == "Gerente");

}
