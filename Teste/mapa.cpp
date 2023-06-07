#include "Mapa.h"
#include <iostream>
#include <algorithm>
#include <vector>


namespace Mapa {

    Mapa::Mapa(int largura, int altura) : largura(largura), altura(altura) {
        criarMatriz();
    }

    Mapa::Mapa() : largura(0), altura(0) { matriz.clear(); } 

    Mapa::~Mapa() { }

    void Mapa::criarMatriz() {
        matriz.resize(altura, std::vector<char>(largura, ' '));

        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1) {
                    matriz[i][j] = '#';
                }
            }
        }
    }

    bool Mapa::verificarColisao(const std::vector<std::pair<int, int>>& corpo, int x, int y) {
        return std::find_if(corpo.begin(), corpo.end(), [&](const auto& pos) {
            return pos.first == x && pos.second == y;
        }) != corpo.end();
    }   


    void Mapa::desenharMapa(int x, int y, const std::vector<std::pair<int, int>>& corpo, const std::pair<int, int>& comida, int pontuacao) {
    std::cout << "Pontuação: " << pontuacao << std::endl;

        for (int i = 0; i < altura; ++i) {
            for (int j = 0; j < largura; ++j) {
                if (i == y && j == x) {
                    std::cout << '*'; // Cabeça da cobra
                } else if (std::find_if(corpo.begin(), corpo.end(), [&](const auto& pos) {
                    return pos.first == j && pos.second == i;
                }) != corpo.end()) {
                    std::cout << '*'; // Corpo da cobra
                } else if (j == comida.first && i == comida.second) {
                    std::cout << '@'; // Comida
                } else {
                    std::cout << ' ';
                }
            }
            std::cout << std::endl;
        }
    }
}