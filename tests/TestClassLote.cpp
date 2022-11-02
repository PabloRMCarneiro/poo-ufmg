#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "iostream"
#include "../third_party/doctest.h"
#include <string>
#include "../include/Lote.h"
#include "../include/data.h"
#include "../include/Empresa.h"
#include "../include/Usuario.h"

vector<string> permissao() {
  vector<string> permissoes;
  permissoes.push_back("Lote.Lote");
  permissoes.push_back("Lote.getNumLote");
  permissoes.push_back("Lote.getQuantidadeProduzida");
  permissoes.push_back("Lote.getQuantidadeAtual");
  permissoes.push_back("Lote.getProduto");
  permissoes.push_back("Lote.getDataProd");
  permissoes.push_back("Lote.imprimeRegistro");
  permissoes.push_back("Lote.vende");

  return permissoes;
}

using namespace std;

TEST_CASE("Construtor padrão da classe Lote") {

  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Lote *l = new Lote();
  CHECK(l->getNumLote() == 0);
  CHECK(l->getQuantidadeProduzida() == 0);
  CHECK(l->getQuantidadeAtual() == 0);
  CHECK(l->getProduto() == "");
  CHECK(l->getDataProd().getDia() == 0);
  CHECK(l->getDataProd().getMes() == 0);
  CHECK(l->getDataProd().getAno() == 0);
}

TEST_CASE("Construtor classe Lote") {

  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Data dataProd(2020, 1, 1);
  Lote *lote = new Lote(dataProd, 1, 100, "Produto");
  CHECK(lote->getNumLote() == 1);
  CHECK(lote->getQuantidadeProduzida() == 100);
  CHECK(lote->getQuantidadeAtual() == 100);
  CHECK(lote->getProduto() == "Produto");
  CHECK(lote->getDataProd().getDia() == 1);
  CHECK(lote->getDataProd().getMes() == 1);
  CHECK(lote->getDataProd().getAno() == 2020);
}

TEST_CASE("ImprimeRegistro da class Lote"){
  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Data dataProd(2020, 1, 1);
  Lote *lote = new Lote(dataProd, 1, 100, "Produto");

  lote->imprimeRegistro();
}

TEST_CASE("Vende da class Lote"){
  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Data dataProd(2020, 1, 1);
  Lote *lote = new Lote(dataProd, 1, 100, "Produto");

  CHECK(lote->vende(50) == 50);
  CHECK(lote->getQuantidadeAtual() == 50);
}