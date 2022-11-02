#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/Departamento.h"
#include "../include/Empresa.h"
#include "../include/Usuario.h"

using namespace std;

vector<string> permissao() {
  vector<string> permissoes;
  permissoes.push_back("Departamento.Departamento");
  permissoes.push_back("Departamento.getNome");

  return permissoes;
}

TEST_CASE("Construtor padrão da classe Departamento")
{
  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Departamento *d = new Departamento();
  CHECK(d->getNome() == "");
  
}

TEST_CASE("Construtor classe Departamento")
{
  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Departamento *departamento = new Departamento("Departamento de Informática");
  CHECK(departamento->getNome() == "Departamento de Informática");
}

TEST_CASE("Getters e Setters da classe Departamento")
{
  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Departamento *departamento = new Departamento();
  departamento->setNome("Departamento de Informática");
  CHECK(departamento->getNome() == "Departamento de Informática");
}

