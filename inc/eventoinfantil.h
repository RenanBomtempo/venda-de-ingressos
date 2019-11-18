#ifndef EVENTO_INFANTIL_H
#define EVENTO_INFANTIL_H


#include "evento.h"
#include "usuario.h"
#include <string>
#include <vector>

using namespace std;

enum sub_categoria_infantil {
    FANTOCHE
};

class EventoInfantil : public Evento{
    private:
        int sub_categoria;
    public:
        EventoInfantil(int i, string n, Usuario* d, int sc);
        EventoInfantil(int i, string n, Usuario* d, int sc,
                       vector<int> ca, vector<int> p);
        int get_sub_categoria() override;
};

#endif//EVENTO_INFANTIL_H
