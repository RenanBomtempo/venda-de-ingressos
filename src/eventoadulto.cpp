#include "eventoadulto.h"

using namespace std;

EventoAdulto::EventoAdulto(int i, string n, Usuario* d, int q, int sc) :
                                                Evento(i, n, d, E_ADULTO){
    quota_idoso = q;
    sub_categoria = sc;
}

EventoAdulto::EventoAdulto(int i, string n, Usuario* d,
                           vector<int> ca, vector<int> p, int q, int sc) :
                                                Evento(i, n, d, E_ADULTO, ca, p){
    quota_idoso = q;
    sub_categoria = sc;

}

int EventoAdulto::get_sub_categoria(){
    return sub_categoria;
}

int EventoAdulto::get_quota_idoso() {
    return quota_idoso;
}
