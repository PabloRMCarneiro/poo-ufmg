#include <cstdlib>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"

#include "../include/Empresa.h"
#include "../include/Usuario.h"
#include "../include/Cargo.h"
#include "../include/Departamento.h"
#include "../include/Cliente.h"
#include "../include/Funcionario.h"
#include "../include/data.h"
#include "../include/Salario.h"
#include "../include/RegistroVendas.h"

#include <string>
#include <vector>

using namespace std;

vector<string> permissao() {
  vector<string> permissoes;
  permissoes.push_back(("Empresa.getUsuario"));
  permissoes.push_back(("Empresa.getCargo"));
  permissoes.push_back(("Cargo.Cargo"));
  permissoes.push_back(("Cargo.getNome"));
  permissoes.push_back(("Empresa.getDepartamento"));    // Acesso a método getDepartamento
  permissoes.push_back(("Departamento.Departamento"));  // Acesso ao construtor Departamento
  permissoes.push_back(("Departamento.getNome"));       // Acesso ao método getNome
  permissoes.push_back(("Empresa.getCliente"));  // Acesso ao método getCiente
  permissoes.push_back(("Cliente.Cliente"));     // Acesso ao construtor Cliente
  permissoes.push_back(("Cliente.getTipoCliente"));  // Acesso ao método getTipoCliente
  
  permissoes.push_back(("Pessoa.Pessoa"));       // Acesso ao construtor Pessoa
  permissoes.push_back(("Pessoa.getNome"));      // Acesso ao método getPessoa
  permissoes.push_back(("Pessoa.getEndereco"));  // Acesso ao método getEndereco
  permissoes.push_back(("Pessoa.getEmail"));     // Acesso ao método getEmail
  permissoes.push_back(("Pessoa.getDocumento")); // Acesso ao método getDocumento
  permissoes.push_back(("Pessoa.getTelefone"));  // Acesso ao método getTelefone

  permissoes.push_back(("Empresa.getFuncionario"));  
  permissoes.push_back(("Empresa.getRegistroVendas"));   // Acesso ao método getRegistroVendas  

  permissoes.push_back(("Funcionario.Funcionario"));       // Acesso ao construtor Funcionario
  permissoes.push_back(("Funcionario.getSalario"));        // Acesso ao método getSalario
  permissoes.push_back(("Funcionario.getCargo"));          // Acesso ao método getCargo
  permissoes.push_back(("Funcionario.getDepartamento"));   // Acesso ao método getDepartamento
  permissoes.push_back(("Funcionario.getDataNascimento")); // Acesso ao método getDataNascimento
  permissoes.push_back(("Funcionario.getRegistro"));       // Acesso ao método getRegistro
  permissoes.push_back(("Funcionario.getEstadoAtivo"));    // Acesso ao método getEstadoAtivo

  permissoes.push_back(("Departamento.Departamento"));     // Acesso ao construtor Departamento
  permissoes.push_back(("Departamento.getNome"));          // Acesso ao método getNome

  permissoes.push_back(("Cargo.Cargo"));                   // Acesso ao construtor Cargo
  permissoes.push_back(("Cargo.getNome"));                 // Acesso ao método getNome

  permissoes.push_back(("Salario.Salario"));               // Acesso ao construtor Salario
  permissoes.push_back(("Salario.getValor"));              // Acesso ao método getValor

  permissoes.push_back(("RegistroVendas.RegistroVendas"));      // Acesso ao construtor RegistroVendas
  permissoes.push_back(("RegistroVendas.getCliente"));          // Acesso ao método getCliente
  permissoes.push_back(("RegistroVendas.getDataDeVenda"));      // Acesso ao método getDataDeVenda
  permissoes.push_back(("RegistroVendas.getNumeroDoLote"));     // Acesso ao método getNumeroDoLote
  permissoes.push_back(("RegistroVendas.getProduto"));          // Acesso ao construtor getProduto
  permissoes.push_back(("RegistroVendas.getQuantidadeVenda"));  // Acesso ao construtor getQuantidadeVenda

  permissoes.push_back(("Produto.Produto"));                    // Acesso ao construtor Produto
  permissoes.push_back(("Produto.getNome"));                    // Acesso ao método getNome
  permissoes.push_back(("Produto.getCodigo"));                  // Acesso ao método getCodigo
  permissoes.push_back(("Produto.getValorDeVenda"));            // Acesso ao método getValorDeVenda
  permissoes.push_back(("Produto.getTamanhoDoLoteMinimo"));     // Acesso ao método getTamanhoDoLoteMinimo
  permissoes.push_back(("Produto.getEstoqueMinimo"));           // Acesso ao método getEstoqueMinimo
  permissoes.push_back(("Produto.getQtdEstoque"));              // Acesso ao método getQtdEstoque
  permissoes.push_back(("Produto.getCategoria"));               // Acesso ao método getCategoria
  permissoes.push_back(("Produto.novoProduto"));               // Acesso ao método novoProduto
  permissoes.push_back(("Produto.temEstoque"));               // Acesso ao método temEstoque
  permissoes.push_back(("Produto.realizaVenda"));               // Acesso ao método realizaVenda

  permissoes.push_back(("Categoria.Categoria"));                // Acesso ao construtor Categoria
  permissoes.push_back(("Categoria.getCategoria"));           // Acesso ao método getCategoria
  permissoes.push_back(("Categoria.novaCategoria"));         // Acesso ao método novaCategoria
  permissoes.push_back("Categoria.getNome");

  return permissoes;
}

