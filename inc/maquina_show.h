#ifndef MAQUINA_SHOW_H
#define MAQUINA_SHOW_H

#include "totem.h"
#include "show.h"
#include <vector>

class MaquinaShow : Totem{
    private:
        int qtd_ingressos;
        Show* ev_escolha;
        std::vector<Show*> eventos;
    public:
        MaquinaShow(std::vector<Evento*> evs, Usuario* us);
        void mostra_maquina();
        int calcula_preco_total();
        string mostra_ingressos_disponiveis(Show* evento);
        Show* acha_evento_por_id(int id);
        int total_de_ingressos();
        string realiza_compra(int preco_total);
};

#endif
