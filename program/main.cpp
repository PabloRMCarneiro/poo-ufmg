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
using namespace std;
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
  permissoes.push_back("Cliente.setTipoCliente");
  permissoes.push_back("Cliente.getTipoCliente");

  permissoes.push_back("Data.Data");
  permissoes.push_back("Data.getAno");
  permissoes.push_back("Data.getMes");
  permissoes.push_back("Data.getDia");
  permissoes.push_back("Data.getHora");
  permissoes.push_back("Data.getMin");
  permissoes.push_back("Data.getSeg");
  permissoes.push_back("Data.setAno");
  permissoes.push_back("Data.setMes");
  permissoes.push_back("Data.setDia");
  permissoes.push_back("Data.setHora");
  permissoes.push_back("Data.setMin");
  permissoes.push_back("Data.setSeg");
  permissoes.push_back("Data.help");
  permissoes.push_back("Data.getData");
  permissoes.push_back("Data.getHorario");
  permissoes.push_back("Data.operator<");
  permissoes.push_back("Data.operator==");

  permissoes.push_back("Departamento.Departamento");
  permissoes.push_back("Departamento.getNome");
  permissoes.push_back("Departamento.setNome");

  permissoes.push_back("Endereco.Endereco");  
  permissoes.push_back("Endereco.setEndereco");  
  permissoes.push_back("Endereco.setX");  
  permissoes.push_back("Endereco.setY");  
  permissoes.push_back("Endereco.getEndereco");  
  permissoes.push_back("Endereco.getX");  
  permissoes.push_back("Endereco.getY");  
  permissoes.push_back("Endereco.getDistancia");

  permissoes.push_back("Funcionario.Funcionario");
  permissoes.push_back("Funcionario.getDepartamento");
  permissoes.push_back("Funcionario.getDataDeNascimento");
  permissoes.push_back("Funcionario.getSalario");
  permissoes.push_back("Funcionario.getRegistro");
  permissoes.push_back("Funcionario.getCargo");
  permissoes.push_back("Funcionario.getEstadoAtivo");
  permissoes.push_back("Funcionario.getJornada");
  permissoes.push_back("Funcionario.getIdVeiculo");
  permissoes.push_back("Funcionario.setJornada");
  permissoes.push_back("Funcionario.setIdVeiculo");
  permissoes.push_back("Funcionario.setDepartamento");
  permissoes.push_back("Funcionario.setDataDeNascimento");
  permissoes.push_back("Funcionario.setSalario");
  permissoes.push_back("Funcionario.setRegistro");
  permissoes.push_back("Funcionario.setCargo");
  permissoes.push_back("Funcionario.setEstadoAtivo");
  permissoes.push_back("Funcionario.alteraRegistro");
  permissoes.push_back("Funcionario.demiteFuncionario");
  permissoes.push_back("Funcionario.promocao");
  permissoes.push_back("Funcionario.reajuste");

  permissoes.push_back("Lote.Lote");
  permissoes.push_back("Lote.setDataProd");
  permissoes.push_back("Lote.setNumLote");
  permissoes.push_back("Lote.setProduto");
  permissoes.push_back("Lote.setQuantidadeAtual");
  permissoes.push_back("Lote.setQuantidadeProduzida");
  permissoes.push_back("Lote.getDataProd");
  permissoes.push_back("Lote.getNumLote");
  permissoes.push_back("Lote.getProduto");
  permissoes.push_back("Lote.getQuantidadeAtual");
  permissoes.push_back("Lote.getQuantidadeProduzida");
  permissoes.push_back("Lote.imprimeRegistro");
  permissoes.push_back("Lote.vende");

  permissoes.push_back("MateriaPrima.MateriaPrima");
  permissoes.push_back("MateriaPrima.geraOrdemDeCompra");
  permissoes.push_back("MateriaPrima.getUnidadeMedida");
  permissoes.push_back("MateriaPrima.getEstoqueMinimo");
  permissoes.push_back("MateriaPrima.getNome");
  permissoes.push_back("MateriaPrima.setEstoqueMin");
  permissoes.push_back("MateriaPrima.setEstoque");
  permissoes.push_back("MateriaPrima.setNome");
  permissoes.push_back("MateriaPrima.setUnidadeDeMedida");
  permissoes.push_back("MateriaPrima.getEstoque");

  permissoes.push_back("MetodoDePagamento.MetodoDePagamento");
  permissoes.push_back("MetodoDePagamento.getQuantidadeDeParcelas");
  permissoes.push_back("MetodoDePagamento.getQuantiaPorParcelas");
  permissoes.push_back("MetodoDePagamento.setQuantidadeDeParcelas");
  permissoes.push_back("MetodoDePagamento.setQuantiaPorParcelas");

  permissoes.push_back("Orcamento.auxiliarMateriaPrima");
  permissoes.push_back("Orcamento.auxiliarProduto");
  permissoes.push_back("Orcamento.Orcamento");
  permissoes.push_back("Orcamento.setTotal");
  permissoes.push_back("Orcamento.getPrecos");
  permissoes.push_back("Orcamento.setCompraDeProduto");
  permissoes.push_back("Orcamento.isCompraDeProduto");
  permissoes.push_back("Orcamento.getPreco");
  permissoes.push_back("Orcamento.setDataOrcamento");
  permissoes.push_back("Orcamento.getDataOrcamento");
  permissoes.push_back("Orcamento.getFornecedor");
  permissoes.push_back("Orcamento.setCliente");
  permissoes.push_back("Orcamento.getCliente");
  permissoes.push_back("Orcamento.getValorTotal");
  permissoes.push_back("Orcamento.getItens");
  permissoes.push_back("Orcamento.setFornecedor");
  permissoes.push_back("Orcamento.setItens");

  permissoes.push_back("OrdemDeCompra.OrdemDeCompra");
  permissoes.push_back("OrdemDeCompra.setMateriaPrimaLista");
  permissoes.push_back("OrdemDeCompra.setMateriaPrima");
  permissoes.push_back("OrdemDeCompra.setData");
  permissoes.push_back("OrdemDeCompra.setValorTotal");
  permissoes.push_back("OrdemDeCompra.setOrcamento");
  permissoes.push_back("OrdemDeCompra.gerarPedidos");
  permissoes.push_back("OrdemDeCompra.setMelhoresPrecos");
  permissoes.push_back("OrdemDeCompra.setCompra");
  permissoes.push_back("OrdemDeCompra.getDatOrdem");
  permissoes.push_back("OrdemDeCompra.setCompra");
  permissoes.push_back("OrdemDeCompra.getOrcamentos");
  permissoes.push_back("OrdemDeCompra.getMateriaPrimaLista");
  permissoes.push_back("OrdemDeCompra.getMelhoresPrecos");
  permissoes.push_back("OrdemDeCompra.getComprou");

  permissoes.push_back("OrdemDeProducao.OrdemDeProducao");
  permissoes.push_back("OrdemDeProducao.setDataOrdem");
  permissoes.push_back("OrdemDeProducao.setProduto");
  permissoes.push_back("OrdemDeProducao.setQuantidade");
  permissoes.push_back("OrdemDeProducao.getDataOrdem");
  permissoes.push_back("OrdemDeProducao.getProduto");
  permissoes.push_back("OrdemDeProducao.getQuantidade");
  permissoes.push_back("OrdemDeProducao.getOrdem");

  permissoes.push_back("PedidoDeCompra.PedidoDeCompra");
  permissoes.push_back("PedidoDeCompra.getCodigo");
  permissoes.push_back("PedidoDeCompra.setOrcamento");
  permissoes.push_back("PedidoDeCompra.setBoleto");
  permissoes.push_back("PedidoDeCompra.setCartaoDeCredito");
  permissoes.push_back("PedidoDeCompra.getOrcamento");
  permissoes.push_back("PedidoDeCompra.getBoleto");
  permissoes.push_back("PedidoDeCompra.getCartaoDeCredito");
  permissoes.push_back("PedidoDeCompra.setVenda");

  permissoes.push_back("Pessoa.Pessoa");
  permissoes.push_back("Pessoa.getNome");
  permissoes.push_back("Pessoa.getEndereco");
  permissoes.push_back("Pessoa.getEmail");
  permissoes.push_back("Pessoa.getDocumento");
  permissoes.push_back("Pessoa.getTelefone");
  permissoes.push_back("Pessoa.setNome");
  permissoes.push_back("Pessoa.setEndereco");
  permissoes.push_back("Pessoa.setEmail");
  permissoes.push_back("Pessoa.setDocumento");
  permissoes.push_back("Pessoa.setTelefone");

  permissoes.push_back("Produto.Produto");
  permissoes.push_back("Produto.getNome");
  permissoes.push_back("Produto.getCodigo");
  permissoes.push_back("Produto.getMateriaPrimaList");
  permissoes.push_back("Produto.setMateriaPrimaList");
  permissoes.push_back("Produto.getValorDeVenda");
  permissoes.push_back("Produto.getTamanhoDoLoteMinimo");
  permissoes.push_back("Produto.getEstoqueMinimo");
  permissoes.push_back("Produto.getQtdEstoque");
  permissoes.push_back("Produto.getCategoria");
  permissoes.push_back("Produto.getOrdem");
  permissoes.push_back("Produto.getLote");
  permissoes.push_back("Produto.setNome");
  permissoes.push_back("Produto.setCodigo");
  permissoes.push_back("Produto.setValorDeVenda");
  permissoes.push_back("Produto.setTamanhoDoLoteMinimo");
  permissoes.push_back("Produto.setEstoqueMinimo");
  permissoes.push_back("Produto.setQtdEstoque");
  permissoes.push_back("Produto.setCategoria");
  permissoes.push_back("Produto.registraLote");
  permissoes.push_back("Produto.realizaVenda");
  permissoes.push_back("Produto.geraOrdem");
  permissoes.push_back("Produto.temEstoque");
  permissoes.push_back("Produto.novoProduto");
  permissoes.push_back("Produto.getProduto");

  permissoes.push_back("RegistroVendas.RegistroVendas");
  permissoes.push_back("RegistroVendas.getCliente");
  permissoes.push_back("RegistroVendas.setCodigoPedido");
  permissoes.push_back("RegistroVendas.getCodigoPedido");
  permissoes.push_back("RegistroVendas.getDataDeVenda");
  permissoes.push_back("RegistroVendas.getNumeroDoLote");
  permissoes.push_back("RegistroVendas.getProduto");
  permissoes.push_back("RegistroVendas.getQuantidadeVenda");
  permissoes.push_back("RegistroVendas.setCliente");
  permissoes.push_back("RegistroVendas.setDataDeVenda");
  permissoes.push_back("RegistroVendas.setNumeroDoLote");
  permissoes.push_back("RegistroVendas.setProduto");
  permissoes.push_back("RegistroVendas.setQuantidadeVenda");
  permissoes.push_back("RegistroVendas.validaVenda");
  permissoes.push_back("RegistroVendas.imprime");

  permissoes.push_back("Salario.Salario");
  permissoes.push_back("Salario.getValor");
  permissoes.push_back("Salario.getRegistro");
  permissoes.push_back("Salario.getDissidio");
  permissoes.push_back("Salario.setValor");
  permissoes.push_back("Salario.setDissidio");
  permissoes.push_back("Salario.promocao");
  permissoes.push_back("Salario.reajuste");
  permissoes.push_back("Salario.atualizaRegistro");

  permissoes.push_back("Turno.Turno");
  permissoes.push_back("Turno.setEntradaHora");
  permissoes.push_back("Turno.setSaidaHora");
  permissoes.push_back("Turno.setPeriodo");
  permissoes.push_back("Turno.setJornada");
  permissoes.push_back("Turno.getPeriodo");
  permissoes.push_back("Turno.getEntradaHora");
  permissoes.push_back("Turno.getSaidaHora");
  permissoes.push_back("Turno.getJornada");
  
  permissoes.push_back("Veiculo.Veiculo");
  permissoes.push_back("Veiculo.setId");
  permissoes.push_back("Veiculo.setCapacidade");
  permissoes.push_back("Veiculo.setAtual");
  permissoes.push_back("Veiculo.setTempoDeRota");
  permissoes.push_back("Veiculo.setTurno");
  permissoes.push_back("Veiculo.setRota");
  permissoes.push_back("Veiculo.setPosicaoRota");
  permissoes.push_back("Veiculo.setPassageiros");
  permissoes.push_back("Veiculo.setPassageiro");
  permissoes.push_back("Veiculo.calculaTempo");
  permissoes.push_back("Veiculo.setHoraSaida");
  permissoes.push_back("Veiculo.auxiliarTempoSegundos");
  permissoes.push_back("Veiculo.auxiliarTempoHora");
  permissoes.push_back("Veiculo.tempoEmpresaCasa");
  permissoes.push_back("Veiculo.getPassageiro");
  permissoes.push_back("Veiculo.calculaRota");
  permissoes.push_back("Veiculo.excluiPassageiro");
  permissoes.push_back("Veiculo.setPassageiros");
  permissoes.push_back("Veiculo.getId");
  permissoes.push_back("Veiculo.getCapacidade");
  permissoes.push_back("Veiculo.getAtual");
  permissoes.push_back("Veiculo.getTempoDeRota");
  permissoes.push_back("Veiculo.getTurno");
  permissoes.push_back("Veiculo.getRota");
  permissoes.push_back("Veiculo.getHoraPosicao");
  permissoes.push_back("Veiculo.getPassageiros");
  permissoes.push_back("Veiculo.getHoraSaida");

  permissoes.push_back("Empresa.Empresa");
  permissoes.push_back("Empresa.getEmpresa");
  permissoes.push_back("Empresa.getlogsEscrita");
  permissoes.push_back("Empresa.getRegistrosVendas");
  permissoes.push_back("Empresa.getlogsLeitura");
  permissoes.push_back("Empresa.setlogAcessoNegado");
  permissoes.push_back("Empresa.getLogAcesso");
  permissoes.push_back("Empresa.getMateriaPrima");
  permissoes.push_back("Empresa.getMateriaPrimaLista");
  permissoes.push_back("Empresa.setMateriaPrima");
  permissoes.push_back("Empresa.setMateriaPrimaLista");
  permissoes.push_back("Empresa.setOrdemDeCompra");
  permissoes.push_back("Empresa.setOrdemDeProducao");
  permissoes.push_back("Empresa.getOrdemDeCompraLista");
  permissoes.push_back("Empresa.getOrdemDeProducaoLista");
  permissoes.push_back("Empresa.getCargo");
  permissoes.push_back("Empresa.getUsuario");
  permissoes.push_back("Empresa.login");
  permissoes.push_back("Empresa.setlogEscrita");
  permissoes.push_back("Empresa.setlogLeitura");
  permissoes.push_back("Empresa.setCargo");
  permissoes.push_back("Empresa.setEndereco");
  permissoes.push_back("Empresa.getEndereco");
  permissoes.push_back("Empresa.getDepartamento");
  permissoes.push_back("Empresa.getCategoria");
  permissoes.push_back("Empresa.setCategoria");
  permissoes.push_back("Empresa.getTurno");
  permissoes.push_back("Empresa.getTurnos");
  // permissoes.push_back("Empresa.excluiFuncionario");
  permissoes.push_back("Empresa.getVeiculo");
  permissoes.push_back("Empresa.getVeiculos");
  permissoes.push_back("Empresa.setTurno");
  permissoes.push_back("Empresa.setTurnos");
  permissoes.push_back("Empresa.setVeiculo");
  permissoes.push_back("Empresa.setVeiculos");
  permissoes.push_back("Empresa.setDepartamento");
  permissoes.push_back("Empresa.getCliente");
  permissoes.push_back("Empresa.setCliente");
  permissoes.push_back("Empresa.getFuncionario");
  permissoes.push_back("Empresa.getFuncionarios");
  permissoes.push_back("Empresa.setFuncionario");
  permissoes.push_back("Empresa.getRegistroVendas");
  permissoes.push_back("Empresa.setRegistroVendas");

  //  PERMISSOES HABILITADAS ANTERIORMENTE
  /* permissoes.push_back(("Empresa.getUsuario"));
  permissoes.push_back(("Empresa.getCargo"));
  permissoes.push_back(("Cargo.Cargo"));
  permissoes.push_back(("Cargo.getNome"));
  permissoes.push_back(("Empresa.getDepartamento"));    // Acesso a método getDepartamento
  permissoes.push_back(("Departamento.Departamento"));  // Acesso ao construtor Departamento
  permissoes.push_back(("Departamento.getNome"));       // Acesso ao método getNome
  permissoes.push_back(("Empresa.getCliente"));  // Acesso ao método getCiente
  permissoes.push_back(("Cliente.Cliente"));     // Acesso ao construtor Cliente
  permissoes.push_back(("Cliente.getTipoCliente"));   */

  // adicionar os restantes das permissoes

  return permissoes;
}



int main() {
  cout << "Teste" << endl;
  Usuario *usuario = new Usuario("admin", "admin");
  UsuarioLogado *usuarioLogado = UsuarioLogado::getUsuarioLogado();
  usuario->setPermissoes(permissoes());
  usuarioLogado->setUsuario(usuario);
  Data::dataDeHoje = Data(25,11,2022,22,9,43);
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
  
  for(auto it : empresa->getlogsEscrita()){
    it->imprime();
  }
  for(auto it : empresa->getlogsLeitura()){
    it->imprime();
  }
  for(auto it : empresa->getLogAcesso()){
    it->imprime();
  }

  return 0;
}