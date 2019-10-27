#include "crianca.h"

using namespace std;

Crianca::Crianca(int i, string n, int idad, float s, Adulto* r) : Usuario(i, n, idad, s, CRIANCA){
    responsavel = r;
    r->add_dependente(this);
}

Adulto* Crianca::get_responsavel(){
    return responsavel;
}
