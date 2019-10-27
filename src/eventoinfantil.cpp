#include "eventoinfantil.h"

EventoInfantil::EventoInfantil(int i, string n, Usuario* d, int sc) :
                                                Evento(i, n, d, 1){
    sub_categoria = sc;
}

EventoInfantil::EventoInfantil(int i, string n, Usuario* d, int sc,
               vector<int> ca, vector<int> p) :
                                                Evento(i, n, d, 1, ca, p){
    sub_categoria = sc;
}

int EventoInfantil::get_sub_categoria(){
    return sub_categoria;
}
