#include "maquina_show.h"
#include "show.h"
#include "adulto.h"
#include "idoso.h"
#include <algorithm>
#include <vector>
#include <sstream>

using namespace std;

MaquinaShow::MaquinaShow(std::vector<Evento*> evs, Usuario* us) : Totem(us){
    std::vector<Show*> vetor_shows;

    for(Evento* evento : evs) {
        switch (evento->get_categoria()) {
            case E_ADULTO:
                switch (evento->get_sub_categoria()) {
                    case SHOW:
                        vetor_shows.push_back(dynamic_cast<Show*>(evento));
                        break;
                }
            default:
                break;
        }
    }
    eventos = vetor_shows;
    ev_escolha = nullptr;
    qtd_ingressos = 0;
}

void MaquinaShow::mostra_maquina(){
    cout << "----------------------Máquina de ingressos----------------------" << endl;
    cout << "-----------------------------Shows------------------------------" << endl << endl;
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
            cout << "ERRO: Por favor, escolha um id valido." << endl;
            mostra_maquina();
            return;
        }
    }
    cout << "Digite a quantidade de ingressos que deseja comprar." << endl;
    cin >> qtd_ingressos;
    if(qtd_ingressos < 0 || qtd_ingressos > total_de_ingressos()){
        cout << "Numero de ingressos inválido." << endl;
        mostra_maquina();
        return;
    }
    std::string confirma;
    int preco_total = calcula_preco_total();
    cout << "O custo total e: " << preco_total << endl;
    cout << "Confirmar compra? (S ou N)" << endl;
    cin >> confirma;
    if (confirma == "S" || confirma == "s"){
        cout << realiza_compra(preco_total);
    }else{
        mostra_maquina();
        return;
    }
}

string MaquinaShow::realiza_compra(int preco_total){
    string result = get_usuario()->gasta_saldo(preco_total);
    if(result == "Pagamento efetuado com sucesso.\n"){
        get_usuario()->incrementar_ingressos_comprados(qtd_ingressos);
        ev_escolha->gasta_ingressos(get_usuario(), qtd_ingressos);
        ev_escolha->incrementar_ingressos_vendidos(qtd_ingressos);
    }
    qtd_ingressos = 0;
    return result;
}

string MaquinaShow::mostra_ingressos_disponiveis(Show* evento){
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

int MaquinaShow::calcula_preco_total(){
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

Show* MaquinaShow::acha_evento_por_id(int id){
    for(auto evento : eventos){
        if(evento->get_id()==id){
            return evento;
        }
    }
    return nullptr;
}

int MaquinaShow::total_de_ingressos(){
    int total = 0;
    vector<int> caps = ev_escolha->get_capacidades();
    for(int i = 0; i < caps.size(); i++){
        total += caps[i];
    }
    return total;
}
