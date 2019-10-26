#include "cinema.h"

using namespace std;

Cinema::Cinema(int i, string n, Usuario* d, int c, int d) :
                                            Evento(i, n, d, c){
    duracao = d;
}

Cinema::Cinema(int i, string n, Usuario* d, int c,
               vector<int> ca, vector<int> p, int d) :
                                            Evento(i, n, d, c, ca, p){
    duracao = d;
}

Cinema::Cinema(int i, string n, Usuario* d, int c,
               vector<int> ca, vector<int> p, int d,
               vector<int> h) :
                                            Cinema(i, n, d, c, ca, p, d){
    horarios = h;
}

void Cinema::add_horario(int h){
    horarios.push_back(h);
}
