#ifndef USUARIOLOGADO_H_INCLUDED
#define USUARIOLOGADO_H_INCLUDED
#include "../include/Usuario.h"

class UsuarioLogado{
    private:
        static UsuarioLogado* usuarioLogado;
        UsuarioLogado();
        Usuario* usuario;
    public:
        static UsuarioLogado* getUsuarioLogado();
        void setUsuario(Usuario* valUsuario);
        Usuario* getUsuario();
};
#endif //USUARIOLOGADO_H_INCLUDED