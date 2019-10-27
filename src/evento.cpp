#include "evento.h"

using namespace std;

Evento::Evento(int i, string n, Usuario* d, int c){
    id = i;
    nome = n;
    dono = d;
    categoria = c;
}

Evento::Evento(int i, string n, Usuario* d, int c, vector<int> ca, vector<int> p) : Evento(i, n, d, c){
    capacidades = ca;
    precos = p;
}

int Evento::getCategoria() {
    return categoria;
}

void Evento::add_ingresso(int c, int p){
    capacidades.push_back(c);
    precos.push_back(p);
}
