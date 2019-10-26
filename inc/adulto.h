#ifndef ADULTO_H
#define ADULTO_H

#include <usuario.h>
#include <vector>

class Adulto : public Usuario {
    private:
        vector<int> dependentes;
    public:
        vector<int> get_dependentes();
        void add_dependente(int d);
        void remove_dependente(int d);
}

#endif//ADULTO_H
