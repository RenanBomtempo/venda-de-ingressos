#ifndef ADULTO_H
#define ADULTO_H

#include <usuario.h>
#include <vector>

using namespace std;

class Adulto : public Usuario {
    private:
        vector<int> dependentes;
    public:
        Adulto(int i, string n, int idad, float s)  : Usuario(i, n, idad, s, 1);
        Adulto(int i, string n, int idad, float s, int t)  : Usuario(i, n, idad, s, t);
        vector<int> get_dependentes();
        void add_dependente(int d);
        void remove_dependente(int d);
}

#endif//ADULTO_H
