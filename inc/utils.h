#ifndef UTILS_H
#define UTILS_H

#include <usuario.h>
#include <crianca.h>
#include <vector>
#include <evento.h>

// Métodos relativos a usuários

int qtd_usuarios_por_tipo(int tipo, vector<Usuario*> usuarios);

vector<float> dados_idade_usuarios(vector<Usuario> usuarios);

vector<float> dados_dependentes_usuarios(vector<Usuario> usuarios);

map<int, vector<Crianca*>> map_dependentes_por_adulto(vector<Usuario> usuarios);

// Métodos relativos a eventos

int qtd_eventos_por_tipo(int tipo, vector<Evento> eventos);

map<int, int> qtd_eventos_por_usuario(vector<Evento> eventos);

int maior_cota_idoso(vector<Evento> eventos);

map<int, int> numero_ingressos_por_preco(vector<Evento> eventos);


#endif
