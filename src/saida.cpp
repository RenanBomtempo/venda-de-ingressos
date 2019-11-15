#include "saida.h"
#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

#define MAX_INT 0x7fffffff

void gerarSaida (std::vector<Usuario*> usuarios, std::vector<Evento*> eventos) {
    std::ofstream outfile ("saida.txt");

    outfile << setprecision(2) << fixed;

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

    outfile << "Número de usuários:\n";
    outfile << "Crianças: " << num_cri << "\n";
    outfile << "Adultos: " << num_adu << "\n";
    outfile << "Idosos: " << num_ido << "\n\n";

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

    outfile << "Idade dos usuários:\n";
    outfile << "Mínima: " << idade_min << "\n";
    outfile << "Máxima: " << idade_max << "\n";
    outfile << "Média: " << idade_med << "\n\n";

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

    outfile << "Número de dependentes:\n";
    outfile << "Mínima: " << num_dep_min << "\n";
    outfile << "Máxima: " << num_dep_max << "\n";
    outfile << "Média: " << num_dep_med << "\n\n";

// DEPENDENTES
    outfile << "Dependentes:\n";
    for (Usuario* u : usuarios) {
        if (u->get_tipo() >= ADULTO) {
            std::vector<Crianca*> dep = (dynamic_cast<Adulto*>(u))->get_dependentes();

            if (!dep.empty()) {
                outfile << u->get_nome() << " (ID: " << u->get_id() << "):";
                for (Crianca* c : dep)
                    outfile << " " << c->get_nome() << " (ID: " << c->get_id() << "),";

                outfile << "\n";
            }
        }
    }

    outfile << "\n";

// NUMERO DE EVENTOS
    int num_boate = 0, num_fantoche = 0, num_show = 0, num_cinema = 0;
    for (Evento* e : eventos) {
        switch (e->get_categoria()) {
            case E_ADULTO:
                switch (e->get_sub_categoria()) {
                    case BOATE:
                        num_boate++;
                        break;
                    case SHOW:
                        num_show++;
                        break;
                    default:
                        break;
                }
                break;


            case E_INFANTIL:
                switch (e->get_sub_categoria()) {
                    case FANTOCHE:
                        num_fantoche++;
                        break;
                    default:
                        break;
                }
                break;

            case CINEMA:
                num_cinema++;
                break;

            default:
                break;
        }
    }

    outfile << "Número de eventos:\n";
    outfile << "Adultos:\n";
    outfile << "    Boate: " << num_boate << "\n";
    outfile << "    Show: " << num_show << "\n";
    outfile << "Livres:\n";
    outfile << "    Cinema: " << num_cinema << "\n";
    outfile << "Infantis:\n";
    outfile << "    Teatro de fantoches: " << num_fantoche << "\n\n";

// NUMERO DE EVENTOS QUE O USUARIO POSSUI
    outfile << "Número de eventos que o usuário possui:\n";
    for (Usuario* u : usuarios) {
        int num_eventos = 0;
        for (Evento* e : eventos) {
            if (e->get_dono()->get_id() == u->get_id())
                num_eventos++;
        }

        if (!num_eventos) continue;

        outfile << u->get_nome() << " (ID: " << u->get_id() << "): " << num_eventos << "\n";
    }

    outfile << "\n";


// EVENTO COM MAIOR COTA PARA IDOSO
    int quota_max = 0;
    Evento* ev;
    for (Evento* e : eventos) {
        if (e->get_categoria() == E_ADULTO) {
            int quota = ((EventoAdulto*)e)->get_quota_idoso();
            if (quota > quota_max) {
                quota_max = quota;
                ev = e;
            }
        }
    }

    outfile << "Evento com maior cota para idoso:" << std::endl;
    outfile << ev->get_nome() << "(ID: " << ev->get_id() << "): " << quota_max << "\n\n";

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

    outfile << "Número de ingressos por preço:\n";
    if (num_50)
        outfile << "R$50.00: " << num_50 << "\n";
    if (num_100)
        outfile << "R$100.00: " << num_100 << "\n";
    if (num_150)
        outfile << "R$150.00: " << num_150 << "\n";
    if (num_200)
        outfile << "R$200.00: " << num_200 << "\n";
    if (num_250)
        outfile << "R$250.00: " << num_250 << "\n";
    if (num_300)
        outfile << "R$300.00: " << num_300 << "\n";

}
