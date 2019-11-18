#ifndef MAQUINA_CINEMA_H
#define MAQUINA_CINEMA_H

#include "maquina.h"
#include "cinema.h"
#include <vector>

class MaquinaCinema : Maquina{
    private:
        int qtd_ingressos;
        Cinema* ev_escolha;
        std::vector<Cinema*> eventos;
    public:
        MaquinaCinema(std::vector<Evento*> evs, Usuario* us);
        void mostra_maquina();
        int calcula_preco_total();
        string mostra_ingressos_disponiveis(Cinema* evento);
        Cinema* acha_evento_por_id(int id);
        int total_de_ingressos();
};

#endif
