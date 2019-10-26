#include "adulto.h"

using namespace std;

Adulto::Adulto(int i, string n, int idad, float s) : Usuario(i, n, idad, s, 1){
}

Adulto::Adulto(int i, string n, int idad, float s, int t)  : Usuario(i, n, idad, s, t){
}

set<int> Adulto::get_dependentes(){
    return dependentes;
}

void Adulto::add_dependente(int d){
    dependentes.insert(d);
}

void Adulto::remove_dependente(int d){
    for (it = dependentes.begin(); it != dependentes.end(); ++it){
        if (it == d){
            dependentes.erase(it)
        }
    }
}
