#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/Categoria.h"
#include "../include/Empresa.h"
#include "../include/Usuario.h"
#include "../third_party/doctest.h"

#include <string>
#include <vector>

using namespace std;

vector<string> permissao() {
  vector<string> permissoes;
  permissoes.push_back("Categoria.Categoria");
  permissoes.push_back("Categoria.getTipo");
  permissoes.push_back("Categoria.novaCategoria");
  permissoes.push_back("Categoria.getCategoria");

  return permissoes;
}

TEST_CASE("Construtor padrão da classe Categoria") {

  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Categoria *c = new Categoria();
  CHECK(c->getTipo() == "");
}

TEST_CASE("Construtor da classe Categoria") {
  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Categoria *c = new Categoria("Categoria 1");
  CHECK(c->getTipo() == "Categoria 1");
}

TEST_CASE("Teste de novaCategoria e getCategoria") {
  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Categoria *c = new Categoria("Categoria 1");
  Categoria *c2 = new Categoria("Categoria 2");
  Categoria *c3 = new Categoria("Categoria 3");

  Categoria::novaCategoria(c);
  Categoria::novaCategoria(c2);
  Categoria::novaCategoria(c3);

  CHECK(Categoria::getCategoria(c->getTipo())->getTipo() == "Categoria 1");
  CHECK(Categoria::getCategoria(c2->getTipo())->getTipo() == "Categoria 2");
  CHECK(Categoria::getCategoria(c3->getTipo())->getTipo() == "Categoria 3");
}