#ifndef BOATE_H
#define BOATE_H

#include <eventoadulto.h>
#include <usuario.h>

using namespace std;

class Boate : public EventoAdulto{
    private:
        int hora_inicio;
        int hora_fim;
    public:
        Boate(int i, string n, Usuario* d, int c, int q, int hi, int hf);
        Boate(int i, string n, Usuario* d, int c,
              vector<int> ca, vector<int> p, int q,
              int hi, int hf);
}


#endif//BOATE_H
