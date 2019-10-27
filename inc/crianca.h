#ifndef CRIANCA_H
#define CRIANCA_H

#include <usuario.h>
#include <adulto.h>

using namespace std;

class Crianca : public Usuario {
    private:
        Adulto* responsavel;
    public:
        Crianca(int i, string n, int idad, float s, Adulto* r);
        Adulto* get_responsavel();
};

#endif//CRIANCA_H
