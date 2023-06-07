#ifndef JOGO_H
#define JOGO_H

#include "mapa.h"
#include <utility>
#include <string>
#include <algorithm>
#include <vector>


namespace Jogo{

    class Jogo {
    public:
        std::vector<std::pair<int, int>> corpo;
        std::pair<int, int> comida;
        int pontuacao = 0;
        Jogo();
        ~Jogo();
        void jogar();
        void novoJogo();
        void limparCobra();


    private:
        void gravarRanking(const std::string& nome, int pontuacao) const;
        Mapa::Mapa* mapa;
        int largura;
        int altura;
    };
}
#endif