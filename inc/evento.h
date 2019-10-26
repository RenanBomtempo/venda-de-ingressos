#ifndef EVENTO_H
#define EVENTO_H

#include "initialize_classes.h"
#include "usuario.h"
#include <vector>
#include <string>

using namespace std;

class Evento{
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
        void add_ingresso(int c, int p);

};

#endif//EVENTO_H
