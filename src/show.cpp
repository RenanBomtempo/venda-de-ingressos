#include "show.h"

using namespace std;

Show::Show(int i, string n, Usuario* d, int q, int ap) :
                                            EventoAdulto(i, n, d, q, SHOW){
    abertura_portoes = ap;
}

Show::Show(int i, string n, Usuario* d,
           vector<int> ca, vector<int> p, int q,
           int ap) :
                                            EventoAdulto(i, n, d, ca, p, q, SHOW){
    abertura_portoes = ap;
}

Show::Show(int i, string n, Usuario* d,
           vector<int> ca, vector<int> p, int q,
           int ap, vector<string> ar) :
                                            Show(i, n, d, ca, p, q, ap){
    artistas = ar;
}

void Show::add_artista(string ar){
    artistas.push_back(ar);
}
