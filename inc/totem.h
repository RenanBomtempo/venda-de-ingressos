#ifndef MAQUINA_H
#define MAQUINA_H

#include "usuario.h"
#include <vector>

class Totem {
    private:
        Usuario* usuario;
    public:
        Totem(Usuario* us);
        virtual void mostra_maquina() = 0;
        virtual int calcula_preco_total() = 0;
        virtual int total_de_ingressos() = 0;
        Usuario* get_usuario();
};

#endif
