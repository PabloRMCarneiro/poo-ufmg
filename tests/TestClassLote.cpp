#include "../third_party/doctest.h"
#include <string>
#include "../include/Lote.h"
#include "../include/data.h"

using namespace std;

TEST_CASE("Construtor padrão da classe Lote")
{
  Lote *lote = new Lote();

  CHECK(lote->getNumLote() == 0);
  CHECK(lote->getQuantidadeProduzida() == 0);
  CHECK(lote->getQuantidadeAtual() == 0);
  CHECK(lote->getProduto() == "");
  
  CHECK(lote->getDataProd().getDia() == 0);
  CHECK(lote->getDataProd().getMes() == 0);
  CHECK(lote->getDataProd().getAno() == 0);

}

TEST_CASE("Construtor da classe Lote")
{
  Lote *lote = new Lote();

  Data *data = new Data(1, 1, 2020);
  int numLote = 1;
  int quantidadeProduzida = 10;
  string produto = "Produto";

  lote->setDataProd(*data);
  lote->setNumLote(numLote);
  lote->setQuantidadeProduzida(quantidadeProduzida);
  lote->setQuantidadeAtual(quantidadeProduzida);
  lote->setProduto(produto);

  CHECK(lote->getNumLote() == numLote);
  CHECK(lote->getQuantidadeProduzida() == quantidadeProduzida);
  CHECK(lote->getQuantidadeAtual() == quantidadeProduzida);
  CHECK(lote->getProduto() == produto);

}

TEST_CASE("Método vende da classe Lote")
{
  Lote *lote = new Lote();

  Data *data = new Data(1, 1, 2020);
  int numLote = 1;
  int quantidadeProduzida = 10;
  string produto = "Produto";

  lote->setDataProd(*data);
  lote->setNumLote(numLote);
  lote->setQuantidadeProduzida(quantidadeProduzida);
  lote->setQuantidadeAtual(quantidadeProduzida);
  lote->setProduto(produto);

  int quantidadeVendida = 5;

  lote->vende(quantidadeVendida);

  CHECK(lote->getQuantidadeAtual() == quantidadeProduzida - quantidadeVendida);

}