#include "eventoinfantil.h"

EventoInfantil::EventoInfantil(int i, string n, Usuario* d, int c) :
                                                Evento(i, n, d, c){
}

Evento::Evento(int i, string n, Usuario* d, int c,
               vector<int> ca, vector<int> p) :
                                                Evento(i, n, d, c, ca, p){
}
