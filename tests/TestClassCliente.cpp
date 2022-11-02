#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/Cliente.h"
#include "../include/Empresa.h"
#include "../include/Usuario.h"

using namespace std;

vector<string> permissao() {
  vector<string> permissoes;
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

TEST_CASE("Construtor padrão da classe Cliente") {

  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Cliente *c = new Cliente();
  CHECK(c->getTipoCliente() == "");
}

TEST_CASE("Construtor classe Cliente") {

  Usuario *user = new Usuario("admin", "admin");

  user->setPermissoes(permissao());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Cliente *cliente = new Cliente("João", "Rua 1", "teste@gmail.com", "70655701000144", 99999999999);

  CHECK(cliente->getTipoCliente() == "Pessoa jurídica");
  
  CHECK(cliente->getNome() == "João");
  CHECK(cliente->getEndereco() == "Rua 1");
  CHECK(cliente->getEmail() == "teste@gmail.com");
  CHECK(cliente->getDocumento() == "70655701000144");
  CHECK(cliente->getTelefone() == 99999999999);
}
