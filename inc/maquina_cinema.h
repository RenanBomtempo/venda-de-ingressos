#ifndef MAQUINA_CINEMA_H
#define MAQUINA_CINEMA_H

#include "totem.h"
#include "cinema.h"
#include <vector>
#include <string>

class MaquinaCinema : public Totem{
    private:
        int qtd_ingressos;
        Cinema* ev_escolha;
        std::vector<Cinema*> eventos;
    public:
        MaquinaCinema(std::vector<Evento*> evs, Usuario* us);
        void mostra_maquina();
        int calcula_preco_total();
        std::string mostra_ingressos_disponiveis(Cinema* evento);
        Cinema* acha_evento_por_id(int id);
        int total_de_ingressos();
        std::string mostra_horarios(Cinema* evento);
        string realiza_compra(int preco_total);
};

#endif
