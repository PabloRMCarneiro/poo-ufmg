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
    LogLeitura *logLeitura = new LogLeitura("usuarioLogado", "UsuarioLogado");
    return usuarioLogado;
}

void UsuarioLogado::setUsuario(Usuario* valUsuario){
    this->usuario = valUsuario;
}

Usuario* UsuarioLogado::getUsuario() {
    LogLeitura *logLeitura = new LogLeitura("usuario", "UsuarioLogado");
    return this->usuario;
}

bool UsuarioLogado::getAcesso(string valFuncoes) {
    return this->usuario->getPermissoes(valFuncoes);
}