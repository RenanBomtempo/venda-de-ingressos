#include <utils.h>

// Métodos relativos a usuários

int qtd_usuarios_por_tipo(int tipo, vector<Usuario*> usuarios){
    int qtd = 0;
    for(auto u : usuarios){
        if (u->get_tipo() == tipo){
            qtd++;
        }
    }
    return qtd;
}

// Retorna idade mínima, média e máxima dos usuários
vector<float> dados_idade_usuarios(vector<Usuario*> usuarios){
    int min = 1000;
    int max = 0;
    int qtd = 0;
    int idade_autal;
    float med;

    for (auto u : usuarios){
        idade_autal = u->get_idade();
        if (idade_autal < min){
            min = idade_autal;
        }
        if (idade_autal > max){
            max = idade_autal;
        }
        med += idade_autal;
        qtd++;
    }

    med /= qtd;

    vector<float> resultados;
    resultados.push_back(min);
    resultados.push_back(med);
    resultados.push_back(max);

    return resultados;

}

vector<float> dados_dependentes_usuarios(vector<Usuario> usuarios){
    int min = 1000;
    int max = 0;
    int qtd = 0;
    vector<Crianca*> dep_autal;
    float med;

    for (auto u : usuarios){
        dep_autal = u->get_dependentes();
        if (dep_autal.size() < min){
            min = dep_autal.size();
        }
        if (dep_autal.size() > max){
            max = dep_autal.size();
        }
        med += dep_autal.size();
        qtd++;
    }

    med /= qtd;

    vector<float> resultados;
    resultados.push_back(min);
    resultados.push_back(med);
    resultados.push_back(max);

    return resultados;

}

map<int, vector<Crianca*>> map_dependentes_por_adulto(vector<Usuario> usuarios){
    map<int, vector<Crianca*>> resultados;

    for (auto u : usuarios){
        resultados.insert(pair<int,
                               vector<Crianca*>(u->get_id(),
                                                u->get_dependentes()))
    }

    return resultados;
}

// Métodos relativos a eventos

int qtd_eventos_por_tipo(int tipo, int sub_tipo, vector<Evento> eventos){
    int qtd = 0;
    for(auto e : eventos){
        if (u->get_categoria() == tipo){
            if ((tipo == 1 || tipo == 2) &&
                u->get_sub_categoria() == sub_tipo){
                qtd++;
            }
            elif(tipo != 1 && tipo != 2){
                qtd++;
            }
        }
    }
    return qtd;
}
/*
map<int, int> qtd_eventos_por_usuario(vector<Evento> eventos);

int maior_cota_idoso(vector<Evento> eventos);

map<int, int> numero_ingressos_por_preco(vector<Evento> eventos);
*/
