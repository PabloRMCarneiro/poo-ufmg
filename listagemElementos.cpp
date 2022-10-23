#include "iostream"
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
  vector<string> produtos;
  vector<pair<string, int>> lista;

  produtos.push_back("Arroz");
  produtos.push_back("Feijão");
  produtos.push_back("Arroz");
  produtos.push_back("Arroz");
  produtos.push_back("Feijão");
  produtos.push_back("Feijão");
  produtos.push_back("Arroz");
  produtos.push_back("Arroz");
  produtos.push_back("CoucaColaLight");
  produtos.push_back("CoucaColaLight");
  produtos.push_back("Feijão");
  produtos.push_back("CoucaColaLight");
  produtos.push_back("Feijão");
  produtos.push_back("Leite");
  produtos.push_back("Leite");
  produtos.push_back("Leite");
  produtos.push_back("Pão");

  for (int i = 0; i < produtos.size(); i++) {
    int cont = 0;
    for (int j = 0; j < produtos.size(); j++) {
      if (produtos[i] == produtos[j]) {
        cont++;
      }
    }
    for (int k = 0; k < lista.size(); k++) {
      if (produtos[i] == lista[k].first) {
        cont = 0;
      }
    }
    if (cont != 0) {
      lista.push_back(make_pair(produtos[i], cont));
    }
  }
  for (int i = 0; i < lista.size(); i++) {
    cout << lista[i].first << " " << lista[i].second << endl;
  }
}