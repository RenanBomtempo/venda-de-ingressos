#ifndef MAQUINA_H
#define MAQUINA_H

#include "evento.h"

class Maquina{
    private:
        Evento* evento;
    public:
        Maquina(Evento* ev);
        virtual void mostra_maquina();
        virtual vector<int> calcula_precos();
        virtual int verifica_disponibilidade();
}

#endif
