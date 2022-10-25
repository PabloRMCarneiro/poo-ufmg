#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"

#include "../include/Funcionario.h"
#include "../include/Pessoa.h"
#include "../include/Departamento.h"
#include "../include/Cargo.h"
#include "../include/Salario.h"
#include "../include/Empresa.h"
#include <vector>
#include <string>

using namespace std;

vector<string> permissoes(){
  vector<string> permissoes;
  permissoes.push_back("Empresa.getFuncionario");

  permissoes.push_back("Funcionario.Funcionario");
  permissoes.push_back("Funcionario.getDepartamento");
  permissoes.push_back("Funcionario.getDataNascimento");
  permissoes.push_back("Funcionario.getSalario");
  permissoes.push_back("Funcionario.getRegistro");
  permissoes.push_back("Funcionario.getCargo");
  permissoes.push_back("Funcionario.getEstadoAtivo");
  permissoes.push_back("Funcionario.alteraRegistro");
  permissoes.push_back("Funcionario.demiteFuncionario");
  permissoes.push_back("Funcionario.promocao");
  permissoes.push_back("Funcionario.reajuste");

  permissoes.push_back("Pessoa.Pessoa");              
  permissoes.push_back("Pessoa.getNome");             
  permissoes.push_back("Pessoa.getEndereco");         
  permissoes.push_back("Pessoa.getEmail");             
  permissoes.push_back("Pessoa.getDocumento");         
  permissoes.push_back("Pessoa.getTelefone"); 

  permissoes.push_back("Departamento.Departamento");     
  permissoes.push_back("Departamento.getNome");         

  permissoes.push_back("Cargo.Cargo");                   
  permissoes.push_back("Cargo.getNome");                 

  permissoes.push_back("Salario.Salario");               
  permissoes.push_back("Salario.getValor");

  return permissoes;
};

TEST_CASE("Construtor padrão da classe Funcionario")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Funcionario *f = new Funcionario();
  CHECK(f->getNome() == "");
  CHECK(f->getEndereco() == "");
  CHECK(f->getEmail() == "");
  CHECK(f->getDocumento() == "");
  CHECK(f->getTelefone() == 0);

  CHECK(f->getDepartamento().getNome() == "");
  CHECK(f->getDataNascimento().getDia() == 0);
  CHECK(f->getDataNascimento().getMes() == 0);
  CHECK(f->getDataNascimento().getAno() == 0);
  CHECK(f->getSalario().getValor() == 0.0);
  CHECK(f->getRegistro().size() == 0);
  CHECK(f->getCargo().getNome() == "");
  CHECK(f->getEstadoAtivo() == false);
}

TEST_CASE("Construtor da classe Funcionario")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Pessoa *p = new Pessoa("João", "Rua 1", "teste@gmail.com", "29380512040", 99999999999);
  Departamento d =  Departamento("Departamento 1");
  Data data =  Data(2000, 1, 1);
  Salario s =  Salario(1000.0);
  Cargo c =  Cargo("Cargo 1");
  vector<Data> registro = {Data(2000, 1, 1), Data(2001, 1, 1), Data(2002, 1, 1)};

  Funcionario *f = new Funcionario(p->getNome(), p->getEndereco(), p->getEmail(), p->getDocumento(), p->getTelefone(), d, data, s, registro, c, true);

  CHECK(f->getNome() == "João");
  CHECK(f->getEndereco() == "Rua 1");
  CHECK(f->getEmail() == "teste@gmail.com");
  CHECK(f->getDocumento() == "29380512040");
  CHECK(f->getTelefone() == 99999999999);

  CHECK(f->getDepartamento().getNome() == "Departamento 1");
  CHECK(f->getDataNascimento().getDia() == 1);
  CHECK(f->getDataNascimento().getMes() == 1);
  CHECK(f->getDataNascimento().getAno() == 2000);
  CHECK(f->getSalario().getValor() == 1000.0);

  CHECK(f->getRegistro().size() == 3);

  CHECK(f->getRegistro()[0].getDia() == 1);
  CHECK(f->getRegistro()[0].getMes() == 1);
  CHECK(f->getRegistro()[0].getAno() == 2000);

  CHECK(f->getRegistro()[1].getDia() == 1);
  CHECK(f->getRegistro()[1].getMes() == 1);
  CHECK(f->getRegistro()[1].getAno() == 2001);

  CHECK(f->getRegistro()[2].getDia() == 1);
  CHECK(f->getRegistro()[2].getMes() == 1);
  CHECK(f->getRegistro()[2].getAno() == 2002);

  CHECK(f->getCargo().getNome() == "Cargo 1");
  CHECK(f->getEstadoAtivo() == true);
}

TEST_CASE("Destrutor da classe Funcionario")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Funcionario *f = new Funcionario();
  delete f;

  CHECK(f->getDepartamento().getNome() == "");
  CHECK(f->getDataNascimento().getDia() == 0);
  CHECK(f->getDataNascimento().getMes() == 0);
  CHECK(f->getDataNascimento().getAno() == 0);
  CHECK(f->getSalario().getValor() == 0.0);
  CHECK(f->getRegistro().size() == 0);
  CHECK(f->getCargo().getNome() == "");
  CHECK(f->getEstadoAtivo() == false);
}

TEST_CASE("Método getDepartamento da classe Funcionario")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Departamento *d = new Departamento("Departamento 1");
  Funcionario *f = new Funcionario();
  f->setDepartamento(*d);
  CHECK(f->getDepartamento().getNome() == "Departamento 1");
}

