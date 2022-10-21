#include "../include/Empresa.h"

#include "../include/Usuario.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  Usuario *usuario = new Usuario("admin", "admin");
  Usuario *usuario2 = new Usuario("admin2", "admin2");
  vector<string> permissoes;
  permissoes.push_back("Empresa.getUsuario");

  usuario->setPermissoes(permissoes);
  usuario2->setPermissoes(permissoes);

  Empresa *empresa = Empresa::getEmpresa();
  empresa->login(usuario);

  cout << empresa->getUsuario()->getEmail() << endl;
  cout << empresa->getUsuario()->getSenha() << endl;

  empresa->setUsuario(usuario2);

  cout << empresa->getUsuario()->getEmail() << endl;
  cout << empresa->getUsuario()->getSenha() << endl;

}