#ifndef MAQUINA_BOATE_H
#define MAQUINA_BOATE_H

#include "maquina.h"

class MaquinaBoate : Maquina{
    MaquinaBoate(std::vector<Evento*> evs);
    void mostra_maquina();
    int calcula_preco_total();
    void mostra_ingressos_disponiveis(Evento* evento);
}

#endif
