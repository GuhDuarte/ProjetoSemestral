#ifndef MAPA_H
#define MAPA_H

#include <vector>

namespace Mapa {

    class Posicao {
    public:
        int x;
        int y;

        Posicao(int x, int y) : x(x), y(y) {}
    };

    class Mapa {
    public:
        Mapa();
        Mapa(int largura, int altura);
        ~Mapa();
        void desenharMapa(int x, int y, const std::vector<Posicao>& corpo, const std::pair<int, int>& comida, int pontuacao);
        bool verificarColisao(const std::vector<Posicao>& corpo, int x, int y);
        int getAltura() const;
        int getLargura() const;
        void setAltura(int a);
        void setLargura(int l);

    private:
        int altura;
        int largura;
        std::vector<std::vector<char>> matriz;
        void criarMatriz();
    };

}

#endif