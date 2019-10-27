#include "saida.h"
#include <list>
#include <string>
#include <iostream>
#include <iomanip>

#define MAX_INT 0x7fffffff

void gerarSaida (std::vector<Usuario*> usuarios, std::vector<Evento*> eventos) {
    std::cout << setprecision(2) << fixed;

// NUMERO DE USUARIOS
    int num_cri = 0, num_adu = 0, num_ido = 0;

    for (Usuario* u : usuarios) {
        switch (u->get_tipo()) {
            case CRIANCA:
                num_cri++;
                break;

            case ADULTO:
                num_adu++;
                break;

            case IDOSO:
                num_adu++;
                num_ido++;
                break;

            default:
                break;
        }
    }

    std::cout << "Número de usuários:\n";
    std::cout << "Crianças: " << num_cri << "\n";
    std::cout << "Adultos: " << num_adu << "\n";
    std::cout << "Idosos: " << num_ido << "\n\n";

// IDADE DOS USUARIOS
    int idade_min = MAX_INT, idade_max = 0;
    float idade_med = 0;

    for (Usuario* u : usuarios) {
        int idade = u->get_idade();
        
        if (idade_max < idade)
            idade_max = idade;
        if (idade_min > idade)
            idade_min = idade;

        idade_med += idade;
    }

    idade_med /= (float)usuarios.size();

    std::cout << "Número de usuários:\n";
    std::cout << "Mínima: " << idade_min << "\n";
    std::cout << "Máxima: " << idade_max << "\n";
    std::cout << "Média: " << idade_med << "\n\n";

// NUMERO DE DEPENDENTES
    int num_dep_min = MAX_INT, num_dep_max = 0;
    float num_dep_med = 0;

    for (Usuario* u : usuarios) {
        if (u->get_tipo() >= ADULTO) {
            int num_dep = dynamic_cast<Adulto*>(u)->get_dependentes().size();

            if (num_dep_max < num_dep)
                num_dep_max = num_dep;
            if (num_dep_min > num_dep)
                num_dep_min = num_dep;

            num_dep_med += num_dep;
        }
    }

    num_dep_med /= (float)num_adu;

    std::cout << "Número de dependentes:\n";
    std::cout << "Mínima: " << num_dep_min << "\n";
    std::cout << "Máxima: " << num_dep_max << "\n";
    std::cout << "Média: " << num_dep_med << "\n\n";

// DEPENDENTES
    std::cout << "Dependentes:\n";
    for (Usuario* u : usuarios) {
        if (u->get_tipo() >= ADULTO) {
            std::vector<Crianca*> dep = (dynamic_cast<Adulto*>(u))->get_dependentes();

            if (!dep.empty()) {
                std::cout << u->get_nome() << " (ID: " << u->get_id() << "):";
                for (Crianca* c : dep)
                    std::cout << " " << c->get_nome() << " (ID: " << c->get_id() << "),";
            
                std::cout << "\n";
            }
        }
    }

    std::cout << "\n";

// NUMERO DE EVENTOS
    int num_boate = 0, num_fantoche = 0, num_show = 0, num_cinema = 0; 
    for (Evento* e : eventos) {
        switch (e->get_categoria()) {
            case BOATE:
                num_boate++;
                break;

            case FANTOCHE:
                num_fantoche++;
                break;

            case SHOW:
                num_show++;
                break;
            
            case CINEMA:
                num_cinema++;
                break;

            default:
                break;
        }        
    }
    
    std::cout << "Número de eventos:\n";
    std::cout << "Adultos:\n";
    std::cout << "    Boate: " << num_boate << "\n";
    std::cout << "    Show: " << num_show << "\n";
    std::cout << "Livres:\n";
    std::cout << "    Cinema: " << num_cinema << "\n";
    std::cout << "Infantis:\n";
    std::cout << "    Teatro de fantoches: " << num_fantoche << "\n\n";

// NUMERO DE EVENTOS QUE O USUARIO POSSUI
    std::cout << "Número de eventos que o usuário possui:\n";
    for (Usuario* u : usuarios) {
        int num_eventos = 0;
        for (Evento* e : eventos) {
            if (e->get_dono()->get_id() == u->get_id())
                num_eventos++;
        }

        if (!num_eventos) continue;

        std::cout << u->get_nome() << " (ID: " << u->get_id() << "): " << num_eventos << "\n";
    }

    std::cout << "\n";
    

// EVENTO COM MAIOR COTA PARA IDOSO
    int quota_max = 0;
    Evento* ev;
    for (Evento* e : eventos) {
        if (e->get_categoria() == SHOW || e->get_categoria() == BOATE) {
            int quota = ((EventoAdulto*)e)->get_quota_idoso();
            if (quota > quota_max) {
                quota_max = quota;
                ev = e;
            }
        }
    }
    
    std::cout << "Evento com maior cota para:\n";
    std::cout << ev->get_nome() << "(ID: " << ev->get_id() << "): " << quota_max << "\n\n";

// NUMERO DE INGRESSOS POR PRECO
    int num_50 = 0, num_100 = 0, num_150 = 0, num_200 = 0, num_250 = 0, num_300 = 0;
    for (Evento* e : eventos) {
        std::vector<int> cap = e->get_capacidades();
        std::vector<int> pre = e->get_precos();

        for (u_int i = 0; i < cap.size(); i++){
            switch (pre[i]) {
                case 50:
                    num_50 += cap[i];
                    break;
                
                case 100:
                    num_100 += cap[i];
                    break;

                case 150:
                    num_150 += cap[i];
                    break; 

                case 200:
                    num_200 += cap[i];
                    break; 

                case 250:
                    num_250 += cap[i];
                    break; 

                case 300:
                    num_300 += cap[i];
                    break; 
            }
        }
    }

    std::cout << "Número de ingreços por preço:\n";
    if (num_50)
        std::cout << "R$50.00: " << num_50 << "\n";
    if (num_100)
        std::cout << "R$100.00: " << num_100 << "\n";
    if (num_150)
        std::cout << "R$150.00: " << num_150 << "\n";
    if (num_200)
        std::cout << "R$200.00: " << num_200 << "\n";
    if (num_250)
        std::cout << "R$250.00: " << num_250 << "\n";
    if (num_300)
        std::cout << "R$300.00: " << num_300 << "\n";
    
}