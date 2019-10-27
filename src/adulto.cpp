#include "adulto.h"

using namespace std;

Adulto::Adulto() : Usuario(0, "", 0, 0, -1){
}

Adulto::Adulto(int i, string n, int idad, float s) : Usuario(i, n, idad, s, ADULTO){
}

Adulto::Adulto(int i, string n, int idad, float s, int t)  : Usuario(i, n, idad, s, t){
}

vector<Crianca*> Adulto::get_dependentes(){
    return dependentes;
}

void Adulto::add_dependente(Crianca* d){
    dependentes.push_back(d);
}

void Adulto::imprime(){
    cout << "Id: " << this->get_id() << endl;
    cout << "Nome: " << this->get_nome() << endl;
    cout << "Idade: " << this->get_idade() << endl;
    cout << "Saldo: R$" << this->get_saldo() << ",00" << endl;
    cout << "Tipo: " << this->get_tipo() << endl;
    cout << "Dependentes:" << endl;
    for(auto d : dependentes)
        cout << "- " << d->get_nome() << " (" << d->get_id() << ")" << endl;
    cout << endl;
}
