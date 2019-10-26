#include "boate.h"

using namespace std;

Boate::Boate(int i, string n, Usuario* d, int c, int q, int hi, int hf) : 
                                            EventoAdulto(i, n, d, c, q) {
    hora_inicio = hi;
    hora_fim = hf;
}

Boate::Boate(int i, string n, Usuario* d, int c,
             vector<int> ca, vector<int> p, int q,
             int hi, int hf) :
                                            EventoAdulto(i, n, d, c, ca, p, q){
    hora_inicio = hi;
    hora_fim = hf;
}
