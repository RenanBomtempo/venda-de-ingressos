#ifndef SAIDA_H
#define SAIDA_H

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
#include <vector>

void numeroDeUsuarios (std::vector<Usuario*> usuarios);
void idadeDosUsuarios (std::vector<Usuario*> usuarios);
void numeroDeDependentes (std::vector<Usuario*> usuarios);
void dependentesPorAdulto (std::vector<Usuario*> usuarios);
void numeroDeEventos (std::vector<Evento*> eventos);
void numeroDeEventosPorUsuario (std::vector<Usuario*> usuarios, std::vector<Evento*> eventos);
void eventoComMaiorQuotaDeIdoso (std::vector<Evento*> eventos);
void numeroDeIngrecosPorPreco (std::vector<Evento*> eventos);
void gerarSaida (std::vector<Usuario*> usuarios, std::vector<Evento*> eventos);

#endif