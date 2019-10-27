#include "saida.h"
#include <list>
#include <string>
#include <iostream>
#include <iomanip>

#define MAX_INT 0xffffff

void saidaUsuarios (std::vector<Usuario*> usuarios) {
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
}

void saidaEventos (std::vector<Evento*> eventos) {

}