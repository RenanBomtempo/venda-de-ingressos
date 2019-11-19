#include "cinema.h"

using namespace std;

Cinema::Cinema(int i, string n, Usuario* d, int du) :
                                            Evento(i, n, d, CINEMA){
    duracao = du;
}

Cinema::Cinema(int i, string n, Usuario* d,
               vector<int> ca, vector<int> p, int du) :
                                            Evento(i, n, d, CINEMA, ca, p){
    duracao = du;
}

Cinema::Cinema(int i, string n, Usuario* d,
               vector<int> ca, vector<int> p, int du,
               vector<int> h) :
                                            Cinema(i, n, d, ca, p, du){
    horarios = h;
}

void Cinema::add_horario(int h){
    horarios.push_back(h);
}

int Cinema::get_duracao() {
    return duracao;
}

std::vector<int> Cinema::get_horarios() {
    return horarios;
}

void Cinema::gasta_ingressos(int qtd){
    vector<int> cap = get_capacidades();
    vector<int> pre = get_precos();

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