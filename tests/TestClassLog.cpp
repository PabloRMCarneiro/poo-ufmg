#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/Log.h"
#include "../include/data.h"
#include "../include/Usuario.h"
#include "../include/Empresa.h"
#include "../include/Permissao.h"
#include <vector>

vector<Permissao*> permissoes() {
  vector<Permissao*> permissoes;
  permissoes.push_back(new Permissao("Empresa.getUsuario"));

  return permissoes;
}

TEST_CASE("Construtor padrão da classe Log") 
{
  Usuario *user = new Usuario("admin@gmail.com", "admin1234");
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Log *log = new Log();
  CHECK(log->getEntidade() == "");
  CHECK(log->getData().getDia() == 0);
  CHECK(log->getUsuario() == user);
  CHECK(log->getUsuario() == user);

  SUBCASE("Construtor com parâmetros da classe log") {

    Data data(1, 1, 1);

    Log *log = new Log(user, data, "entidade");
    CHECK(log->getData().getDia() == 1);
    CHECK(log->getEntidade() == "entidade");
    CHECK(log->getUsuario() == user);
  }
}

TEST_CASE("Getters e setters da classe log") 
{
  Usuario *user2 = new Usuario("usuario@gmail.com", "usuario123");
  Data data(1, 1, 1);
  Log *log = new Log(user2, data, "entidade");
  CHECK(log->getData().getMes() == 1);
  CHECK(log->getEntidade() == "entidade");

  Usuario *user3 = new Usuario("usuario3@hotmail.com", "usuario1234");

  log->setDataAcesso(Data(2, 2, 2));
  log->setEntidade("entidade2");
  log->setUsuario(user3);

  CHECK(log->getData().getMes() == 2);
  CHECK(log->getEntidade() == "entidade2");
  CHECK(log->getUsuario() == user3);
}

