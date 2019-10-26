#ifndef IDOSO_H
#define IDOSO_H

#include <adulto.h>

using namespace std;

class Idoso : public Adulto {
    public:
        Idoso(int i, string n, int idad, float s) : Adulto(i, n, idad, s, 2);
}

#endif//IDOSO_H
