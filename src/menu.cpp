#include "menu.h"
#include <string>
#include <iostream>

const int checarInput(const char in, const char beg, const char end)  {
    if (in > end || in < beg)
        return 0;
    else 
        return 1;
}

int lerInput(const char beg, const char end) {
    std::string input;

    while (1) {
        std::cout << "\nOpcao: ";
        std::cin >> input;

        if (checarInput(input[0], beg, end)) 
            return input[0] - '0';
        else {
            std::cout << "ERRO: Opcao invalida. Insira outra opcao:\n";
        }
    }
}

void exibirMenu() {
    std::cout << "\nSISTEMA DE VENDA DE INGRESSOS       \n";
    std::cout << "Favor escolher uma das opcoes abaixo: \n";
    std::cout << "\t1. Carregar usuarios e eventos      \n";
    std::cout << "\t2. Exibir usuarios cadastrados      \n";
    std::cout << "\t3. Comprar ingressos                \n";
    std::cout << "\t4. Sair                             \n";
}


void exibirTelaDeEventos() {
    std::cout << "\n--------------MENU DE EVENTOS--------------\n";
    std::cout << "Escolha um evento para comprar ingressos:\n";
    std::cout << "\t1. Cinema   \n";
    std::cout << "\t2. Show     \n";
    std::cout << "\t3. Boate    \n";
    std::cout << "\t4. Fantoche \n";
    std::cout << "\t5. Voltar para o menu\n";
}