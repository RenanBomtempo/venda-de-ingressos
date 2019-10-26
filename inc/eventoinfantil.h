#ifndef EVENTO_INFANTIL_H
#define EVENTO_INFANTIL_H

#include <evento.h>

using namespace std;

class EventoInfantil : public Evento{
    public:
        EventoInfantil(int i, string n, Usuario* d, int c);
        EventoInfantil(int i, string n, Usuario* d, int c,
                       vector<int> ca, vector<int> p);
}

#endif//EVENTO_INFANTIL_H
