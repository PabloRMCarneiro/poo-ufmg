#include "../third_party/doctest.h"
#include "../include/data.h"

using namespace std;

TEST_CASE("Construtor padrão da classe Data")
{
  Data *d = new Data();
  CHECK(d->getDia() == 0);
  CHECK(d->getMes() == 0);
  CHECK(d->getAno() == 0);
}

TEST_CASE("Construtor classe Data")
{
  Data *data = new Data(2019,1,1);
  CHECK(data->getDia() == 1);
  CHECK(data->getMes() == 1);
  CHECK(data->getAno() == 2019);
}

TEST_CASE("Getters e Setters da classe Data")
{
  Data *data = new Data();
  data->setDia(1);
  data->setMes(1);
  data->setAno(2019);
  CHECK(data->getDia() == 1);
  CHECK(data->getMes() == 1);
  CHECK(data->getAno() == 2019);
}

/* TEST_CASE("Operadores da classe Data")
{
  Data *data1 = new Data(1, 1, 2019);
  Data *data2 = new Data(1, 1, 2019);
  Data *data3 = new Data(1, 1, 2020);
  Data *data4 = new Data(1, 2, 2019);
  Data *data5 = new Data(2, 1, 2019);
  Data *data6 = new Data(1, 1, 2018);
  CHECK(*data1 == *data2);
  CHECK(*data1 < *data3);
  CHECK(*data1 < *data4);
  CHECK(*data1 < *data5);
  CHECK(*data1 < *data6);
}
 */
