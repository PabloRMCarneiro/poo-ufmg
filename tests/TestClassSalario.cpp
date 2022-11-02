#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/Empresa.h"
#include "../include/Salario.h"
#include "../include/Usuario.h"
#include "../include/data.h"
#include "../third_party/doctest.h"
#include <vector>
#include <string>
#include "iostream"

using namespace std;

vector<string> permissao() {
  vector<string> permissoes;
  permissoes.push_back("Salario.Salario");
  permissoes.push_back("Salario.getValor");
  permissoes.push_back("Salario.getDissidio");
  permissoes.push_back("Salario.getRegistro");
  permissoes.push_back("Salario.atualizaRegistro");
  permissoes.push_back("Salario.promocao");

  return permissoes;

}
TEST_CASE("Constutor padrão da classe Salario") {

  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Salario salario = Salario();

  CHECK(salario.getValor() == 0.0);
  CHECK(salario.getDissidio() == 0.0);
  
  CHECK(salario.getRegistro()[0].first.getDia() == 0);
  CHECK(salario.getRegistro()[0].first.getMes() == 0);
  CHECK(salario.getRegistro()[0].first.getAno() == 0);

  CHECK(salario.getRegistro()[0].second == 0.0);
}

TEST_CASE("Constutor da classe Salario") {

  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Salario salario = Salario(1000.0);

  CHECK(salario.getValor() == 1000.0);
  CHECK(salario.getDissidio() == 0.0);

}

TEST_CASE("promocao da classe Salario"){
  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Salario salario = Salario(1000.0);
  Data data = Data(2019, 1, 1);
  Data data2 = Data(2020, 1, 1);
  Data data3 = Data(2021, 1, 1);

  salario.promocao(data, 10);
  salario.promocao(data2, 10);
  salario.promocao(data3, 10);

  CHECK(salario.getRegistro()[0].first.getDia() == 1);
  CHECK(salario.getRegistro()[0].first.getMes() == 1);
  CHECK(salario.getRegistro()[0].first.getAno() == 2019);
  CHECK(salario.getRegistro()[0].second == 1100.0);

  CHECK(salario.getRegistro()[1].first.getDia() == 1);
  CHECK(salario.getRegistro()[1].first.getMes() == 1);
  CHECK(salario.getRegistro()[1].first.getAno() == 2020);
  CHECK(salario.getRegistro()[1].second == 1210.0);

  CHECK(salario.getRegistro()[2].first.getDia() == 1);
  CHECK(salario.getRegistro()[2].first.getMes() == 1);
  CHECK(salario.getRegistro()[2].first.getAno() == 2021);
  CHECK(salario.getRegistro()[2].second == 1331.0);
}

