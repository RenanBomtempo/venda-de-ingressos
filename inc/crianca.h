#ifndef CRIANCA_H
#define CRIANCA_H

#include <usuario.h>

using namespace std;

class Crianca : public Usuario {
    private:
        int responsavel;
    public:
        Crianca(int i, string n, int idad, float s, int r);
        int get_responsavel();
};

#endif//CRIANCA_H
