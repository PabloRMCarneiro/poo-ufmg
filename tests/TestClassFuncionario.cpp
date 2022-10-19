/* #include "../third_party/doctest.h"
#include "../include/Funcionario.h"
#include "../include/Pessoa.h"
#include "../include/Departamento.h"
#include "../include/Cargo.h"
#include "../include/Salario.h"

using namespace std;

TEST_CASE("Construtor padrão da classe Funcionario")
{
  Funcionario *f = new Funcionario();
  CHECK(f->getPessoa().getNome() == "");
  CHECK(f->getPessoa().getEndereco() == "");
  CHECK(f->getPessoa().getEmail() == "");
  CHECK(f->getPessoa().getDocumento() == "");
  CHECK(f->getPessoa().getTelefone() == 0);

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
  Pessoa *p = new Pessoa("João", "Rua 1", "teste@gmail.com", "29380512040", 99999999999);
  Departamento *d = new Departamento("Departamento 1");
  Data *data = new Data(2000, 1, 1);
  Salario *s = new Salario(1000.0);
  Cargo *c = new Cargo("Cargo 1");
  vector<Data> registro = {Data(2000, 1, 1), Data(2001, 1, 1), Data(2002, 1, 1)};

  Funcionario *f = new Funcionario(*p, *d, *data, *s, registro, *c, true);

  CHECK(f->getPessoa().getNome() == "João");
  CHECK(f->getPessoa().getEndereco() == "Rua 1");
  CHECK(f->getPessoa().getEmail() == "teste@gmail.com");
  CHECK(f->getPessoa().getDocumento() == "29380512040");
  CHECK(f->getPessoa().getTelefone() == 99999999999);

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

TEST_CASE("Método getPessoa da classeFuncionario")
{
  Pessoa *p = new Pessoa("João", "Rua 1", "teste@gmail.com", "29380512040", 99999999999);
  Funcionario *f = new Funcionario();
  f->setPessoa(*p);

  CHECK(f->getPessoa().getNome() == "João");
  CHECK(f->getPessoa().getEndereco() == "Rua 1");
  CHECK(f->getPessoa().getEmail() == "teste@gmail.com");
  CHECK(f->getPessoa().getDocumento() == "29380512040");
  CHECK(f->getPessoa().getTelefone() == 99999999999);

}

TEST_CASE("Método getDepartamento da classe Funcionario")
{
  Departamento *d = new Departamento("Departamento 1");
  Funcionario *f = new Funcionario();
  f->setDepartamento(*d);
  CHECK(f->getDepartamento().getNome() == "Departamento 1");
}

TEST_CASE("Método getDataNascimento da classe Funcionario")
{
  Data *data = new Data(2000, 1, 1);
  Funcionario *f = new Funcionario();
  f->setDataNascimento(*data);
  CHECK(f->getDataNascimento().getDia() == 1);
  CHECK(f->getDataNascimento().getMes() == 1);
  CHECK(f->getDataNascimento().getAno() == 2000);
}

TEST_CASE("Método getSalario da classe Funcionario")
{
  Salario *s = new Salario(1000.0);
  Funcionario *f = new Funcionario();
  f->setSalario(*s);
  CHECK(f->getSalario().getValor() == 1000.0);
}

TEST_CASE("Método getRegistro da classe Funcionario")
{
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
  Cargo *c = new Cargo("Cargo 1");
  Funcionario *f = new Funcionario();
  f->setCargo(*c);
  CHECK(f->getCargo().getNome() == "Cargo 1");
}

TEST_CASE("Método getEstadoAtivo da classe Funcionario")
{
  Funcionario *f = new Funcionario();
  f->setEstadoAtivo(true);
  CHECK(f->getEstadoAtivo() == true);
}

TEST_CASE("Método alteraRegistro da classe Funcionario")
{
  vector<Data> registro = {Data(2000, 1, 1), Data(2001, 1, 1), Data(2002, 1, 1)};
  Funcionario *f = new Funcionario();
  f->setRegistro(registro);
  f->alteraRegistro(Data(2003, 1, 1));
  CHECK(f->getRegistro().size() == 4);

  CHECK(f->getRegistro()[0].getDia() == 1);
  CHECK(f->getRegistro()[0].getMes() == 1);
  CHECK(f->getRegistro()[0].getAno() == 2000);

  CHECK(f->getRegistro()[1].getDia() == 1);
  CHECK(f->getRegistro()[1].getMes() == 1);
  CHECK(f->getRegistro()[1].getAno() == 2001);

  CHECK(f->getRegistro()[2].getDia() == 1);
  CHECK(f->getRegistro()[2].getMes() == 1);
  CHECK(f->getRegistro()[2].getAno() == 2002);

  CHECK(f->getRegistro()[3].getDia() == 1);
  CHECK(f->getRegistro()[3].getMes() == 1);
  CHECK(f->getRegistro()[3].getAno() == 2003);
}

TEST_CASE("Método demiteFuncionario da classe Funcionario")
{
  Funcionario *f = new Funcionario();
  f->demiteFuncionario();
  CHECK(f->getEstadoAtivo() == false);
}

TEST_CASE("Método alteraSalario da classe Funcionario")
{
  Salario *s = new Salario(1000.0);
  Funcionario *f = new Funcionario();
  f->setSalario(*s);
  f->alteraSalario(0.1);
  CHECK(f->getSalario().getValor() == 1100.0);
} */