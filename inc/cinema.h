#ifndef CINEMA_H
#define CINEMA_H

#include "evento.h"
#include <string>
#include <vector>

using namespace std;

class Cinema : public Evento{
    private:
        vector<int> horarios;
        int duracao;
    public:
        Cinema(int i, string n, Usuario* d, int du);
        Cinema(int i, string n, Usuario* d,
               vector<int> ca, vector<int> p, int du);
        Cinema(int i, string n, Usuario* d,
               vector<int> ca, vector<int> p, int du,
               vector<int> h);
        void add_horario(int h);
        int get_duracao();
        vector<int> get_horarios();
        void gasta_ingressos(int qtd);
};

#endif//CINEMA_H
