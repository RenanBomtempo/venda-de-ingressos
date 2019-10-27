#include "show.h"

using namespace std;

Show::Show(int i, string n, Usuario* d, int q, int ap) :
                                            EventoAdulto(i, n, d, c, q, 1){
    abertura_portoes = ap;
}

Show::Show(int i, string n, Usuario* d,
           vector<int> ca, vector<int> p, int q,
           int ap) :
                                            EventoAdulto(i, n, d, c, ca, p, q, 1){
    abertura_portoes = ap;
}

Show::Show(int i, string n, Usuario* d,
           vector<int> ca, vector<int> p, int q,
           int ap, vector<string> ar) :
                                            Show(i, n, d, c, ca, p, q, ap, 1){
    artistas = ar;
}

void Show::add_artista(string ar){
    artistas.push_back(ar);
}
