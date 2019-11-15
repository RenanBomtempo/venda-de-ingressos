#include "maquina_boate.h"
#include <algorithm>
#include <vector>

using namespace std;

MaquinaBoate::MaquinaBoate(std::vector<Evento*> evs){
    eventos = evs;
}

void MaquinaBoate::mostra_maquina(){
    cout << "----------------------Máquina de ingressos----------------------" << endl;
    cout << "-----------------------------Boates-----------------------------" << endl << endl;
    for(auto evento: eventos){
        cout << evento->get_id() << " - "<< evento->get_nome() << ":" << endl;
        cout << "\tIngressos disponiveis:" << endl;
        mostra_ingressos_disponiveis(evento);
    }
    cout << endl << endl << "----------------------------------------------------------------" << endl;
    int id_escolha;
    cout << "Digite o id do evento escolhido ou o número -1 caso deseje voltar ao menu anterior." << endl;
    cin >> id_escolha;
    if(id_escolha == -1){
        return;
    }else{
        Evento* ev_escolha = acha_evento_por_id(id_escolha);
        if(ev_escolha == nullptr){
            cout << "Por favor, escolha um id valido." << endl;
            mostra_maquina();
            return;
        }
    }
    cout << "Digite a quantidade de ingressos que deseja comprar." << endl;
    int qtd_ingressos;
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

void MaquinaBoate::mostra_ingressos_disponiveis(Evento* evento){
    vector<int> cap = evento->get_capacidades();
    vector<int> prec = evento->get_precos();

    for(int i = 0; i < cap.size(); i++){
        cout << "\t\tLote #" << i << ": " << endl;
        cout << "\t\t\tQuantidade disponivel: " << cap[i] << endl;
        cout << "\t\t\tPreco: " << prec[i] << endl;
    }

    cout << endl << "\t\tQuota de idosos: " << evento->get_quota_idoso() << endl;
}

int calcula_preco_total(){
    vector<int> cap = ev_escolha->get_capacidades();
    vector<int> prec = ev_escolha->get_precos();
    int min_index;
    std::vector<int>::iterator it;
    int total;
    while(qtd_ingressos > 0){
        min_index = min_element(prec.begin(),prec.end()) - prec.begin();
        if(cap[min_index] > 0){
            if(qtd_ingressos >= cap[min_index]){
                qtd_ingressos-=cap[min_index];
                total += cap[min_index]*prec[min_index];
            }else{
                cap[min_index]-=qtd_ingressos;
                total += qtd_ingressos*prec[min_index];
                qtd_ingressos = 0;
            }
        }
        if(cap[min_index] == 0){
            it = precos.begin();
            precos.erase(it+min_index);
            it = capacidades.begin();
            capacidades.erase(it+min_index);
        }
    }
}
