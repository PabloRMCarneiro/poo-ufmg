#include "../include/Categoria.h"
#include "../include/Empresa.h"
#include "../include/PermissaoNegada.h"

vector <Categoria*> Categoria::categorialist;
Categoria::Categoria()
{
  if(!Empresa::getEmpresa()->getAcesso("Categoria.Categoria"))
  {
    throw acessoNegadoCategoria();
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
    throw acessoNegadoCategoria();
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
    throw acessoNegadoTipoCategoria();
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
    throw acessoNegadoNovaCategoria();
  }
  else
  {
    categorialist.push_back(nova);
  }
}
Categoria* Categoria::getCategoria(string t){
  if(!Empresa::getEmpresa()->getAcesso("Categoria.getCategoria"))
  {
    throw acessoNegadoGetCategoria();
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