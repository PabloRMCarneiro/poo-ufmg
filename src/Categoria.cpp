#include "../include/Categoria.h"

vector <Categoria*> Categoria::categorialist;
Categoria::Categoria()
{
    this->novaCategoria(this);
}

Categoria::Categoria(string t)
{
  this->setTipo(t);
  this->novaCategoria(this);
}

Categoria::~Categoria()
{
}

string Categoria::getTipo()
{
  return this->tipo;
}

void Categoria::setTipo(string t)
{
  this->tipo = t;
  
}
void Categoria::novaCategoria(Categoria* nova){
    categorialist.push_back(nova);
}
Categoria* Categoria::getCategoria(string t){
    for(auto it : categorialist){
            if(it->getTipo() == t){
                return it;
            }
        }
    return nullptr;
}