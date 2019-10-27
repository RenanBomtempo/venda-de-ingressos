#ifndef BOATE_H
#define BOATE_H

#include "initialize_classes.h"
#include "eventoadulto.h"
#include "usuario.h"
#include <string>
#include <vector>

using namespace std;

class Boate : public EventoAdulto{
    private:
        int hora_inicio;
        int hora_fim;
    public:
        Boate(int i, string n, Usuario* d, int q, int hi, int hf);
        Boate(int i, string n, Usuario* d,
              vector<int> ca, vector<int> p, int q,
              int hi, int hf);
};


#endif//BOATE_H
