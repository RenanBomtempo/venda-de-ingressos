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
