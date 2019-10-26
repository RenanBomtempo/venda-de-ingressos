#ifndef SHOW_H
#define SHOW_H

#include <eventoadulto.h>
#include <usuario.h>
#include <vector>
#include <string>

using namespace std;

class Show : public EventoAdulto{
    private:
        int abertura_portoes;
        vector<string> artistas;
    public:
        Show(int i, string n, Usuario* d, int c, int q, int ap);
        Show(int i, string n, Usuario* d, int c,
             vector<int> ca, vector<int> p, int q,
             int ap)
        Show(int i, string n, Usuario* d, int c,
             vector<int> ca, vector<int> p, int q,
             int ap, vector<string> ar);
        void add_artista(string ar);
}

#endif//SHOW_H
