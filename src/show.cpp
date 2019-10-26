#include "show.h"

using namespace std;

Show::Show(int i, string n, Usuario* d, int c, int q, int ap) :
                                            EventoAdulto(i, n, d, c, q){
    abertura_portoes = ap;
}

Show::Show(int i, string n, Usuario* d, int c,
           vector<int> ca, vector<int> p, int q,
           int ap) :
                                            EventoAdulto(i, n, d, c, ca, p, q){
    abertura_portoes = ap;
}

Show::Show(int i, string n, Usuario* d, int c,
           vector<int> ca, vector<int> p, int q,
           int ap, vector<string> ar) :
                                            Show(i, n, d, c, ca, p, q, ap){
    artistas = ar;
}

void Show::add_artista(string ar){
    artistas.push_back(ar);
}
