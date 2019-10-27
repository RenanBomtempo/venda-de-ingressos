#include "teatrofantoche.h"

using namespace std;

TeatroFantoche::TeatroFantoche(int i, string n, Usuario* d) :
                                            EventoInfantil(i, n, d, 0){
}

TeatroFantoche::TeatroFantoche(int i, string n, Usuario* d,
                               vector<int> ca, vector<int> p) :
                                            EventoInfantil(i, n, d, 0, ca, p){
}

TeatroFantoche::TeatroFantoche(int i, string n, Usuario* d,
                               vector<int> ca, vector<int> p,
                               vector<int> h) :
                                            EventoInfantil(i, n, d, 0, ca, p){
    horarios = h;
}

void TeatroFantoche::add_horario(int h){
    horarios.push_back(h);
}
