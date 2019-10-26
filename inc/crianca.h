#ifndef CRIANCA_H
#define CRIANCA_H

#include <usuario.h>

using namespace std;

class Crianca : public Usuario {
    private:
        int responsavel;
    public:
        Crianca(int i, string n, int idad, float s) : Usuario(i, n, idad, s, 0);
        int get_responsavel();
        void set_responsavel(int r);
}

#endif//CRIANCA_H
