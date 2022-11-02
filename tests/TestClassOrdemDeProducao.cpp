#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/Empresa.h"
#include "../include/OrdemDeProducao.h"
#include "../include/Usuario.h"
#include "../third_party/doctest.h"

vector<string> permissao() {
  vector<string> permissoes;
  permissoes.push_back("OrdemDeProducao.OrdemDeProducao");
  permissoes.push_back("OrdemDeProducao.getDataOrdem");
  permissoes.push_back("OrdemDeProducao.getProduto");
  permissoes.push_back("OrdemDeProducao.getQuantidade");

  return permissoes;

}
TEST_CASE("Construtor padrão da classe OrdemDeProducao") {
  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  OrdemDeProducao *ordem = new OrdemDeProducao();
  CHECK(ordem->getQuantidade() == 0);
  CHECK(ordem->getProduto() == "");
  CHECK(ordem->getDataOrdem().getAno() == 0);
  CHECK(ordem->getDataOrdem().getMes() == 0);
  CHECK(ordem->getDataOrdem().getDia() == 0);
}

TEST_CASE("Construtor classe OrdemDeProducao") {
  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  OrdemDeProducao *ordem = new OrdemDeProducao(Data(2022, 1, 1), "Produto 1", 10);

  CHECK(ordem->getQuantidade() == 10);
  CHECK(ordem->getProduto() == "Produto 1");
  CHECK(ordem->getDataOrdem().getAno() == 2022);
  CHECK(ordem->getDataOrdem().getMes() == 1);
  CHECK(ordem->getDataOrdem().getDia() == 1);
}

TEST_CASE("getOrdem da classe OrdemDeProducao") {
  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  OrdemDeProducao *ordem = new OrdemDeProducao(Data(2022, 1, 1), "Produto 1", 10);

  ordem->getOrdem();
}