TEST_CASE("Teste Empresa - Usuario") {

  Usuario *usuario = new Usuario("admin", "admin");
  Usuario *usuario2 = new Usuario("admin2", "admin2");

  usuario->setPermissoes(permissao());
  usuario2->setPermissoes(permissao());

  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(usuario);

  CHECK(empresa->getUsuario()->getEmail() == "admin");
  CHECK(empresa->getUsuario()->getSenha() == "admin");

  empresa->setUsuario(usuario2);

  CHECK(empresa->getUsuario()->getEmail() == "admin2");
  CHECK(empresa->getUsuario()->getSenha() == "admin2");

}

TEST_CASE("Teste Empresa - Cargo") {

  Usuario *usuario = new Usuario("admin", "admin");

  usuario->setPermissoes(permissao());

  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(usuario);

  Cargo *cargo = new Cargo("Cargo1");
  empresa->setCargo(cargo);

  CHECK(empresa->getCargo(cargo)->getNome() == "Cargo1");
}

TEST_CASE("Teste Empresa - Departamento") {

  Usuario *usuario = new Usuario("admin", "admin");

  usuario->setPermissoes(permissao());

  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(usuario);

  Departamento *departamento = new Departamento("Departamento1");
  empresa->setDepartamento(departamento);

  CHECK(empresa->getDepartamento(departamento->getNome())->getNome() == "Departamento1");
}

TEST_CASE("Teste Empresa - Cliente"){

  Usuario *usuario = new Usuario("admin", "admin");

  usuario->setPermissoes(permissao());

  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(usuario);

  Cliente *clienteCNPJ = new Cliente("NomeCliente", "EnderecoCliente", "emailCliente@gmail.com", "83518119000188", 988112233);
  Cliente *clienteCPF = new Cliente("NomeCliente", "EnderecoCliente", "emailCliente@gmail.com", "11258901005", 988112233);

  empresa->setCliente(clienteCNPJ);
  empresa->setCliente(clienteCPF);

  CHECK(empresa->getCliente(clienteCNPJ->getDocumento())->getNome() == "NomeCliente");
  CHECK(empresa->getCliente(clienteCPF->getDocumento())->getNome() == "NomeCliente");

  CHECK(empresa->getCliente(clienteCNPJ->getDocumento())->getEndereco() == "EnderecoCliente");
  CHECK(empresa->getCliente(clienteCPF->getDocumento())->getEndereco() == "EnderecoCliente");

  CHECK(empresa->getCliente(clienteCNPJ->getDocumento())->getEmail() == "emailCliente@gmail.com");
  CHECK(empresa->getCliente(clienteCPF->getDocumento())->getEmail() == "emailCliente@gmail.com");

  CHECK(empresa->getCliente(clienteCNPJ->getDocumento())->getDocumento() == "83518119000188");
  CHECK(empresa->getCliente(clienteCPF->getDocumento())->getDocumento() == "11258901005");

  CHECK(empresa->getCliente(clienteCNPJ->getDocumento())->getTelefone() == 988112233);
  CHECK(empresa->getCliente(clienteCPF->getDocumento())->getTelefone() == 988112233);

  CHECK(empresa->getCliente(clienteCNPJ->getDocumento())->getTipoCliente() == "Pessoa jurídica");
  CHECK(empresa->getCliente(clienteCPF->getDocumento())->getTipoCliente() == "Pessoa física");

}   

