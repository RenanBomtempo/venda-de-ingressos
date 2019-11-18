#include "maquina_cinema.h"
#include "cinema.h"
#include <algorithm>
#include <vector>
#include <sstream>

MaquinaCinema::MaquinaCinema(std::vector<Evento*> evs, Usuario* us) : Maquina(us){
    std::vector<Cinema*> vetor_cinema;

    for(Evento* evento : evs) {
        switch (evento->get_categoria()) {
            case CINEMA:
                vetor_cinema.push_back(dynamic_cast<Cinema*>(evento));
                break;
            default:
                break;
        }
    }
    eventos = vetor_cinema;
    ev_escolha = nullptr;
    qtd_ingressos = 0;
}

void MaquinaCinema::mostra_maquina(){
    std::cout << "----------------------Máquina de ingressos----------------------" << endl;
    std::cout << "----------------------------Cinema------------------------------" << endl << endl;
    for(auto evento: eventos){
        std::cout << evento->get_id() << " - "<< evento->get_nome() << ":" << endl;
        std::cout << "\tIngressos disponiveis:" << endl;
        std::cout << mostra_ingressos_disponiveis(evento);
    }
    std::cout << endl << endl << "----------------------------------------------------------------" << endl;
    int id_escolha;
    std::cout << "Digite o id do evento escolhido ou o número -1 caso deseje voltar ao menu anterior." << endl;
    std::cin >> id_escolha;
    if(id_escolha == -1){
        return;
    }else{
        ev_escolha = acha_evento_por_id(id_escolha);
        if(ev_escolha == nullptr){
            std::cout << "ERRO: Por favor, escolha um id valido." << endl;
            mostra_maquina();
            return;
        }
    }
    std::cout << "Digite a quantidade de ingressos que deseja comprar." << endl;
    std::cin >> qtd_ingressos;
    if(qtd_ingressos < 0 || qtd_ingressos > total_de_ingressos()){
        std::cout << "Numero de ingressos inválido." << endl;
        mostra_maquina();
        return;
    }
    std::string confirma;

    std::cout << "O custo total e: " << calcula_preco_total() << endl;
    std::cout << "Confirmar compra? (S ou N)" << endl;
    std::cin >> confirma;
    if (confirma == "S" || confirma == "s"){

    }else{
        mostra_maquina();
        return;
    }
}

string MaquinaCinema::mostra_ingressos_disponiveis(Cinema* evento){
    vector<int> cap = evento->get_capacidades();
    vector<int> prec = evento->get_precos();
    stringstream result;

    for(size_t i = 0; i < cap.size(); i++){
        result << "\t\tLote #" << i+1 << ": " << endl;
        result << "\t\t\tQuantidade disponivel: " << cap[i] << endl;
        result << "\t\t\tPreco: " << prec[i] << endl;
    }

    return result.str();
}

int MaquinaCinema::calcula_preco_total(){
    vector<int> cap = ev_escolha->get_capacidades();
    vector<int> prec = ev_escolha->get_precos();
    int min_index;
    std::vector<int>::iterator it;
    int total = 0;
    int i = 0;
    while(qtd_ingressos > 0){
        if(cap[i] > 0){
            if(qtd_ingressos >= cap[i]){
                qtd_ingressos-=cap[i];
                total += cap[i]*prec[i];
            }else{
                cap[i]-=qtd_ingressos;
                total += qtd_ingressos*prec[i];
                qtd_ingressos = 0;
            }
        }
        i++;
    }
    return total;
}

Cinema* MaquinaCinema::acha_evento_por_id(int id){
    for(auto evento : eventos){
        if(evento->get_id()==id){
            return evento;
        }
    }
    return nullptr;
}

int MaquinaCinema::total_de_ingressos(){
    int total = 0;
    vector<int> caps = ev_escolha->get_capacidades();
    for(int i = 0; i < caps.size(); i++){
        total += caps[i];
    }
    return total;
}
