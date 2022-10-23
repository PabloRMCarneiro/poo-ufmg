#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/Log.h"
#include "../include/data.h"
#include "../include/Usuario.h"

TEST_CASE("Construtor padrão da classe Log") 
{
  Log *log = new Log();
  CHECK(log->getEntidade() == "");
  CHECK(log->getData().getDia() == 0);
  CHECK(log->getUsuario() == nullptr);

  SUBCASE("Construtor com parâmetros da classe log") {
    Usuario *usuario = new Usuario("usuario@gmail.com", "usuario123");
    Data data(1, 1, 1);
    Log *log = new Log(usuario, data, "entidade");

    CHECK(log->getData().getDia() == 1);
    CHECK(log->getEntidade() == "entidade");
    CHECK(log->getUsuario() == usuario);

  }
}

TEST_CASE("Getters e setters da classe log") 
{
  Usuario *usuario = new Usuario("usuario@gmail.com", "usuario123");
  Data data(1, 1, 1);
  Log *log = new Log(usuario, data, "entidade");
  CHECK(log->getData().getMes() == 1);
  CHECK(log->getEntidade() == "entidade");

  Usuario *usuario2 = new Usuario("usuario2@hotmail.com", "usuario1234");

  log->setDataAcesso(Data(2, 2, 2));
  log->setEntidade("entidade2");
  log->setUsuario(usuario2);

  CHECK(log->getData().getMes() == 2);
  CHECK(log->getEntidade() == "entidade2");
  CHECK(log->getUsuario() == usuario2);
  
}

