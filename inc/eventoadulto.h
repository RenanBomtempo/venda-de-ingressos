#ifndef EVENTO_ADULTO_H
#define EVENTO_ADULTO_H

#include <evento.h>
#include <usuario.h>

using namespace std;

class EventoAdulto : public Evento{
    private:
        int quota_idoso;
        int sub_categoria;
    public:
        EventoAdulto(int i, string n, Usuario* d, int q, int sc);
        EventoAdulto(int i, string n, Usuario* d,
                     vector<int> ca, vector<int> p, int q, int sc);
        int get_sub_categoria();
};

#endif//EVENTO_ADULTO_H