TEST_CASE("Método getDataNascimento da classe Funcionario")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Data *data = new Data(2000, 1, 1);
  Funcionario *f = new Funcionario();
  f->setDataNascimento(*data);
  CHECK(f->getDataNascimento().getDia() == 1);
  CHECK(f->getDataNascimento().getMes() == 1);
  CHECK(f->getDataNascimento().getAno() == 2000);
}

TEST_CASE("Método getSalario da classe Funcionario")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Salario s =  Salario(1000.0);
  Funcionario *f = new Funcionario();
  Data data = Data(2000, 1, 1);
  f->setSalario(data, s);

  CHECK(f->getSalario().getValor() == 1000.0);
}

TEST_CASE("Método getRegistro da classe Funcionario")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  vector<Data> registro = {Data(2000, 1, 1), Data(2001, 1, 1), Data(2002, 1, 1)};
  Funcionario *f = new Funcionario();
  f->setRegistro(registro);
  CHECK(f->getRegistro().size() == 3);

  CHECK(f->getRegistro()[0].getDia() == 1);
  CHECK(f->getRegistro()[0].getMes() == 1);
  CHECK(f->getRegistro()[0].getAno() == 2000);

  CHECK(f->getRegistro()[1].getDia() == 1);
  CHECK(f->getRegistro()[1].getMes() == 1);
  CHECK(f->getRegistro()[1].getAno() == 2001);

  CHECK(f->getRegistro()[2].getDia() == 1);
  CHECK(f->getRegistro()[2].getMes() == 1);
  CHECK(f->getRegistro()[2].getAno() == 2002);
}

TEST_CASE("Método getCargo da classe Funcionario")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Cargo *c = new Cargo("Cargo 1");
  Funcionario *f = new Funcionario();
  f->setCargo(*c);
  CHECK(f->getCargo().getNome() == "Cargo 1");
}

TEST_CASE("Método getEstadoAtivo da classe Funcionario")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Funcionario *f = new Funcionario();
  f->setEstadoAtivo(true);
  CHECK(f->getEstadoAtivo() == true);
}

TEST_CASE("Método demiteFuncionario da classe Funcionario")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Funcionario *f = new Funcionario();
  f->demiteFuncionario();
  CHECK(f->getEstadoAtivo() == false);
}

TEST_CASE("Método alteraRegistro da classe Funcionario")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Funcionario *f = new Funcionario();
  Salario s = Salario(1000.0);
  Data data1 = Data(2000, 1, 1);
  Data data2 = Data(2015, 1, 1);
  Data data3 = Data(2022, 1, 1);

  vector <Data> datas = {data1, data2};
  
  f->setRegistro(datas);
  f->alteraRegistro(data3);

  CHECK(f->getRegistro().size() == 3);
  
  CHECK(f->getRegistro()[0].getDia() == 1);
  CHECK(f->getRegistro()[0].getMes() == 1);
  CHECK(f->getRegistro()[0].getAno() == 2000);

  CHECK(f->getRegistro()[1].getDia() == 1);
  CHECK(f->getRegistro()[1].getMes() == 1);
  CHECK(f->getRegistro()[1].getAno() == 2015);

  CHECK(f->getRegistro()[2].getDia() == 1);
  CHECK(f->getRegistro()[2].getMes() == 1);
  CHECK(f->getRegistro()[2].getAno() == 2022);

}

TEST_CASE("Método promocao da classe Funcionario")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Funcionario *f = new Funcionario();
  Salario s = Salario(1000.0);
  
  Data data1 = Data(2015, 1, 1);
  Data data2 = Data(2016, 1, 1);

  f->setSalario(data1, s);

  f->promocao(data2, 20);

  CHECK(f->getSalario().getValor() == 1200.0);

}

TEST_CASE("Método reajuste da classe Funcionario")
{
  Usuario *user = new Usuario("admin", "admin");
  
  user->setPermissoes(permissoes());
  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(user);

  Pessoa *p1 = new Pessoa("João1", "Rua 1", "teste@gmail.com", "19380512040", 99999999999);
  Pessoa *p2 = new Pessoa("João2", "Rua 1", "teste@gmail.com", "29380512040", 99999999999);
  Pessoa *p3 = new Pessoa("João3", "Rua 1", "teste@gmail.com", "39380512040", 99999999999);

  Departamento d =  Departamento("Departamento 1");
  Data data =  Data(2000, 1, 1);
 
  Salario s1 = Salario(1200.0);
  Salario s2 = Salario(1000.0);
  Salario s3 = Salario(2000.0);

  Cargo c =  Cargo("Cargo 1");
  vector<Data> registro = {Data(2000, 1, 1)};

  Funcionario *f1 = new Funcionario(p1->getNome(), p1->getEndereco(), p1->getEmail(), p1->getDocumento(), p1->getTelefone(), d, data, s1, registro, c, true);

  Funcionario *f2 = new Funcionario(p2->getNome(), p2->getEndereco(), p2->getEmail(), p2->getDocumento(), p2->getTelefone(), d, data, s2, registro, c, true);
  
  Funcionario *f3 = new Funcionario(p3->getNome(), p3->getEndereco(), p3->getEmail(), p3->getDocumento(), p3->getTelefone(), d, data, s3, registro, c, true);
  
  Data data2 = Data(2015, 1, 1);

  empresa->setFuncionario(f1);
  empresa->setFuncionario(f2);
  empresa->setFuncionario(f3);
  
  f1->reajuste(data2, 20);

  vector <Funcionario*> funcionarios = empresa->getFuncionario();

  CHECK(funcionarios[0]->getSalario().getValor() == 1440);
  CHECK(funcionarios[1]->getSalario().getValor() == 1200);  
  CHECK(funcionarios[2]->getSalario().getValor() == 2400);
}