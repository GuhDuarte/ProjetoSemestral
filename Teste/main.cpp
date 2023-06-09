#include <iostream>
#include <string>
#include "jogo.h"
#include <fstream>

void lerRanking() {
    std::cout << "=== Ranking ===" << std::endl;
    std::ifstream arquivo("ranking.txt");
    if (arquivo.is_open()) {
        std::string linha;
        while (std::getline(arquivo, linha)) {
            std::cout << linha << std::endl;
        }
        arquivo.close();
    } else {
        std::cout << "Erro ao abrir o arquivo." << std::endl;
    }
}

int main() {
    int opcao;
    using Jogo::Jogo;
    Jogo jogo;

    do {
        std::cout << "===== Snake Game =====" << std::endl;
        std::cout << "======== Menu ========" << std::endl;
        std::cout << "1. Novo Jogo" << std::endl;
        std::cout << "2. Ver Ranking" << std::endl;
        std::cout << "3. Fechar" << std::endl;
        std::cout << "Escolha uma opcao: ";
        std::cin >> opcao;

        switch (opcao) {
            case 1:
                jogo.novoJogo();
                jogo.limparCobra();
                break;
            case 2:
                lerRanking();
                break;
            case 3:
                std::cout << "Fechando o programa..." << std::endl;
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
                std::cin.ignore(); 
        }

        if (opcao != 3) {
            std::cout << "Pressione Enter para voltar ao menu principal.";
            std::cin.ignore(); 
        }

        std::cout << std::endl;
    } while (opcao != 3);

    return 0;
}