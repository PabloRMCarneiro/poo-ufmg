#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/Cargo.h"
#include "../include/Empresa.h"

using namespace std;

TEST_CASE("Construtor padrão da classe Cargo")
{ 
  /*logar usuario em empresa*/
  Usuario *user = new Usuario("admin", "admin");
  Empresa *empresa = Empresa::getEmpresa();
  vector<string> funcoes;
  funcoes.push_back("Cargo.Cargo");
  
  user->setPermissoes(funcoes);
  empresa->login(user);
  
  Cargo *c = new Cargo();
  CHECK(c->getNome() == "");
}

/* TEST_CASE("Construtor classe Cargo")
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
 */