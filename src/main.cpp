#include "menu.h"
// Usuario
#include "usuario.h"
#include "adulto.h"
#include "crianca.h"
#include "idoso.h"
// Evento
#include "evento.h"
#include "cinema.h"
#include "eventoadulto.h"
#include "show.h"
#include "boate.h"
#include "eventoinfantil.h"
#include "teatrofantoche.h"
// Maquinas de eventos
#include "maquina.h"
#include "maquina_boate.h"
#include "maquina_cinema.h"
#include "maquina_show.h"
#include "maquina_fantoche.h"

// Bibliotecas std
#include "csvprocessor.h"
#include "saida.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void limparDadosCarregados(vector<Usuario*> vetor_usuarios, vector<Evento*> vetor_eventos);
int main(){
    vector<Usuario*> vetor_usuarios;
    vector<Evento*> vetor_eventos;
    string_table usuarios_table = CSVtoStringTable("../data/usuarios.csv");
    string_table eventos_table  = CSVtoStringTable("../data/eventos.csv");
    bool is_dados_carregados = false;

    while (1) {
        exibirMenu();
        switch (lerInput('1', '4')) {
        case 1:
            if (!is_dados_carregados) {
                cout << "CARREGANDO DADOS...\n";
                vetor_usuarios = LerUsuarios(usuarios_table);
                vetor_eventos = LerEventos(eventos_table, vetor_usuarios);
                cout << "----------------------------\n";
                gerarSaida(vetor_usuarios, vetor_eventos);
                cout << "----------------------------\n";
                is_dados_carregados = true;
            } else {
                cout << "ERRO: Os dados de usuarios e eventos ja estao carregados.\n";
                cout << "----------------------------\n";
            }
            break;
        
        case 2:
            if (is_dados_carregados){
                cout << "\nUSUARIOS CADASTRADOS:\n";
                for (Usuario* u : vetor_usuarios){
                    cout << "----------------------------\n";
                    u->imprime();
                }
                
            }
            else {
                cout << "ERRO: Os dados de usuarios e eventos nao foram carregados.\n";
                cout << "----------------------------\n";
                break;
            }
            break;
            
        case 3:
            if (is_dados_carregados){
                int id;
                Usuario* comprador = nullptr;

                cout << "Insira o ID do comprador: ";
                cin >> id;

                for(Usuario* u : vetor_usuarios) {
                    if (u->get_id() == id) {
                        comprador = u;
                        if (u->get_tipo() == CRIANCA) {
                            cout << "ERRO: Apenas ADULTOS e IDOSOS podem comprar ingressos.\n";
                            cout << "----------------------------\n";
                            break;
                        }
                        bool is_comprando = true;
                        while(is_comprando){
                            exibirTelaDeEventos();
                            switch (lerInput('1', '5')) {
                            case 1:
                            {
                                MaquinaCinema maq_cinema(vetor_eventos, comprador);
                                maq_cinema.mostra_maquina();
                            };
                                break;
                            case 2:
                            {
                                MaquinaShow maq_show(vetor_eventos, comprador);
                                maq_show.mostra_maquina();
                            };
                                break;
                            case 3:
                            {
                                MaquinaBoate maq_boate(vetor_eventos, comprador);
                                maq_boate.mostra_maquina();
                            };
                                break;
                            case 4:
                            {
                                //MaquinaFantoche maq_fantoche(vetor_eventos, comprador);
                                //maq_fantoche.mostra_maquina();
                            };
                                break;
                            case 5:
                                is_comprando = false;
                                break;
                            default:
                                break;
                            }
                        }
                    }
                }

                if (comprador == nullptr) {
                    cout << "ERRO: O ID inserido nao esta cadastrado no sistema.\n";
                    cout << "----------------------------\n";
                    break;
                }
            }
            else {
                cout << "ERRO: Os dados de usuarios e eventos nao foram carregados.\n";
                cout << "----------------------------\n";
                break;
            }
            break;

        case 4:
            limparDadosCarregados(vetor_usuarios, vetor_eventos);
            return 0;
        default:
            break;
        }
    }

// Delete all dynamically allocated data
    limparDadosCarregados(vetor_usuarios, vetor_eventos);

    return 0;
}

void limparDadosCarregados(vector<Usuario*> vetor_usuarios, vector<Evento*> vetor_eventos) {
    for (Usuario *u : vetor_usuarios) {
        //u->imprime();
        switch (u->get_tipo()) {
            case CRIANCA:
                delete(dynamic_cast<Crianca*>(u));
                break;

            case ADULTO:
                delete(dynamic_cast<Adulto*>(u));
                break;

            case IDOSO:
                delete(dynamic_cast<Idoso*>(u));
                break;

            default:
                delete(u);
                break;
        };
    }

    for (Evento *e : vetor_eventos) {
        switch (e->get_categoria()) {
            case E_ADULTO:
                switch (e->get_sub_categoria()) {
                    case SHOW:
                        delete(dynamic_cast<Show*>(e));
                        break;

                    case BOATE:
                        delete(dynamic_cast<Boate*>(e));
                        break;

                    default:
                        delete(e);
                        break;
                }
                break;

            case E_INFANTIL:
                switch (e->get_sub_categoria()) {
                    case FANTOCHE:
                        delete(dynamic_cast<TeatroFantoche*>(e));
                        break;

                    default:
                        delete(e);
                        break;
                }
                break;

            case CINEMA:
                delete(dynamic_cast<Cinema*>(e));
                break;

            default:
                delete(e);
                break;
        };
    }
}