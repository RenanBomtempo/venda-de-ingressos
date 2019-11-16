#include "crianca.h"

using namespace std;

Crianca::Crianca(int i, string n, int idad, float s, Adulto* r) : Usuario(i, n, idad, s, CRIANCA){
    responsavel = r;
    r->add_dependente(this);
}

Adulto* Crianca::get_responsavel(){
    return responsavel;
}

void Crianca::imprime() {
    cout << "Id: " << get_id() << endl;
    cout << "Nome: " << get_nome() << endl;
    cout << "Idade: " << get_idade() << endl;
    cout << "Saldo: R$" << get_saldo() << endl;
    cout << "Categoria: Crianca\n";
    cout << "Responsavel: " << get_responsavel()->get_id() << endl;
}
