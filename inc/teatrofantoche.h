#ifndef TEATRO_FANTOCHE_H
#define TEATRO_FANTOCHE_H

#include <eventoinfantil.h>
#include <vector>

using namespace std;

class TeatroFantoche : public EventoInfantil{
    private:
        vector<int> horarios;
    public:
        TeatroFantoche(int i, string n, Usuario* d);
        TeatroFantoche(int i, string n, Usuario* d,
                       vector<int> ca, vector<int> p);
        TeatroFantoche(int i, string n, Usuario* d,
                       vector<int> ca, vector<int> p,
                       vector<int> h);
        void add_horario(int h);
};

#endif//TEATRO_FANTOCHE_H
