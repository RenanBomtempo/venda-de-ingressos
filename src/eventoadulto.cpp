#include "eventoadulto.h"

using namespace std;

EventoAdulto::EventoAdulto(int i, string n, Usuario* d, int c, int q) :
                                                Evento(i, n, d, c){
    quota_idoso = q;
}

EventoAdulto::EventoAdulto(int i, string n, Usuario* d, int c,
                           vector<int> ca, vector<int> p, int q) :
                                                Evento(i, n, d, c, ca, p){
    quota_idoso = q;
}

int EventoAdulto::get_quota_idoso() {
    return quota_idoso;
}