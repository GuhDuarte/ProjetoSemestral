#ifndef JOGO_H
#define JOGO_H

#include "mapa.h"
#include <utility>
#include <string>


namespace Jogo{
    // class Cobra;

    class Jogo {
    public:
        Jogo();
        ~Jogo();
        void jogar();
        void novoJogo();
        // std::pair<std::string, int> obterNomePontuacao() const;


    private:
        void gravarRanking(const std::string& nome, int pontuacao) const;
        Mapa::Mapa* mapa;
        // Cobra* cobra;
        int largura;
        int altura;
    };
}
#endif