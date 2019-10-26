#ifndef CINEMA_H
#define CINEMA_H

#include "initialize_classes.h"
#include "evento.h"
#include <string>
#include <vector>

using namespace std;

class Cinema : public Evento{
    private:
        vector<int> horarios;
        int duracao;
    public:
        Cinema(int i, string n, Usuario* d, int c, int dur);
        Cinema(int i, string n, Usuario* d, int c,
               vector<int> ca, vector<int> p, int dur);
        Cinema(int i, string n, Usuario* d, int c,
               vector<int> ca, vector<int> p, int dur,
               vector<int> h);
        void add_horario(int h);
};

#endif//CINEMA_H
