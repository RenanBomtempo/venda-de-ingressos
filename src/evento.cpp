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

vector<int> Evento::get_capacidades() {
    return capacidades;
}
vector<int> Evento::get_precos() {
    return precos;
}

Usuario *Evento::get_dono() {
    return dono;
}

string Evento::get_nome() {
    return nome;
}

int Evento::get_categoria() {
    return categoria;
}

int Evento::get_id() {
    return id;
}

void Evento::add_ingresso(int c, int p){
    capacidades.push_back(c);
    precos.push_back(p);
}
