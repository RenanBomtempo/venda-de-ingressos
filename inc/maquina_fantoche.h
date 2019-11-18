#ifndef MAQUINA_FANTOCHE_H
#define MAQUINA_FANTOCHE_H

#include "maquina.h"
#include <vector>
#include "teatrofantoche.h"

class MaquinaFantoche : Maquina {
    private:
        int qtd_ingressos;
        TeatroFantoche* ev_escolha;
        std::vector<TeatroFantoche*> eventos;
        Crianca* dependente;
    public:
        MaquinaFantoche(std::vector<TeatroFantoche*> evs, Usuario* us);
        void mostra_maquina();
        int calcula_preco_total();
        std::string mostra_ingressos_disponiveis();
        TeatroFantoche* acha_evento_por_id(int id);
        int total_de_ingressos();
};

#endif //MAQUINA_TEATROFANTOCHE_H
