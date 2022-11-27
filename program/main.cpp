#include "../include/Boleto.h"
#include "../include/Cargo.h"
#include "../include/CartaoDeCredito.h"
#include "../include/Categoria.h"
#include "../include/Cliente.h"
#include "../include/data.h"
#include "../include/Departamento.h"
#include "../include/Empresa.h"
#include "../include/Endereco.h"
#include "../include/Fornecedor.h"
#include "../include/Funcionario.h"
#include "../include/Log.h"
#include "../include/LogEscrita.h"
#include "../include/LogLeitura.h"
#include "../include/Lote.h"
#include "../include/MateriaPrima.h"
#include "../include/MetodoDePagamento.h"
#include "../include/Orcamento.h"
#include "../include/OrdemDeCompra.h"
#include "../include/OrdemDeProducao.h"
#include "../include/PedidoDeCompra.h"
#include "../include/PermissaoNegada.h"
#include "../include/Pessoa.h"
#include "../include/Produto.h"
#include "../include/RegistroVendas.h"
#include "../include/Salario.h"
#include "../include/Turno.h"
#include "../include/Usuario.h"
#include "../include/UsuarioLogado.h"
#include "../include/Veiculo.h"

vector<string> permissoes(){
  vector<string> permissoes;

  permissoes.push_back("Boleto.Boleto");
  permissoes.push_back("Boleto.getDataDeVencimento");
  permissoes.push_back("Boleto.setDataDeVencimento");

  permissoes.push_back("Cargo.Cargo");
  permissoes.push_back("Cargo.getNome");
  permissoes.push_back("Cargo.setNome");

  permissoes.push_back("Categoria.Categoria");
  permissoes.push_back("Categoria.getTipo");
  permissoes.push_back("Categoria.setTipo");

  permissoes.push_back("Cliente.Cliente");
  



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
cout << "Teste" << endl;
  Data::dataDeHoje = Data(25,11,2022,22,9,43);
  cout << Data::dataDeHoje.getData() << endl;
  Usuario *usuario = new Usuario("admin", "admin");
  UsuarioLogado *usuarioLogado = UsuarioLogado::getUsuarioLogado();
  usuario->setPermissoes(permissoes());
  usuarioLogado->setUsuario(usuario);
  Empresa *empresa = Empresa::getEmpresa();
  empresa->setEndereco(Endereco("Rua Capitao ALexandre Guimaraes", -19.795, -45.684));




  /*PROVA USUARIO LOGADO SINGLETON*/
cout << "1 : " << &usuarioLogado << endl;

UsuarioLogado *usuarioLogado2 = UsuarioLogado::getUsuarioLogado();
cout << "2 : " << &usuarioLogado << endl;

empresa->login(usuarioLogado);

  /*cadastro de 3 funcionários*/

  vector<Data> registroFuncionario1 = {Data(1,1,2019), Data(1,1,2020), Data(1,1,2021)};
  vector<Data> registroFuncionario2 = {Data(1,3,2019), Data(1,4,2020), Data(1,6,2021)};
  vector<Data> registroFuncionario3 = {Data(1,1,2019), Data(1,4,2020), Data(1,9,2021)};
  //cout << registroFuncionario1[0].getData()<< endl;
  Funcionario *funcionario1 = new Funcionario("João da Silva", Endereco("Avenida Carlos Prastes, 6783", -19.791, -45.674), "joaoDaSilva@gmail.com", "29380512040", 77988487960, Departamento("TI"), Data(15, 11, 2000), Salario(15000), registroFuncionario1, Cargo("DevOps Senior"), true);
  Funcionario *funcionario2 = new Funcionario("Maria Oscalina", Endereco("Avenida Luz, 23", -19.793, -45.681), "mariaOscalina@gmail.com", "72060108063", 11804744532, Departamento("TI"), Data(2, 10, 1998), Salario(10000), registroFuncionario1, Cargo("Dev FullStack Senior"), true);
  Funcionario *funcionario3 = new Funcionario("João Marcus", Endereco("Avenida JK, 581", -19.789, -45.679), "joaoDaSilva@gmail.com", "29380512040", 77988487960, Departamento("TI"), Data(15, 11, 2000), Salario(15000), registroFuncionario1, Cargo("DevOps Senior"), true);
  // cout << funcionario1->getCargo().getNome() << ", " << funcionario1->getEndereco().getX() << ", " << funcionario1->getDocumento() << endl;
  


  /*cadastro de 2 clientes*/

  Cliente *clientePF = new Cliente("Maria Ines", Endereco("Rua das Camelias", 1, 2), "abcLuz@gmail.com", "13218864623", 37991232625);
  Cliente *clientePJ = new Cliente("Livia Carvalho", Endereco("Rua das Oliveiras", 1, 3), "luzLuz@gmail.com", "99058771000105", 37991205080);
  // cout << cliente1->getNome() << ", " << cliente1->getEndereco().getX() << ", " << cliente1->getDocumento() << ", " << cliente1->getTipoCliente() << endl;
  // cout << cliente2->getNome() << ", " << cliente2->getEndereco().getX() << ", " << cliente2->getDocumento() << ", " << cliente2->getTipoCliente() << endl;
  


  /*cadastro de 1 produto*/
  vector<pair<MateriaPrima*, double>> materiaPrimaList;
  MateriaPrima *madeira = new MateriaPrima("Madeira", "kg", 1);
  madeira->setEstoque(20, Data::dataDeHoje);
  MateriaPrima *plastico = new MateriaPrima("Plastico", "kg", 1);
  plastico->setEstoque(20, Data::dataDeHoje);
  MateriaPrima *aluminio = new MateriaPrima("Aluminio", "kg", 1);
  aluminio->setEstoque(20, Data::dataDeHoje);
  MateriaPrima *parafuso = new MateriaPrima("Parafuso", "unidades", 20);
  parafuso->setEstoque(300, Data::dataDeHoje);
  materiaPrimaList.push_back(make_pair(madeira, 0.45));
  materiaPrimaList.push_back(make_pair(plastico, 0.15));
  materiaPrimaList.push_back(make_pair(aluminio, 0.1));
  materiaPrimaList.push_back(make_pair(parafuso, 8));
  // cout << madeira->getNome() << ", " << madeira->getEstoque() << " " << madeira->getUnidadeMedida() << ", minimo: " << madeira->getEstoqueMinimo() << endl;
  // cout << plastico->getNome() << ", " << plastico->getEstoque() << " " << plastico->getUnidadeMedida() << ", minimo: " << plastico->getEstoqueMinimo() << endl;
  // cout << aluminio->getNome() << ", " << aluminio->getEstoque() << " " << aluminio->getUnidadeMedida() << ", minimo: " << aluminio->getEstoqueMinimo() << endl;
  // cout << parafuso->getNome() << ", " << parafuso->getEstoque() << " " << parafuso->getUnidadeMedida() << ", minimo: " << parafuso->getEstoqueMinimo() << endl;
  Produto *mesa = new Produto("Mesa", 1, 750, 11, 20, 0, "Moveis");
  mesa->setMateriaPrimaList(materiaPrimaList);
  //cout << mesa->getNome() << ", " << mesa->getValorDeVenda() << ", " << mesa->getCategoria()->getTipo() << endl;



  /*producao de lotes*/
  mesa->registraLote(1, Data::dataDeHoje);
  //cout << mesa->getQtdEstoque() << endl;
  mesa->registraLote(2, Data::dataDeHoje);
  //cout << mesa->getQtdEstoque() << endl;


  
  /*tentar excluir funcionario*/
  try{
    empresa->excluiFuncionario(funcionario2);
  } catch (string e){
    cout << e << endl;
  }  



  /*cliente pj solicita orcamento de 10 mesas*/
  vector<pair<string, double>> valItens;
  valItens.push_back(make_pair(mesa->getNome(), 10));
  Orcamento *orcamento = new Orcamento(1, valItens, Data::dataDeHoje, clientePJ);
  //cout << orcamento->getDataOrcamento().getData() << endl;
  //cout << orcamento->getPreco(mesa->getNome()) << endl;
  //cout << orcamento->getValorTotal() << endl;



  /*aumenta o preço 5% cliente pj compra 10 mesas*/
  mesa->alteraPreco(1.05);
  //cout << mesa->getValorDeVenda() << endl;
  PedidoDeCompra *pedido = new PedidoDeCompra(orcamento, Data(27,12, 2022));
  cout << "Codigo do pedido: " << pedido->getCodigo() << endl;
  //cout << mesa->getQtdEstoque() << endl;
  //cout << mesa->getLote(1)->getQuantidadeAtual() << endl;
  for(auto it : empresa->getRegistrosVendas()){
    it->imprime();
    cout << "Codigo do pedido: " << it->getCodigoPedido() << endl;
    for(auto it2 : it->getNumeroDoLote()){
      cout << "Lote vendido " << it2 << endl;
    }
  }
  //cout << mesa->getQtdEstoque() << endl;



  /*rota turno da manha*/
  Turno *matutino = new Turno("manha", Data(0,0,0,8,0,0), Data(0,0,0,16,0,0), 8);
  //cout << matutino->getEntradaHora().getData() << ", " << matutino->getPeriodo() << ", " << matutino->getSaidaHora().getData() << endl;
  funcionario1->setJornada(matutino);
  funcionario2->setJornada(matutino);
  funcionario3->setJornada(matutino);
  //cout << funcionario1->getJornada()->getPeriodo() << endl;
  Veiculo *primeiro = new Veiculo(1550, 20, matutino);
  //cout << primeiro->getCapacidade() << ", " << primeiro->getHoraSaida().getData();
  vector<Funcionario*> passageiros;
  passageiros.push_back(funcionario1);
  passageiros.push_back(funcionario2);
  passageiros.push_back(funcionario3);
  //cout << passageiros[1]->getNome() << endl;
  bool embarque = primeiro->setPassageiros(passageiros);
  //cout << embarque << endl;
  for(auto it : primeiro->getRota()){
    cout << primeiro->getPassageiro(it.second)->getNome() << " embarca às ";
    Data a = primeiro->getHoraPosicao(primeiro->getPassageiro(it.second)); 
    cout << a.getHorario() << endl;
  }
  
  
  Data::dataDeHoje = Data(26,11,2022,13,31,25);
  /*LOGS DE TODAS AS OPERACOES*/
  LogEscrita *logescrita1 = new LogEscrita("preco", "9.9", "10.6", "Produto");
  //logescrita->imprime();
  LogEscrita *logescrita2 = new LogEscrita("nome", "mesa", "mesa 3x4", "Produto");
  //logescrita->imprime();
  LogLeitura *logleitura = new LogLeitura("preco", "Produto");
  //logleitura->imprime();
  PermissaoNegada * permissaonegada = new PermissaoNegada("getNome", "Produto");
  //permissaonegada->imprime();
  
  // for(auto it : empresa->getlogsEscrita()){
  //   it->imprime();
  // }
  // for(auto it : empresa->getlogsLeitura()){
  //   it->imprime();
  // }
  // for(auto it : empresa->getLogAcesso()){
  //   it->imprime();
  // }

  return 0;
}