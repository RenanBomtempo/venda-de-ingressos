#include "cinema.h"

using namespace std;

Cinema::Cinema(int i, string n, Usuario* d, int c, int dur) :
                                            Evento(i, n, d, c){
    duracao = dur;
}

Cinema::Cinema(int i, string n, Usuario* d, int c,
               vector<int> ca, vector<int> p, int dur) :
                                            Evento(i, n, d, c, ca, p){
    duracao = dur;
}

Cinema::Cinema(int i, string n, Usuario* d, int c,
               vector<int> ca, vector<int> p, int dur,
               vector<int> h) :
                                            Cinema(i, n, d, c, ca, p, dur){
    horarios = h;
}

void Cinema::add_horario(int h){
    horarios.push_back(h);
}
