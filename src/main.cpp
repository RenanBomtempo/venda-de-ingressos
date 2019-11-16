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

// Bibliotecas std
#include "csvprocessor.h"
#include "saida.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void limparDadosCarregados( vector<Usuario*> vetor_usuarios, vector<Evento*> vetor_eventos){
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

int main(){
    vector<Usuario*> vetor_usuarios;
    vector<Evento*> vetor_eventos;
    string_table usuarios_table = CSVtoStringTable("../data/usuarios.csv");
    string_table eventos_table  = CSVtoStringTable("../data/eventos.csv");
    bool is_dados_carregados = false;

    exibirMenu();

    while (1) {
        switch (getInput()) {
        case 1:
            if (!is_dados_carregados) {
                vetor_usuarios = LerUsuarios(usuarios_table);
                vetor_eventos = LerEventos(eventos_table, vetor_usuarios);
                cout << "----------------------------\n";
                gerarSaida(vetor_usuarios, vetor_eventos);
                cout << "----------------------------\n";
                is_dados_carregados = true;
            } else {
                cout << "Os dados de usuarios e eventos ja estao carregados.\n";
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
                cout << "Os dados de usuarios e eventos nao foram carregados.\n";
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
                            cout << "Apenas ADULTOS e IDOSOS podem comprar ingressos.\n";
                            break;
                        }
                        // INICIAR PROCESSO DE COMPRA
                        //
                        //
                        //
                        //
                    }
                }

                if (comprador == nullptr)
                    cout << "O ID inserido nao esta cadastrado no sistema.\n";

                break;
            }
            else {
                cout << "Os dados de usuarios e eventos nao foram carregados.\n";
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
/*
    std::vector<Boate*> vetor_boates;

    for(Evento* evento : vetor_eventos) {
        switch (evento->get_categoria()) {
            case E_ADULTO:
                switch (evento->get_sub_categoria()) {
                    case BOATE:
                        vetor_boates.push_back(dynamic_cast<Boate*>(evento));
                        break;
                }
            default:
                break;
        }
    }

    MaquinaBoate maq_boate(vetor_boates, vetor_usuarios[0]);

    maq_boate.mostra_maquina();
*/

// Delete all dynamically allocated data
    limparDadosCarregados(vetor_usuarios, vetor_eventos);

    return 0;
}
