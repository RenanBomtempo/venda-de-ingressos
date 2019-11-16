#ifndef MAQUINA_H
#define MAQUINA_H

#include "evento.h"
#include <vector>

class Maquina{
    private:
        Usuario* usuario;
    public:
        Maquina(Usuario* us);
        virtual void mostra_maquina(){};
        virtual int calcula_preco_total(){};
        virtual int total_de_ingressos(){};
};

#endif