TEST_CASE("Teste Empresa - Funcionario") {
  
  Usuario *usuario = new Usuario("admin", "admin");

  usuario->setPermissoes(permissao());

  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(usuario);

  Departamento departamento = Departamento("TI");
  Cargo cargo = Cargo("Back-End Develop");
  
  Data dataNascimento = Data(2022,1,1);
  Salario salario = Salario(6000);
  
  vector <Data> registro;
  registro.push_back(Data(1980,2,12));
  registro.push_back(Data(2001,2,12));
  registro.push_back(Data(2023,2,12));

  Funcionario *funcionario = new Funcionario("NomeFuncionario", "EnderecoFuncionario", "emailFuncionario@gmail.com", "11258901005", 988112233, departamento, dataNascimento, salario, registro, cargo, false);

  empresa->setFuncionario(funcionario);

  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getNome() == "NomeFuncionario");
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getEndereco() == "EnderecoFuncionario");
  
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getEmail() == "emailFuncionario@gmail.com");
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getDocumento() == "11258901005");
  
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getTelefone() == 988112233);
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getDepartamento().getNome() == "TI");
  
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getDataNascimento().getDia() == 1); 
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getDataNascimento().getMes() == 1);
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getDataNascimento().getAno() == 2022);

  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getSalario().getValor() == 6000.00);

  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getRegistro()[0].getDia() == 12);
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getRegistro()[0].getMes() == 2);
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getRegistro()[0].getAno() == 1980);

  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getRegistro()[1].getDia() == 12);
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getRegistro()[1].getMes() == 2);
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getRegistro()[1].getAno() == 2001);

  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getRegistro()[2].getDia() == 12);
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getRegistro()[2].getMes() == 2);
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getRegistro()[2].getAno() == 2023);

  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getCargo().getNome() == "Back-End Develop");
  CHECK(empresa->getFuncionario(funcionario->getDocumento())->getEstadoAtivo() == false);



}

TEST_CASE("Teste Empresa - Registro De Vendas"){
  
  Usuario *usuario = new Usuario("admin", "admin");

  usuario->setPermissoes(permissao());
  
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(usuario);

  Data dataDeVenda = Data(2022,10,15);
  Cliente *cliente = new Cliente("NomeCliente", "EnderecoCliente", "emailCliente@gmail.com", "83518119000188", 988112233);
  Produto *produto = new Produto("CoucaCoula Light", 101001, 10.00, 25, 5, 15, "Bebidas");
  RegistroVendas *registroVendas = new RegistroVendas(dataDeVenda, produto, 10, cliente);

  empresa->setRegistroVendas(registroVendas);

  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getDataDeVenda().getDia() == 15);
  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getDataDeVenda().getMes() == 10);
  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getDataDeVenda().getAno() == 2022);

  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getProduto()->getNome() == "CoucaCoula Light");
  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getProduto()->getCodigo() == 101001);
  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getProduto()->getValorDeVenda() == 10.00);
  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getProduto()->getTamanhoDoLoteMinimo() == 25);
  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getProduto()->getEstoqueMinimo() == 5);
  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getProduto()->getQtdEstoque() == 15);
  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getProduto()->getCategoria() == "Bebidas");

  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getQuantidadeVenda() == 10);

  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getCliente()->getNome() == "NomeCliente");
  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getCliente()->getEndereco() == "EnderecoCliente");
  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getCliente()->getEmail() == "emailCliente@gmail.com");
  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getCliente()->getDocumento() == "83518119000188");
  CHECK(empresa->getRegistroVendas(dataDeVenda, produto, cliente)->getCliente()->getTelefone() == 988112233);

}