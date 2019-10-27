#include "cinema.h"

using namespace std;

Cinema::Cinema(int i, string n, Usuario* d, int du) :
                                            Evento(i, n, d, 0){
    duracao = du;
}

Cinema::Cinema(int i, string n, Usuario* d,
               vector<int> ca, vector<int> p, int du) :
                                            Evento(i, n, d, 0, ca, p){
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
