#ifndef EVENTO_ADULTO_H
#define EVENTO_ADULTO_H


#include "evento.h"
#include "usuario.h"
#include <string>
#include <vector>

using namespace std;

enum sub_categoria_adulto {
    SHOW, BOATE
};

class EventoAdulto : public Evento{
    private:
        int quota_idoso;
        int sub_categoria;
    public:
        EventoAdulto(int i, string n, Usuario* d, int q, int sc);
        EventoAdulto(int i, string n, Usuario* d,
                     vector<int> ca, vector<int> p, int q, int sc);
        int get_sub_categoria() override;
        int get_quota_idoso();
        void gasta_ingressos(Usuario* us, int qtd);
};

#endif//EVENTO_ADULTO_H
