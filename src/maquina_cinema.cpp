#include "maquina_cinema.h"
#include "cinema.h"
#include <algorithm>
#include <vector>
#include <sstream>

MaquinaCinema::MaquinaCinema(std::vector<Evento*> evs, Usuario* us) : Totem(us){
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
    std::cout << "----------------------Máquina de ingressos----------------------" << std::endl;
    std::cout << "----------------------------Cinema------------------------------" << std::endl << std::endl;
    for(Cinema* evento : eventos){
        std::cout << evento->get_id() << " - "<< evento->get_nome() << ":" << std::endl;
        std::cout << "\tDuracao: " << evento->get_duracao() << " horas" << std::endl;
        std::cout << "\tIngressos disponiveis:" << std::endl;
        std::cout << mostra_ingressos_disponiveis(evento);
        std::cout << mostra_horarios(evento);
    }
    std::cout << std::endl << std::endl << "----------------------------------------------------------------" << std::endl;
    int id_escolha;
    std::cout << "Digite o id do evento escolhido ou o número -1 caso deseje voltar ao menu anterior." << std::endl;
    std::cin >> id_escolha;
    if(id_escolha == -1){
        return;
    }else{
        ev_escolha = acha_evento_por_id(id_escolha);
        if(ev_escolha == nullptr){
            std::cout << "ERRO: Por favor, escolha um id valido." << std::endl;
            mostra_maquina();
            return;
        }
    }

    int hor_escolhido;
    std::cout << "Escolha um horario para ver o filme." << std::endl;
    std::cin >> hor_escolhido;
    if (hor_escolhido < 1 || hor_escolhido > acha_evento_por_id(id_escolha)->get_horarios().size()) {
        std::cout << "Horario invalido." << std::endl;
        mostra_maquina();
        return;
    }

    std::cout << "Digite a quantidade de ingressos que deseja comprar." << std::endl;
    std::cin >> qtd_ingressos;
    if(qtd_ingressos < 0 || qtd_ingressos > total_de_ingressos()){
        std::cout << "Numero de ingressos inválido." << std::endl;
        mostra_maquina();
        return;
    }

    int preco = calcula_preco_total();
    std::cout << "O custo total e: " << preco << std::endl;
    std::cout << "Confirmar compra? (S ou N)" << std::endl;
    
    std::string confirma;
    std::cin >> confirma;
    if (confirma == "S" || confirma == "s"){
        std::cout << realiza_compra(preco);
        return;
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
        result << "\t\tLote #" << i+1 << ": " << std::endl;
        result << "\t\t\tQuantidade disponivel: " << cap[i] << std::endl;
        result << "\t\t\tPreco: " << prec[i] << std::endl;
    }

    return result.str();
}

string MaquinaCinema::mostra_horarios(Cinema* evento){
    vector<int> horarios = evento->get_horarios();
    stringstream result;

    result << "\tHorarios:" << std::endl;
    for(size_t i = 0; i < horarios.size(); i++){
        result << "\t\t" << i+1 << ". " << horarios[i] << "h" << std::endl;
    }

    return result.str();
}

int MaquinaCinema::calcula_preco_total(){
    vector<int> cap = ev_escolha->get_capacidades();
    vector<int> prec = ev_escolha->get_precos();
    int min_index;
    int total = 0;
    int i = 0;
    int aux_qtd = qtd_ingressos;
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
    qtd_ingressos = aux_qtd;
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

string MaquinaCinema::realiza_compra(int preco_total){
    std::string result = get_usuario()->gasta_saldo(preco_total);
    if(result == "Pagamento efetuado com sucesso.\n"){
        ev_escolha->gasta_ingressos(qtd_ingressos);
    }
    qtd_ingressos = 0;
    return result;
}