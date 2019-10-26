#include "crianca.h"

using namespace std;

Crianca::Crianca(int i, string n, int idad, float s, Adulto* r) : Usuario(i, n, idad, s, 0){
    responsavel = r;
    r->add_dependente(this);
}

Adulto* Crianca::get_responsavel(){
    return responsavel;
}

void Crianca::imprime() : Usuario::imprime(){
    cout << "Responsavel: " << responsavel->get_nome() << " (" <<
                               responsavel->get_id() << ")" << endl;
}
