#ifndef MAQUINA_BOATE_H
#define MAQUINA_BOATE_H

#include "maquina.h"
#include <vector>
#include "boate.h"

class MaquinaBoate : Maquina{
    private:
        int qtd_ingressos;
        Boate* ev_escolha;
        std::vector<Boate*> eventos;
    public:
        MaquinaBoate(std::vector<Boate*> evs, Usuario* us);
        void mostra_maquina();
        int calcula_preco_total();
        string mostra_ingressos_disponiveis(Boate* evento);
        Boate* acha_evento_por_id(int id);
        int total_de_ingressos();
};

#endif
