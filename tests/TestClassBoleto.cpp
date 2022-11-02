#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/Boleto.h"
#include "../include/data.h"
#include "../include/Usuario.h"
#include "../include/Empresa.h"

vector<string> permissao() {
    vector<string> permissoes;
    permissoes.push_back("Boleto.Boleto");
    permissoes.push_back("Boleto.setDataDeVencimento");
    permissoes.push_back("Boleto.setCodigoDeBarras");
    permissoes.push_back("Boleto.setValor");

    return permissoes;
}

TEST_CASE("Construtor padrão da classe Boleto") {

    Usuario *user = new Usuario("admin@gmail.com", "admin123");
    Empresa *empresa = Empresa::getEmpresa();

    user->setPermissoes(permissao());
    empresa->login(user);

    Boleto *b = new Boleto();
    CHECK(b->getCodigoDeBarras() == "");
    CHECK(b->getValor() == 0);
    CHECK(b->getDataDeVencimento().getAno() == 0);

    SUBCASE("Testando o construtor da classe") {

        Data data = Data(2022, 01, 30);
        
        Boleto *b = new Boleto("123456789", data, 68.5);

        CHECK(b->getCodigoDeBarras() == "123456789");
        CHECK(b->getValor() == 68.5);
        CHECK(b->getDataDeVencimento().getAno() == 2022);
    }
}

TEST_CASE("Metodos set da classe Boleto") {

    Usuario *user = new Usuario("trainee@gmail.com", "trainee123");
    Empresa *empresa = Empresa::getEmpresa();

    user->setPermissoes(permissao());
    empresa->login(user);

    Data data = Data(2022, 05, 25);
    Boleto *b = new Boleto("123456789", data, 55.2);

    b->setDataDeVencimento(data);
    b->setValor(100);
    b->setCodigoDeBarras("0987654321");

    CHECK(b->getDataDeVencimento().getMes() == 05);
    CHECK(b->getValor() == 100);
    CHECK(b->getCodigoDeBarras() == "0987654321");
}