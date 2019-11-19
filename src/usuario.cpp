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

string Usuario::gasta_saldo(int gasto){
    if(saldo >= gasto){
        saldo -= gasto;
        return "Pagamento efetuado com sucesso.\n";
    }else{
        return "Saldo insuficiente.\n";
    }
}

int Usuario::get_tipo(){
    return tipo;
}

void Usuario::imprime(){
    cout << "\tId: " << id << endl;
    cout << "\tNome: " << nome << endl;
    cout << "\tIdade: " << idade << endl;
    cout << "\tSaldo: R$" << saldo << endl;
    cout << "\tNumero de ingressos comprados: " << num_ing_comprados << endl;
    cout << "\tCategoria: ";
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

void Usuario::incrementar_ingressos_comprados(int qtd) {
    num_ing_comprados += qtd;
}

int Usuario::get_ingressos_comprados() {
    return num_ing_comprados;
}