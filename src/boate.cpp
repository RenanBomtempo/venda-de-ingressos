#include "boate.h"

using namespace std;

Boate::Boate(int i, string n, Usuario* d, int q, int hi, int hf) :
                                            EventoAdulto(i, n, d, q, BOATE){
    hora_inicio = hi;
    hora_fim = hf;
}

Boate::Boate(int i, string n, Usuario* d,
             vector<int> ca, vector<int> p, int q,
             int hi, int hf) :
                                            EventoAdulto(i, n, d, ca, p, q, BOATE){
    hora_inicio = hi;
    hora_fim = hf;
}
