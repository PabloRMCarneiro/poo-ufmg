#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../third_party/doctest.h"
#include "../include/Usuario.h"

using namespace std;

TEST_CASE("Construtor padrão da classe Usuário")
{
    Usuario usuario;
    CHECK(usuario.getEmail() == "");
    CHECK(usuario.getSenha() == "");
}

TEST_CASE("Construtor da classe Usuário")
{
    Usuario usuario("shaolinMatadorDePorco@gmail.com", "123456");
    CHECK(usuario.getEmail() == "shaolinMatadorDePorco@gmail.com");
    CHECK(usuario.getSenha() == "123456");
}

TEST_CASE("Método getEmail da classe Usuário")
{
    Usuario usuario("shaolinMatadorDePorco@gmail.com", "123456");
    usuario.setEmail("shaolinMatadorDePorco@gmail.com");
    CHECK(usuario.getEmail() == "shaolinMatadorDePorco@gmail.com");
}

TEST_CASE("Método getSenha da classe Usuário")
{
    Usuario usuario("shaolinMatadorDePorco@gmail.com", "123456");
    usuario.setSenha("123456");
    CHECK(usuario.getSenha() == "123456");
}

TEST_CASE("Método getPermissoes da classe Usuário")
{
    Usuario usuario("shaolinMatadorDePorco@gmail.com", "123456");
    vector <string> permissoes = {"Cadastrar", "Consultar", "Alterar", "Excluir"};
    usuario.setPermissoes(permissoes);
    CHECK(usuario.getPermissoes("Cadastrar") == true);
    CHECK(usuario.getPermissoes("Consultar") == true);
    CHECK(usuario.getPermissoes("Alterar") == true);
    CHECK(usuario.getPermissoes("Excluir") == true);
}