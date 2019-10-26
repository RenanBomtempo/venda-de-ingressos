#include "adulto.h"

using namespace std;

Adulto::Adulto() : Usuario(0, "", 0, 0, -1){
}

Adulto::Adulto(int i, string n, int idad, float s) : Usuario(i, n, idad, s, 1){
}

Adulto::Adulto(int i, string n, int idad, float s, int t)  : Usuario(i, n, idad, s, t){
}

vector<Crianca> Adulto::get_dependentes(){
    return dependentes;
}

void Adulto::add_dependente(Crianca d){
    dependentes.push_back(d);
}

void Adulto::remove_dependente(int id_d){
    for (int i = 0; i < dependentes.size(); i++){
        if (dependentes[i].get_id() == id_d){
            dependentes.erase(dependentes.begin()+i);
        }
    }
}
