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
        int dificuldade;

        Jogador(const std::string& nome, int pontuacao);
    };

    class Jogo {
    public:
        std::vector<Jogador> rankings;
        std::pair<int, int> comida;
        Jogo();
        ~Jogo();
        void novoJogo();
        void atualizarRanking();
        void salvarRanking();  

    private:
        void gravarRanking(std::string& nome, int pontuacao);
    };
}
#endif