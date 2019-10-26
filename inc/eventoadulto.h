#ifndef EVENTO_ADULTO_H
#define EVENTO_ADULTO_H

using namespace std;

class EventoAdulto{
    private:
        int quota_idoso;
    public:
        EventoAdulto(int i, string n, Usuario* d, int c, int q);
        EventoAdulto(int i, string n, Usuario* d, int c, vector<int> ca, vector<int> p, int q);
}

#endif//EVENTO_ADULTO_H
