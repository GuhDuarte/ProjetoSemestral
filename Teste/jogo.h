#ifndef JOGO_H
#define JOGO_H

#include "mapa.h"
#include <utility>
#include <string>
#include <algorithm>
#include <vector>


namespace Jogo{

    class Jogador {
    public:
        std::string nome;
        int pontuacao;

        Jogador(const std::string& nome, int pontuacao);
    };

    class Jogo {
    public:
        std::vector<std::pair<int, int>> corpo;
        std::vector<Jogador> rankings;
        std::pair<int, int> comida;
        Jogo();
        ~Jogo();
        void jogar();
        void novoJogo();
        void limparCobra();

    private:
        void gravarRanking(std::string& nome, int pontuacao);
        void salvarRanking();
        // Mapa::Mapa* mapa; 
    };
}
#endif