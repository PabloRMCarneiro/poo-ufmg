#include <iostream>
#include <vector>
#include "../include/data.h"
// #include "../include/Endereco.h"

#include "../include/Empresa.h"
#include "../include/Usuario.h"
#include "../include/UsuarioLogado.h"

#include "../include/Funcionario.h"
#include "../include/Pessoa.h"
#include "../include/Departamento.h"
#include "../include/Cargo.h"
#include "../include/Endereco.h"
#include "../include/Salario.h"
#include "../src/Pessoa.cpp"

using namespace std;


vector<string> permissoes(){
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
  permissoes.push_back(("Cliente.getTipoCliente"));  

  // adicionar os restantes das permissoes

  return permissoes;
}



int main() {
  /* cout << "Teste" << endl;
  // int valTempo; // min
  // int getHora, getMin, getSeg, valTempo2;
  // cin >> getHora >> getMin >> getSeg >> valTempo >> valTempo2;
  // cout << valTempo << " - " << valTempo2 << " - " << getHora << ":" << getMin << ":" << getSeg << endl;
  // valTempo = valTempo; // em segundos
  // int horaEntrada, horaturno, hora, minuto, segundo; 
  // horaturno = getHora*3600+ getMin*60 + getSeg;
  // horaEntrada = horaturno -600 - valTempo;
  // hora = int(horaEntrada/3600);
  // minuto = int((horaEntrada%3600)/60);
  // segundo = horaEntrada-(hora*3600 + minuto*60);
  // cout << hora << ":" << minuto << ":" << segundo << endl;
  // int tempoTotal, horaSaida, hora2, minuto2, segundo2;
  // horaSaida = hora*3600+ minuto*60 + segundo;
  // tempoTotal = horaSaida + valTempo2;
  // hora2 = int(tempoTotal/3600);
  // minuto2 = int((tempoTotal%3600)/60);
  // segundo2 = tempoTotal-(hora2*3600 + minuto2*60);
  // cout << segundo2 << endl;
  // cout << hora2 << ":" << minuto2 << ":" << segundo2 << endl;
<<<<<<< HEAD
  int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
  int *um = &a, *dois = &b, *tres = &c, *quatro = &d, *cinco = &e, *seis = &f;
  vector<int*> numeros;
  numeros.push_back(um);
  numeros.push_back(dois);
  numeros.push_back(tres);
  numeros.push_back(quatro);
  numeros.push_back(cinco);
  numeros.push_back(seis);
  vector <int*> subst;
  for(auto it : numeros){
    cout << (*it) << endl;
    if(it != quatro){
      subst.push_back(it);
    }
  }
  for(auto it : subst){
    cout << "novo: " << (*it) << endl;
  }
  return 0; */
  Empresa *empresa = Empresa::getEmpresa();
  Usuario *usuario = new Usuario("admin", "admin");
  UsuarioLogado *usuarioLogado = UsuarioLogado::getUsuarioLogado();
  
  usuario->setPermissoes(permissoes());

  usuarioLogado->setUsuario(usuario);

  empresa->login(usuarioLogado);

  /*cadastro de 3 funcionários*/

  vector<Data> registroFuncionario1 = {Data(1,1,2019), Data(1,1,2020), Data(1,1,2021)};
  vector<Data> registroFuncionario2 = {Data(1,3,2019), Data(1,4,2020), Data(1,6,2021)};
  vector<Data> registroFuncionario3 = {Data(1,1,2019), Data(1,4,2020), Data(1,9,2021)};

  Funcionario *funcionario1 = new Funcionario("João da Silva", Endereco("Avenida Carlos Prastes, 6783", 2, 2), "joaoDaSilva@gmail.com", "29380512040", 77988487960, Departamento("TI"), Data(15, 11, 2000), Salario(15000), registroFuncionario1, Cargo("DevOps Senior"), true);

  Funcionario *funcionario2 = new Funcionario("Maria Oscalina", Endereco("Avenida Luz, 23", 5, 6), "mariaOscalina@gmail.com", "72060108063", 11804744532, Departamento("TI"), Data(2, 10, 1998), Salario(10000), registroFuncionario1, Cargo("Dev FullStack Senior"), true);

  Funcionario *funcionario3 = new Funcionario("João da Silva", Endereco("Avenida Carlos Prastes, 6783", 2, 2), "joaoDaSilva@gmail.com", "29380512040", 77988487960, Departamento("TI"), Data(15, 11, 2000), Salario(15000), registroFuncionario1, Cargo("DevOps Senior"), true);
  

  // int a = 1, b = 2, c = 3, d = 4, e = 5, f = 6;
  // int *um = &a, *dois = &b, *tres = &c, *quatro = &d, *cinco = &e, *seis = &f;
  // vector<int*> numeros;
  // numeros.push_back(um);
  // numeros.push_back(dois);
  // numeros.push_back(tres);
  // numeros.push_back(quatro);
  // numeros.push_back(cinco);
  // numeros.push_back(seis);
  // vector <int*> subst;
  // for(auto it : numeros){
  //   cout << (*it) << endl;
  //   if(it != quatro){
  //     subst.push_back(it);
  //   }
  // }
  // for(auto it : subst){
  //   cout << "novo: " << (*it) << endl;
  // }
  Data a;
  cout << a.getAno() << endl;
  
  return 0;
}