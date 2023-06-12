#ifndef MAPA_H
#define MAPA_H

#include <vector>

namespace Mapa {
    class Mapa {
    public:
        Mapa(int largura, int altura);
        Mapa();
        ~Mapa();
        void desenharMapa(int x, int y, const std::vector<std::pair<int, int>>& corpo, const std::pair<int, int>& comida, int pontuacao);
        bool verificarColisao(const std::vector<std::pair<int, int>>& corpo, int x, int y);

    private:
        int altura;
        int largura;
        std::vector<std::vector<char>> matriz;
        void criarMatriz();
    };
}

#endif
