// #include "../include/Orcamento.h"

// Orcamento::Orcamento() {
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.Orcamento")) {
//     throw "Acesso negado a Orcamento.Orcamento";
//   } else {
//     this->data = Data();
//     this->cliente = new Cliente;
//     this->historico = vector<pair<Produto*, float>>();
//   }
// }

// Orcamento::Orcamento(Cliente cliente, Data data){
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.Orcamento")) {
//     throw "Acesso negado a Orcamento.Orcamento";
//   } else {
//     this->data = data;
//     this->cliente = cliente;
//     this->valorTotal = 0;
//   }
// }

// vector<Produto*> Orcamento::getProduto() {
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.getProduto")) {
//     throw "Acesso negado a Orcamento.getProduto";
//   } else {
//     return this->produtos;
//   }
// }

// int Orcamento::getQuantidade(string nomeDoProduto) {
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.getQuantidade")) {
//     throw "Acesso negado a Orcamento.getQuantidade";
//   } else {
//     this->listagemDeProdutos();
//     for (int i = 0; i < this->historico.size(); i++) {
//       if (this->historico[i].first->getNome() == nomeDoProduto) {
//         return this->historico[i].second;
//       }
//     }
//     return 0;
//   }
// }

// Data Orcamento::getData() {
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.getData")) {
//     throw "Acesso negado a Orcamento.getData";
//   } else {
//     return this->data;
//   }
// }

// Cliente Orcamento::getCliente() {
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.getCliente")) {
//     throw "Acesso negado a Orcamento.getCliente";
//   } else {
//     return this->cliente;
//   }
// }

// float Orcamento::getValorTotal() {
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.getValorTotal")) {
//     throw "Acesso negado a Orcamento.getValorTotal";
//   } else {
//     return this->valorTotal;
//   }
// }

// vector<MateriaPrima*> Orcamento::getMateriaPrimaLista(){
//   if(true){//!Empresa::getEmpresa()->getAcesso("Orcamento.getMateriaPrimaLista")) {
//     throw "Acesso negado a Orcamento.getMateriaPrimaLista";
//   } else {
//     return this->materiaPrimaLista;
//   }
// }

// vector<pair<MateriaPrima*, double>> Orcamento::getHistoricoMateriaPrima(){
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.getHistoricoMateriaPrima")) {
//     throw "Acesso negado a Orcamento.getHistoricoMateriaPrima";
//   } else {
//     return this->historicoMateriaPrimaLista;
//   }
// }

// Fornecedor *Orcamento::getFornecedor(){
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.getFornecedor")) {
//     throw "Acesso negado a Orcamento.getFornecedor";
//   } else {
//     return this->fornecedor;
//   }
// }

// void Orcamento::setFornecedor(Fornecedor *fornecedor){
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.setFornecedor")) {
//     throw "Acesso negado a Orcamento.setFornecedor";
//   } else {
//     this->fornecedor = fornecedor;
//   }
// }

// void Orcamento::setMateriaPrimaLista(vector<MateriaPrima*> materiaPrimaLista){
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.setMateriaPrimaLista")) {
//     throw "Acesso negado a Orcamento.setMateriaPrimaLista";
//   } else {
//     this->materiaPrimaLista = materiaPrimaLista;
//   }
// }

// void Orcamento::setProduto(Produto* produto) {
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.setProduto")) {
//     throw "Acesso negado a Orcamento.setProduto";
//   } else {
//     this->produtos.push_back(produto);
//   }
// }

// void Orcamento::setData(Data data) {
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.setData")) {
//     throw "Acesso negado a Orcamento.setData";
//   } else {
//     this->data = data;
//   }
// }

// void Orcamento::setCliente(Cliente cliente) {
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.setCliente")) {
//     throw "Acesso negado a Orcamento.setCliente";
//   } else {
//     this->cliente = cliente;
//   }
// }

// void Orcamento::listagemDeProdutos() {
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.listagemDeProdutos")) {
//     throw "Acesso negado a Orcamento.listagemDeProdutos";
//   } else {
//     for (int i = 0; i < this->produtos.size(); i++) {
//       int cont = 0;
//       for (int j = 0; j < this->produtos.size(); j++) {
//         if (this->produtos[i]->getNome() == this->produtos[j]->getNome()) {
//           cont++;
//         }
//       }
//       for (int k = 0; k < this->historico.size(); k++) {
//         if (this->produtos[i]->getNome() == this->historico[k].first->getNome()) {
//           cont = 0;
//         }
//       }
//       if (cont != 0) {
//         this->historico.push_back(make_pair(this->produtos[i], cont));
//       }
//     }
//   }
// }

// void Orcamento::realizaOrcamento(){
//   if (true){//!Empresa::getEmpresa()->getAcesso("Orcamento.realizaOrcamento")) {
//     throw "Acesso negado a Orcamento.realizaOrcamento";
//   } else {
//     this->listagemDeProdutos();
//     this->valorTotal = 0;
//     cout <<"Produto - Quantidade - Valor Unitário" << endl;
//     for (int i = 0; i < this->historico.size(); i++) {
//       this->valorTotal += this->historico[i].first->getValorDeVenda() * this->historico[i].second;
//     }
//     for(int i = 0; i < this->historico.size(); i++) {
//       cout << this->historico[i].first->getNome() << " - " << this->historico[i].second << " - R$ " << this->historico[i].first->getValorDeVenda() << endl;
//     }
//     cout << "Valor total: R$ " << this->valorTotal << endl;
//   }
  
// }