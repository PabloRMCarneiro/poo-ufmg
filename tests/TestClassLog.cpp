/* #include "../third_party/doctest.h"

#include "../include/Log.h"
#include "../include/data.h"
#include "../include/Usuario.h"

#include <string>

using namespace std;

TEST_CASE("Construtor padrão da classe Log")
{
  Log *l = new Log();
  CHECK(l->getUsuario() == "");


  CHECK(l->getData().getDia() == 0);
  CHECK(l->getData().getMes() == 0);
  CHECK(l->getData().getAno() == 0);

  CHECK(l->getEntidade() == "");

}; */