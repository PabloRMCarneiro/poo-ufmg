#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"

#include "../include/Cliente.h"
#include "../include/Empresa.h"
#include "../include/Orcamento.h"
#include "../include/Produto.h"
#include "../include/data.h"

using namespace std;

vector<string> permissoes() {

  vector<string> permissoes;

  permissoes.push_back("Orcamento.Orcamento");
  permissoes.push_back("Orcamento.getProduto");
  permissoes.push_back("Orcamento.getQuantidade");
  permissoes.push_back("Orcamento.getData");
  permissoes.push_back("Orcamento.getValorTotal");
  permissoes.push_back("Orcamento.getCliente");
  permissoes.push_back("Orcamento.setProduto");
  permissoes.push_back("Orcamento.setData");
  permissoes.push_back("Orcamento.setCliente");
  permissoes.push_back("Orcamento.listagemDeProdutos");
  permissoes.push_back("Orcamento.realizaOrcamento");

  permissoes.push_back("Produto.Produto");
  permissoes.push_back("Produto.getNome");
  permissoes.push_back("Produto.getCodigo");
  permissoes.push_back("Produto.getValorDeVenda");
  permissoes.push_back("Produto.getTamanhoDoLoteMinimo");
  permissoes.push_back("Produto.getEstoqueMinimo");
  permissoes.push_back("Produto.getQtdEstoque");
  permissoes.push_back("Produto.getCategoria");
  permissoes.push_back("Produto.novoProduto");
  permissoes.push_back("Produto.getOrdem");
  permissoes.push_back("Produto.registraLote");

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

  permissoes.push_back("Cliente.Cliente");
  permissoes.push_back("Cliente.getTipoCliente");

  permissoes.push_back("Pessoa.Pessoa");
  permissoes.push_back("Pessoa.getNome");
  permissoes.push_back("Pessoa.getEndereco");
  permissoes.push_back("Pessoa.getTelefone");
  permissoes.push_back("Pessoa.getDocumento");
  permissoes.push_back("Pessoa.getEmail");

  return permissoes;
}

TEST_CASE("Construtor Padrão da Classe Orcamento") {

  Usuario *usuario = new Usuario("admin", "admin");
  usuario->setPermissoes(permissoes());

  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(usuario);

  Orcamento *orcamento = new Orcamento();
  CHECK(orcamento->getQuantidade("") == 0);
  CHECK(orcamento->getData().getDia() == 0);
  CHECK(orcamento->getData().getMes() == 0);
  CHECK(orcamento->getData().getAno() == 0);
  CHECK(orcamento->getCliente().getNome() == "");
}

TEST_CASE("realizaOrcamento da Classe Orcamento") {

  Usuario *usuario = new Usuario("admin", "admin");
  usuario->setPermissoes(permissoes());

  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(usuario);

  Orcamento *orcamento = new Orcamento();

  Produto *produto1 = new Produto("Coca-Cola 1L", 1001, 4.53, 15, 10, 100, "Bebidas");


  orcamento->setProduto(produto1);
  orcamento->setProduto(produto1);
  orcamento->setProduto(produto1);
  orcamento->setProduto(produto1);

  cout << "----------------------------------------" << endl << endl << endl << endl;
  orcamento->realizaOrcamento();
  cout << endl << endl << endl << endl;
  cout << "----------------------------------------" << endl;
}