// Usuario
#include "usuario.h"
#include "adulto.h"
#include "crianca.h"
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
#include "csvprocessor.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

void print_test(Usuario a){
    cout << "Id:" << a.get_id() << endl;
    cout << "Nome:" << a.get_nome() << endl;
    cout << "Saldo:" << a.get_saldo() << endl;
    cout << "Idade:" << a.get_idade() << endl;
}

int main(){
    /*Adulto teste_a(1, "Ana Maria", 30, 1500.0);
    Crianca teste_c1(0, "Jorge", 10, 100.0, &teste_a);
    Crianca teste_c2(3, "Joana", 10, 200.0, &teste_a);
    Idoso teste_i(2, "Arlindo", 50, 500.0);

    print_test(teste_c1);
    cout << "Responsavel:" <<  teste_c1.get_responsavel()->get_id() << endl;
    print_test(teste_c2);
    cout << "Responsavel:" <<  teste_c2.get_responsavel()->get_id() << endl;
    print_test(teste_a);
    cout << "Dependentes:";
    for(auto d : teste_a.get_dependentes()){
        cout << d->get_id() << endl;
    }
    print_test(teste_i);*/

    string_table usuarios_table = CSVtoStringTable("../data/usuarios.csv");
    string_table eventos_table  = CSVtoStringTable("../data/eventos.csv");

    // Ler usuarios
    std::vector<Usuario*> vetor_usuarios = LerUsuarios(usuarios_table);
    
    for (Usuario *u : vetor_usuarios)
    {
        u->imprime();
        free(u);
    }

    return 0;
}
