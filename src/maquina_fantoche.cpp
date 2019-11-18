#include "maquina_fantoche.h"

MaquinaFantoche::MaquinaFantoche(std::vector<TeatroFantoche*> evs, Usuario* us){
    eventos = evs;
    usuario = us;
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

std::string mostra_ingressos_disponiveis(){

}

TeatroFantoche* acha_evento_por_id(int id){

}
