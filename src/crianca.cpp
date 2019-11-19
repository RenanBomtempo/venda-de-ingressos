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
    cout << "\tId: " << get_id() << endl;
    cout << "\tNome: " << get_nome() << endl;
    cout << "\tIdade: " << get_idade() << endl;
    cout << "\tSaldo: R$" << get_saldo() << endl;
    cout << "\tNumero de ingressos comprados: " << get_ingressos_comprados() << endl;
    cout << "\tCategoria: Crianca\n";
    cout << "\tResponsavel: " << get_responsavel()->get_id() << endl;
}
