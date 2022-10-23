#include "../include/Categoria.h"
#include "../include/Empresa.h"

vector <Categoria*> Categoria::categorialist;
Categoria::Categoria()
{
  if(!Empresa::getEmpresa()->getAcesso("Categoria.Categoria"))
  {
    throw "Acesso negado a Categoria.Categoria";
  }
  else
  {
    this->novaCategoria(this);
  }
}

Categoria::Categoria(string t)
{
  if(!Empresa::getEmpresa()->getAcesso("Categoria.Categoria"))
  {
    throw "Acesso negado a Categoria.Categoria";
  }
  else
  {
    this->setTipo(t);
    this->novaCategoria(this);
  }
}

Categoria::~Categoria()
{
}

string Categoria::getTipo()
{
  if(!Empresa::getEmpresa()->getAcesso("Categoria.getTipo"))
  {
    throw "Acesso negado a Categoria.getTipo";
  }
  else
  {
    return this->tipo;
  }
}

void Categoria::setTipo(string t)
{
  this->tipo = t;
  
}
void Categoria::novaCategoria(Categoria* nova){
  if(!Empresa::getEmpresa()->getAcesso("Categoria.novaCategoria"))
  {
    throw "Acesso negado a Categoria.novaCategoria";
  }
  else
  {
    categorialist.push_back(nova);
  }
}
Categoria* Categoria::getCategoria(string t){
  if(!Empresa::getEmpresa()->getAcesso("Categoria.getCategoria"))
  {
    throw "Acesso negado a Categoria.getCategoria";
  }
  else
  {
    for(auto it : categorialist){
            if(it->getTipo() == t){
                return it;
            }
        }
    return nullptr;
  }
}