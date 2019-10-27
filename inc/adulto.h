#ifndef ADULTO_H
#define ADULTO_H

#include <usuario.h>
#include <initialize_classes.h>
#include <vector>

using namespace std;

class Adulto : public Usuario {
    private:
        vector<Crianca*> dependentes;
    public:
        Adulto();
        Adulto(int i, string n, int idad, float s);
        Adulto(int i, string n, int idad, float s, int t);
        vector<Crianca*> get_dependentes();
        void add_dependente(Crianca* d);
};

#endif//ADULTO_H
