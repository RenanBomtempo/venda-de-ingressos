#ifndef IDOSO_H
#define IDOSO_H

#include "initialize_classes.h"
#include "adulto.h"
#include <string>

using namespace std;

class Idoso : public Adulto {
    public:
        Idoso(int i, string n, int idad, float s);
};

#endif//IDOSO_H
