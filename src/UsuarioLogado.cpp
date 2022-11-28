#include "../include/UsuarioLogado.h"
#include "../include/Empresa.h"

UsuarioLogado* UsuarioLogado::usuarioLogado = nullptr;

UsuarioLogado::UsuarioLogado(){

}

UsuarioLogado* UsuarioLogado::getUsuarioLogado(){
    if(usuarioLogado == nullptr)
    {
        usuarioLogado = new UsuarioLogado;
    }
    return usuarioLogado;
}

void UsuarioLogado::setUsuario(Usuario* valUsuario){
    this->usuario = valUsuario;
}

Usuario* UsuarioLogado::getUsuario() {
    return this->usuario;
}

bool UsuarioLogado::getAcesso(string valFuncoes) {
    return this->usuario->getPermissoes(valFuncoes);
}