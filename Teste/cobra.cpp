#include "Cobra.h"

Cobra::Cobra(int posicaoInicialX, int posicaoInicialY) : corpoX(posicaoInicialX), corpoY(posicaoInicialY) {
    // Implementação do construtor
}

void Cobra::mover(int direcao) {
    // Implementação do movimento da cobra
}

bool Cobra::colisaoComSiMesma() {
    return false;// Implementação da verificação de colisão com si mesma
}

bool Cobra::colisaoComMapa(const Mapa& mapa) {
    return false;// Implementação da verificação de colisão com o mapa
}

void Cobra::crescer() {
    // Implementação do crescimento da cobra
}

int Cobra::getX() const {
    return 0;// Implementação do acesso à posição X
}

int Cobra::getY() const {
    return 0;// Implementação do acesso à posição Y
}