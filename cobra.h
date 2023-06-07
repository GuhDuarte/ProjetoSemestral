#ifndef COBRA_H
#define COBRA_H

#include <vector>

class Mapa;

class Cobra {
public:
    Cobra(int posicaoInicialX, int posicaoInicialY);
    void mover(int direcao);
    bool colisaoComSiMesma();
    bool colisaoComMapa(const Mapa& mapa);
    void crescer();
    int getX() const;
    int getY() const;

private:
    
    std::vector<int> corpoX;
    std::vector<int> corpoY;
};
#endif
