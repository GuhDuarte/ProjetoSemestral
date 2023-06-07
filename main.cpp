#include <iostream>
#include <string>
#include "jogo.h"
#include <fstream>


// void verRanking() {
//     std::cout << "=== Ranking ===" << std::endl;
//     int c;
//     FILE *file;
//     file = fopen("Ranking.txt", "r");

//     if(file){
//         while ((c = getc(file)) != EOF)
//         {
//             printf("%c", c);
//         }
//     fclose(file);
//     }
//     // std::cout << "=== Ranking ===" << std::endl;
//     // std::ofstream arquivo("ranking.txt");
//     //     if (arquivo.is_open()) {
//     //         arquivo << "Nome: " << nome << std::endl;
//     //         arquivo << "Pontuação: " << pontuacao << std::endl;
//     //         arquivo.close();
//     //         std::cout << "Dados gravados com sucesso no arquivo." << std::endl;
//     //     } else {
//     //         std::cout << "Erro ao abrir o arquivo." << std::endl;
//     //     }
// }
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
    // Jogo* jogo = nullptr;
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
                // if (jogo != nullptr) {
                //     delete jogo;
                // }
                // jogo = new Jogo();
                jogo.novoJogo();
                break;
            case 2:
                lerRanking();
                break;
            case 3:
                std::cout << "Fechando o programa..." << std::endl;
                break;
            default:
                std::cout << "Opcao invalida. Tente novamente." << std::endl;
        }

        if (opcao != 3) {
            std::cout << "Pressione Enter para voltar ao menu principal.";
            std::cin.ignore(); // Aguardar a entrada do usuário (pressionar Enter)
        }

        std::cout << std::endl;
    } while (opcao != 3);

    return 0;
}