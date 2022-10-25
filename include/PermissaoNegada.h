#ifndef PERMISSAO_NEGADA_H  
#define PERMISSAO_NEGADA_H

#include <exception>
#include <string>
#include "Categoria.h"

using namespace std;

class acessoNegadoException : public exception {
    public:
        virtual const char *what() const noexcept {
            return "Acesso negado!";
        }
};

class acessoNegadoCargo : public acessoNegadoException {
    public:
        virtual const char *what() const noexcept {
            return "Acesso negado a Cargo.Cargo";
        }
};

class acessoNegadoNomeCargo : public acessoNegadoException {
    public:
        virtual const char *what() const noexcept {
            return "Acesso negado a Cargo.getNome";
        }
};

class acessoNegadoCategoria : public acessoNegadoException {
    public:
        virtual const char *what() const noexcept {
            return "Acesso negado a Categoria.Categoria";
        }
};

class acessoNegadoTipoCategoria : public acessoNegadoException {
    public:
        virtual const char *what() const noexcept {
            return "Acesso negado a Categoria.getTipo";
        }
};

class acessoNegadoNovaCategoria : public acessoNegadoException {
    public:
        virtual const char *what() const noexcept {
            return "Acesso negado a Categoria.novaCategoria";
        }
};

class acessoNegadoGetCategoria : public acessoNegadoException {
    public:
        virtual const char *what() const noexcept {
            return "Acesso negado a Categoria.getCategoria";
        }
};

class acessoNegadoCliente : public acessoNegadoException {
    public:
        virtual const char *what() const noexcept {
            return "Acesso negado a Cliente.Cliente";
        }
};

class acessoNegadoGetCliente : public acessoNegadoException {
    public:
        virtual const char *what() const noexcept {
            return "Acesso negado a Cliente.getTipoCliente";
        }
};

#endif
