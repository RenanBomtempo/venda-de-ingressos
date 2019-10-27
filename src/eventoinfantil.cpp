#include "eventoinfantil.h"

EventoInfantil::EventoInfantil(int i, string n, Usuario* d, int sc) :
                                                Evento(i, n, d, E_INFANTIL){
    sub_categoria = sc;
}

EventoInfantil::EventoInfantil(int i, string n, Usuario* d, int sc,
               vector<int> ca, vector<int> p) :
                                                Evento(i, n, d, E_INFANTIL, ca, p){
    sub_categoria = sc;
}

int EventoInfantil::get_sub_categoria(){
    return sub_categoria;
}
