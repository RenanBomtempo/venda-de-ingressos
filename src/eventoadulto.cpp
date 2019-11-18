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


void EventoAdulto::gasta_ingressos(Usuario* us, int qtd){
    switch (us->get_tipo()) {
        case IDOSO:
            if(quota_idoso > qtd){
                quota_idoso -= qtd;
            }else{
                quota_idoso = 0;
            }
            break;
        default:
            break;
    }
    vector<int> cap = get_capacidades();
    vector<int> pre = get_precos();
    int aux;
    for(int i = 0; i < cap.size(); i++){
        if(cap[i] > qtd){
            gasta_capacidades(i, qtd);
            return;
        }else{
            gasta_capacidades(i, cap[i]);
        }
    }
    return;
}
