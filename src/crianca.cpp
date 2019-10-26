#include "crianca.h"

using namespace std;

Crianca::Crianca(int i, string n, int idad, float s, int r) : Usuario(i, n, idad, s, 0){
    responsavel = r;
}
