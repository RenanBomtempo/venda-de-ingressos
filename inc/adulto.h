#ifndef ADULTO_H
#define ADULTO_H

#include <usuario.h>
#include <set>

using namespace std;

class Adulto : public Usuario {
    private:
        set<int> dependentes;
    public:
        Adulto(int i, string n, int idad, float s);
        Adulto(int i, string n, int idad, float s, int t);
        set<int> get_dependentes();
        void add_dependente(int d);
        void remove_dependente(int d);
};

#endif//ADULTO_H
