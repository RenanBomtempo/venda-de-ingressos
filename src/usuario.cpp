#include "usuario.h"

using namespace std;

class Usuario {
    private:
        int id;
        string nome;
        int idade;
        float saldo;
        int tipo;
    public:
        int get_id();
        string get_nome();
        int get_idade();
        float get_saldo();
        int get_tipo();
}

Usuario::Usuario(int i, string n, int idad, float s, int t){
    id = i;
    nome = n;
    idade = idad;
    saldo = s;
    tipo = t;
}

Usuario::get_id(){
    return id;
}

Usuario::get_nome(){
    return nome;
}

Usuario::get_idade(){
    return idade;
}

Usuario::get_saldo(){
    return saldo;
}

Usuario::get_tipo(){
    return tipo;
}
