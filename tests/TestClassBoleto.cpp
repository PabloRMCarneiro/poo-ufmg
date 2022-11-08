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
        Data dataVencimento = Data(2022, 02, 30);
        
        Boleto *b = new Boleto("cartão de credito", 10, data, {1.2, 4.5, 6.0}, "987502918", dataVencimento, 1000.75);

        CHECK(b->getCodigoDeBarras() == "987502918");
        CHECK(b->getValor() == 1000.75);
        CHECK(b->getDataDeVencimento().getAno() == 2022);
        CHECK(b->getTipoDePagamento() == "cartão de credito");
    }
}

TEST_CASE("Metodos set da classe Boleto") {

    Usuario *user = new Usuario("trainee@gmail.com", "trainee123");
    Empresa *empresa = Empresa::getEmpresa();

    user->setPermissoes(permissao());
    empresa->login(user);

    Data data = Data(2022, 05, 25);
    Data dataVencimento = Data(2022, 06, 25);
    
    Boleto *b = new Boleto("cartão de credito", 10, data, {1.2, 1.5, 3.2}, "987502918", dataVencimento, 1000.75);

    b->setDataDeVencimento(data);
    b->setValor(100);
    b->setCodigoDeBarras("0987654321");
    b->setParcelamento({1.2, 3.5, 10});

    CHECK(b->getDataDeVencimento().getMes() == 05);
    CHECK(b->getValor() == 100);
    CHECK(b->getCodigoDeBarras() == "0987654321");
    CHECK(b->getParcelamento() == vector<float> {1.2, 3.5, 10});
}