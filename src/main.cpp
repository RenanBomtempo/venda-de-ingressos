// Usuario
#include "usuario.h"
#include "crianca.h"
#include "adulto.h"
#include "idoso.h"
// Evento
#include "evento.h"
#include "cinema.h"
#include "eventoadulto.h"
#include "show.h"
#include "boate.h"
#include "eventoinfantil.h"
#include "teatrofantoche.h"
// Bibliotecas std
#include <iostream>

using namespace std;

void print_test(Usuario a){
    cout << "Id:" << a.get_id() << endl;
    cout << "Nome:" << a.get_nome() << endl;
    cout << "Saldo:" << a.get_saldo() << endl;
    cout << "Idade:" << a.get_idade() << endl;
}

int main(){
    Crianca teste_c(0, "Jorge", 10, 100.0, 1);
    Adulto teste_a(1, "Ana Maria", 30, 1500.0);
    teste_a.add_dependente(0);
    Idoso teste_i(2, "Arlindo", 50, 500.0);

    print_test(teste_c);
    cout << "Responsavel:" <<  teste_c.get_responsavel() << endl;
    print_test(teste_a);
    cout << "Dependentes:";
    for(auto d : teste_a.get_dependentes()){
        cout << d << endl;
    }
    print_test(teste_i);

    return 0;
}
