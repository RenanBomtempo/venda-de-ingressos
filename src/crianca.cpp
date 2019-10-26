#include "crianca.h"

using namespace std;

Crianca::Crianca(int i, string n, int idad, float s, Adulto* r) : Usuario(i, n, idad, s, 0){
    responsavel = r;
    r->add_dependente(this);
}

Adulto* Crianca::get_responsavel(){
    return responsavel;
}

void Crianca::imprime(){ 
    cout << "Id: " << this->get_id() << endl;
    cout << "Nome: " << this->get_nome() << endl;
    cout << "Idade: " << this->get_idade() << endl;
    cout << "Saldo: R$" << this->get_saldo() << ",00" << endl;
    cout << "Tipo: " << this->get_tipo() << endl;
    cout << "Responsavel: " << responsavel->get_nome() << " (" <<
                               responsavel->get_id() << ")" << endl;
    cout << endl;
}
