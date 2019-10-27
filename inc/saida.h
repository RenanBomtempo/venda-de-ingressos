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

/* Gera o relatorio de saida dos dados dos Usuarios
 */
void saidaUsuarios (std::vector<Usuario*> usuarios);

/* Gera o relatorio de saida dos dados dos Eventos
 */
void saidaEventos (std::vector<Evento*> eventos);

#endif