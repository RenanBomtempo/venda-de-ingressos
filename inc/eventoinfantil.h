#ifndef EVENTO_INFANTIL_H
#define EVENTO_INFANTIL_H

#include "initialize_classes.h"
#include "evento.h"
#include "usuario.h"
#include <string>
#include <vector>

using namespace std;

class EventoInfantil : public Evento{
    public:
        EventoInfantil(int i, string n, Usuario* d, int c);
        EventoInfantil(int i, string n, Usuario* d, int c,
                       vector<int> ca, vector<int> p);
};

#endif//EVENTO_INFANTIL_H
