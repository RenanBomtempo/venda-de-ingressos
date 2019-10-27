#ifndef USUARIO_H
#define USUARIO_H

#include "initialize_classes.h"
#include "usuario.h"
#include <iostream>
#include <string>

using namespace std;

enum tipo {
    CRIANCA, ADULTO, IDOSO
};

class Usuario {
    private:
        int id;
        std::string nome;
        int idade;
        float saldo;
        int tipo;
    public:
        Usuario(int i, string n, int idad, float s, int t);
        virtual ~Usuario();
        int get_id();
        string get_nome();
        int get_idade();
        float get_saldo();
        int get_tipo();
        virtual void imprime();
};

#endif//USUARIO_H
