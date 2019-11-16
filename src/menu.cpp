#include "menu.h"
#include <string>

const int checarInput(const char in)  {
    if (in > 52 || in < 49)
        return 0;
    else 
        return 1;
}

int getInput() {
    std::string input;

    while (1) {
        std::cout << "\nOpcao: ";
        std::cin >> input;

        if (checarInput(input[0])) 
            return input[0] - '0';
        else
            std::cout << "Opcao invalida. Insira outra opcao.\n";
            std::cout << "----------------------------\n";
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
