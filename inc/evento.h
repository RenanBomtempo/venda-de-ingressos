#ifndef EVENTO_H
#define EVENTO_H

#include "initialize_classes.h"
#include "usuario.h"
#include <vector>
#include <string>

using namespace std;

enum categoria {
    CINEMA, E_INFANTIL, E_ADULTO
};

class Evento {
    private:
        int id;
        string nome;
        Usuario* dono;
        int categoria;
        vector<int> capacidades;
        vector<int> precos;
    public:
        Evento(int i, string n, Usuario* d, int c);
        Evento(int i, string n, Usuario* d, int c,
               vector<int> ca, vector<int> p);
        virtual ~Evento();
        string get_nome();
        vector<int> get_capacidades();
        vector<int> get_precos();
        int get_preco_atual();
        void gasta_capacidades(int index, int qtd);
        Usuario *get_dono();
        int get_categoria();
        int get_id();
        void add_ingresso(int c, int p);
        virtual int get_sub_categoria();
};

void exibirTelaDeEventos();

#endif//EVENTO_H
