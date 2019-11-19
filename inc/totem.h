#ifndef MAQUINA_H
#define MAQUINA_H

#include "usuario.h"
#include <vector>

class Totem {
    private:
        Usuario* usuario;
    public:
        Totem(Usuario* us);
        virtual void mostra_maquina(){};
        virtual int calcula_preco_total(){};
        virtual int total_de_ingressos(){};
        Usuario* get_usuario();
};

#endif
