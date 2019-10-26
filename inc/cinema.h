#ifndef CINEMA_H
#define CINEMA_H

#include <evento.h>
#include <usuario.h>

using namespace std;

class Cinema : public Evento{
    private:
        vector<int> horarios;
        int duracao;
    public:
        Cinema(int i, string n, Usuario* d, int c, int d);
        Cinema(int i, string n, Usuario* d, int c,
               vector<int> ca, vector<int> p, int d);
        Cinema(int i, string n, Usuario* d, int c,
               vector<int> ca, vector<int> p, int d,
               vector<int> h);
        void add_horario(int h);
}

#endif//CINEMA_H
