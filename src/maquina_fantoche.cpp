#include "maquina_fantoche.h"
#include <sstream>

MaquinaFantoche::MaquinaFantoche(std::vector<TeatroFantoche*> evs, Usuario* us) : Maquina(us){
    std::vector<TeatroFantoche*> vetor_fantoches;

    for(Evento* evento : evs) {
        switch (evento->get_categoria()) {
            case E_INFANTIL:
                switch (evento->get_sub_categoria()) {
                    case FANTOCHE:
                        vetor_fantoches.push_back(dynamic_cast<TeatroFantoche*>(evento));
                        break;
                }
            default:
                break;
        }
    }
    eventos = vetor_fantoches;
    ev_escolha = nullptr;
    qtd_ingressos = 0;
}

void MaquinaFantoche::mostra_maquina(){
    cout << "----------------------Máquina de ingressos----------------------" << endl;
    cout << "-----------------------Teatro de Fantoches-----------------------" << endl << endl;
    for(auto evento: eventos){
        cout << evento->get_id() << " - "<< evento->get_nome() << ":" << endl;
        cout << "\tIngressos disponiveis:" << endl;
        cout << mostra_ingressos_disponiveis(evento);
    }
    cout << endl << endl << "----------------------------------------------------------------" << endl;
    int id_escolha;
    cout << "Digite o id do evento escolhido ou o número -1 caso deseje voltar ao menu anterior." << endl;
    cin >> id_escolha;
    if(id_escolha == -1){
        return;
    }else{
        ev_escolha = acha_evento_por_id(id_escolha);
        if(ev_escolha == nullptr){
            cout << "Por favor, escolha um id valido." << endl;
            mostra_maquina();
            return;
        }

        int cr_escolha;
        cout << "Lista de seus dependentes" << endl;
        Usuario* us = get_usuario();
        Adulto* ad = (Adulto*)(us);

        for (Crianca* dep : ( ad )->get_dependentes() ) {
            cout << dep->get_nome() << " " << dep->get_id();
        }
        cout << "Digite o ID do seu dependente de escolha: " << endl;
        cin >> cr_escolha;
        while ( acha_crianca_por_id(cr_escolha) == nullptr ) {
            cout << "Digite um ID de um dependente valido: ";
            cin >> cr_escolha;
        }

        cout << "Digite a quantidade de ingressos que deseja comprar." << endl;
        cin >> qtd_ingressos;
        if(qtd_ingressos < 0 || qtd_ingressos > total_de_ingressos()){
            cout << "Numero de ingressos inválido." << endl;
            mostra_maquina();
            return;
        }
        std::string confirma;

        cout << "O custo total e: " << calcula_preco_total() << endl;
        cout << "Confirmar compra? (S ou N)" << endl;
        cin >> confirma;
        if (confirma == "S" || confirma == "s"){

        }else{
            mostra_maquina();
            return;
        }
}

std::string MaquinaFantoche::mostra_ingressos_disponiveis(TeatroFantoche* evento){
    vector<int> cap = evento->get_capacidades();
    vector<int> prec = evento->get_precos();
    stringstream result;

    for(size_t i = 0; i < cap.size(); i++){
        result << "\t\tLote #" << i+1 << ": " << endl;
        result << "\t\t\tQuantidade disponivel: " << cap[i] << endl;
        result << "\t\t\tPreco: " << prec[i] << endl;
    }

    result << endl << "\t\tQuota de idosos: " << evento->get_quota_idoso() << endl;
    return result.str();
}

TeatroFantoche* MaquinaFantoche::acha_evento_por_id(int id){
    for(auto evento : eventos){
        if(evento->get_id()==id){
            return evento;
        }
    }
    return nullptr;
}

Crianca* MaquinaFantoche::acha_crianca_por_id(int i){
    for( Crianca* cr : (get_usuario())->get_dependentes() ) {
        if (cr->get_id() == i) {
            return cr;
        }
    }
    return nullptr;
}
