#include "Jogo.h"
// #include "Cobra.h"
#include "mapa.h"
#include <iostream>
#include <string>
#include <fstream>

namespace Jogo{

    Jogo::Jogo() : mapa(nullptr), largura(0), altura(0) {};
    // Jogo::Jogo() : mapa(nullptr), cobra(nullptr), largura(0), altura(0) {};

    Jogo::~Jogo() {
        delete mapa;
        // delete cobra;
    };

    void Jogo::novoJogo() {
        std::string nome;
        int largura, altura;

        std::cout << "=== Novo Jogo ===" << std::endl;

        std::cout << "Digite seu nome: ";
        std::cin >> nome;

        std::cout << "Digite a largura do mapa: ";
        std::cin >> largura;

        std::cout << "Digite a altura do mapa: ";
        std::cin >> altura;

        delete mapa;
        // delete cobra;

        mapa = new Mapa::Mapa(largura, altura);
        // Cobra cobra(largura / 2, altura / 2); // Inicia a cobra no meio do mapa
        mapa->desenhar();
        int pontuacao = 100; // Substitua pelo valor real da pontuação
        gravarRanking(nome, pontuacao);

        // jogar();
    }

    void Jogo::gravarRanking(const std::string& nome, int pontuacao) const {
        std::ofstream arquivo("ranking.txt", std::ios_base::app);
        if (arquivo.is_open()) {
            arquivo << "Nome: " << nome << std::endl;
            arquivo << "Pontuação: " << pontuacao << std::endl;
            arquivo << std::endl;
            arquivo.close();
            std::cout << "Dados gravados com sucesso no arquivo." << std::endl;
        } else {
            std::cout << "Erro ao abrir o arquivo." << std::endl;
        }
    }   
}