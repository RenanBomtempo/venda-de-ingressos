#ifndef EVENTO_INFANTIL_H
#define EVENTO_INFANTIL_H

#include <evento.h>

using namespace std;

class EventoInfantil : public Evento{
    private:
        int sub_categoria;
    public:
        EventoInfantil(int i, string n, Usuario* d, int sc);
        EventoInfantil(int i, string n, Usuario* d, int sc,
                       vector<int> ca, vector<int> p);
        int get_sub_categoria();
};

#endif//EVENTO_INFANTIL_H
