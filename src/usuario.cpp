#include "usuario.h"

using namespace std;

Usuario::Usuario(int i, string n, int idad, float s, int t){
    id = i;
    nome = n;
    idade = idad;
    saldo = s;
    tipo = t;
    num_ing_comprados = 0;
}

Usuario::~Usuario () {}

int Usuario::get_id(){
    return id;
}

string Usuario::get_nome(){
    return nome;
}

int Usuario::get_idade(){
    return idade;
}

float Usuario::get_saldo(){
    return saldo;
}

int Usuario::gasta_saldo(int gasto){
    if(saldo >= gasto){
        saldo -= gasto;
        return 0;
    }else{
        return 1;
    }
}


int Usuario::get_tipo(){
    return tipo;
}

void Usuario::imprime(){
    cout << "Id: " << id << endl;
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
    cout << "Saldo: R$" << saldo << endl;
    cout << "Categoria: ";
    switch (tipo) {
    case ADULTO:
        cout << "Adulto\n";
        break;
    case IDOSO:
        cout << "Idoso\n";
        break;
    default:
        break;
    }
}
