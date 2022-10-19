/* #include "../third_party/doctest.h"
#include "../include/Salario.h"
#include "../include/data.h"

using namespace std;

TEST_CASE("Construtor padrão da classe Salario")
{
  Salario *s = new Salario();
  CHECK(s->getValor() == 0.0);
}

TEST_CASE("Construtor classe Salario")
{
  Salario *salario = new Salario(1000);
  CHECK(salario->getValor() == 1000.0);
}

TEST_CASE("Getters e Setters da classe Salario")
{
  Salario *salario = new Salario();
  salario->setValor(1000);
  salario->setDissidio(0.1);

  CHECK(salario->getValor() == 1000.0);
  CHECK(salario->getDissidio() == 0.1);
}

TEST_CASE("Promoção da classe Salario")
{
  Salario *salario = new Salario(1000);
  salario->promocao(0.1);
  CHECK(salario->getValor() == 1100);
}

TEST_CASE("Reajuste da classe Salario")
{
  Salario *salario = new Salario(1000);
  salario->reajuste(0.1);
  CHECK(salario->getValor() == 1100);
}

TEST_CASE("Registro da classe Salario")
{
  Salario *salario = new Salario(1000);
  Data *data = new Data(1, 1, 2020);
  salario->alteraRegistro(*data, 0.1);

  CHECK(salario->getRegistro()[0].first.getDia() == 1);
  CHECK(salario->getRegistro()[0].first.getMes() == 1);
  CHECK(salario->getRegistro()[0].first.getAno() == 2020);
  CHECK(salario->getRegistro()[0].second == 0.1);

}
 */