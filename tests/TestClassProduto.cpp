#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../include/Categoria.h"
#include "../include/Empresa.h"
#include "../include/Lote.h"
#include "../include/OrdemDeProducao.h"
#include "../include/Produto.h"
#include "../include/Usuario.h"
#include "../third_party/doctest.h"

#include <string>
#include <vector>

using namespace std;

vector<string> permissao() {
  vector<string> permissoes;
  permissoes.push_back("Produto.Produto");
  permissoes.push_back("Produto.getNome");
  permissoes.push_back("Produto.getCodigo");
  permissoes.push_back("Produto.getValorDeVenda");
  permissoes.push_back("Produto.getTamanhoDoLoteMinimo");
  permissoes.push_back("Produto.getEstoqueMinimo");
  permissoes.push_back("Produto.getQtdEstoque");
  permissoes.push_back("Produto.getCategoria");
  permissoes.push_back("Produto.novoProduto");
  permissoes.push_back("Produto.registraLote");
  permissoes.push_back("Produto.getLote");

  permissoes.push_back("Categoria.Categoria");
  permissoes.push_back("Categoria.getCategoria");
  permissoes.push_back("Categoria.getTipo");
  permissoes.push_back("Categoria.novaCategoria");

  permissoes.push_back("Lote.Lote");
  permissoes.push_back("Lote.getProduto");
  permissoes.push_back("Lote.getNumLote");
  permissoes.push_back("Lote.getDataProd");
  permissoes.push_back("Lote.getQuantidadeAtual");
  permissoes.push_back("Lote.getQuantidadeProduzida");

  return permissoes;
}

TEST_CASE("Constutor padrão da classe Produto") {

  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Produto produto = Produto();

  CHECK(produto.getNome() == "");
  CHECK(produto.getCodigo() == 0);
  CHECK(produto.getValorDeVenda() == 0);
  CHECK(produto.getTamanhoDoLoteMinimo() == 0);
  CHECK(produto.getEstoqueMinimo() == 0);
  CHECK(produto.getQtdEstoque() == 0);
  CHECK(produto.getCategoria() == "");
}

TEST_CASE("Contrutor da classe Produto") {
  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Produto produto = Produto("Produto", 1221, 10.0, 10, 10, 15, "Categoria");

  CHECK(produto.getNome() == "Produto");
  CHECK(produto.getCodigo() == 1221);
  CHECK(produto.getValorDeVenda() == 10.0);
  CHECK(produto.getTamanhoDoLoteMinimo() == 10);
  CHECK(produto.getEstoqueMinimo() == 10);
  CHECK(produto.getQtdEstoque() == 15);
  CHECK(produto.getCategoria() == "Categoria");
}

TEST_CASE("registraLote da classe Produto"){
  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Produto *produto = new Produto("Cerveja", 123, 3.50, 20, 10, 15, "Bebida");


  produto->registraLote(163542, Data(2022, 10, 10));

  CHECK(produto->getLote(163542)->getNumLote() == 163542);
  CHECK(produto->getLote(163542)->getProduto() == "Cerveja");

  CHECK(produto->getLote(163542)->getDataProd().getAno() == 2022);
  CHECK(produto->getLote(163542)->getDataProd().getMes() == 10);
  CHECK(produto->getLote(163542)->getDataProd().getDia() == 10);

  CHECK(produto->getLote(163542)->getQuantidadeProduzida() == 20);
  CHECK(produto->getLote(163542)->getQuantidadeAtual() == 20); 

 }
 