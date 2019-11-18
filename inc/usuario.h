#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
#include <string>
#include <vector>

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
        int num_ing_comprados;
    public:
        Usuario(int i, string n, int idad, float s, int t);
        virtual ~Usuario();
        int get_id();
        string get_nome();
        int get_idade();
        float get_saldo();
        int get_tipo();
        string gasta_saldo(int gasto);
        virtual void imprime();
};

class Crianca;
class Adulto;
class Idoso;

#endif//USUARIO_H
