#include "teatrofantoche.h"

using namespace std;

TeatroFantoche::TeatroFantoche(int i, string n, Usuario* d, int c) :
                                            EventoInfantil(i, n, d, c){
}

TeatroFantoche::TeatroFantoche(int i, string n, Usuario* d, int c,
                               vector<int> ca, vector<int> p) :
                                            EventoInfantil(i, n, d, c, ca, p){
}

TeatroFantoche::TeatroFantoche(int i, string n, Usuario* d, int c,
                               vector<int> ca, vector<int> p,
                               vector<int> h) :
                                            EventoInfantil(i, n, d, c, ca, p){
    horarios = h;
}

void TeatroFantoche::add_horario(int h){
    horarios.push_back(h);
}
