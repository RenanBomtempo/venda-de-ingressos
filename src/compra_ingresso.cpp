#include <iostream>
#include "compra_ingresso.h"

using namespace std;

void compra_ingresso(Evento* evento, Usuario* usuario){
    int preco_agora = evento->get_preco_atual();
    if (preco_agora == -1){
        cout << "Não há ingressos disponíveis." << endl;
    }else{
       // if (usuario->get_saldo()) >
    }
}
