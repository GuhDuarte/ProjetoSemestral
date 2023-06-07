#include "Mapa.h"
// #include "Cobra.h"
#include <iostream>


namespace Mapa {

    Mapa::Mapa(int largura, int altura) : largura(largura), altura(altura), matriz(nullptr) {
        criarMatriz();
    }

    Mapa::~Mapa() {
        for (int i = 0; i < altura; i++) {
            delete[] matriz[i];
        }
        delete[] matriz;
    }

    void Mapa::criarMatriz() {
        matriz = new char*[altura];
        for (int i = 0; i < altura; i++) {
            matriz[i] = new char[largura];
            for (int j = 0; j < largura; j++) {
                if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1) {
                    matriz[i][j] = '#'; // Bordas do mapa
                } else {
                    matriz[i][j] = ' '; // Espaços vazios dentro do mapa
                }
            }
        }
    }

    void Mapa::desenhar() {
        // Desenha o mapa com a cobra
        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                std::cout << matriz[i][j]; // Desenha o restante do mapa
            }
            std::cout << std::endl;
        }
    }
    // void Mapa::desenhar(const Cobra& cobra) {
    //     // Desenha o mapa com a cobra
    //     for (int i = 0; i < altura; i++) {
    //         for (int j = 0; j < largura; j++) {
    //             if (i == cobra.getY() && j == cobra.getX()) {
    //                 std::cout << '*'; // Desenha o corpo da cocbra
    //             } else {
    //                 std::cout << matriz[i][j]; // Desenha o restante do mapa
    //             }
    //         }
    //         std::cout << std::endl;
    //     }
    // }

    bool Mapa::colisaoComCobra(int x, int y) const {
        return false;// Implementação da verificação de colisão com a cobra
    };
}