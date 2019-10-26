#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
    private:
        int id;
        string nome;
        int idade;
        float saldo;
        int tipo;
    public:
        Usuario(int i, string n, int idad, float s);
        int get_id();
        string get_nome();
        int get_idade();
        float get_saldo();
        int get_tipo();
}

#endif//USUARIO_H
