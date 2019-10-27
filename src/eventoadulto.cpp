#include "eventoadulto.h"

using namespace std;

EventoAdulto::EventoAdulto(int i, string n, Usuario* d, int q, int sc) :
                                                Evento(i, n, d, 2){
    quota_idoso = q;
    sub_categoria = sc;
}

EventoAdulto::EventoAdulto(int i, string n, Usuario* d,
                           vector<int> ca, vector<int> p, int q, int sc) :
                                                Evento(i, n, d, 2, ca, p){
    quota_idoso = q;
    sub_categoria = sc;

}

int EventoAdulto::get_sub_categoria(){
    return sub_categoria;
}
