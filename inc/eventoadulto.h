#ifndef EVENTO_ADULTO_H
#define EVENTO_ADULTO_H

#include <evento.h>
#include <usuario.h>

using namespace std;

class EventoAdulto : public Evento{
    private:
        int quota_idoso;
    public:
        EventoAdulto(int i, string n, Usuario* d, int c, int q);
        EventoAdulto(int i, string n, Usuario* d, int c,
                     vector<int> ca, vector<int> p, int q);
}

#endif//EVENTO_ADULTO_H
