#include "Jogo.h"
#include <conio.h>
#include "mapa.h"
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

namespace Jogo{

    void limparTela() {
        system("cls");
    }

    Jogo::Jogo() : mapa(nullptr), largura(0), altura(0) {};
    Jogo::~Jogo() { };
    Jogador::Jogador(const std::string& nome, int pontuacao) : nome(nome), pontuacao(pontuacao) {}

    void Jogo::novoJogo() {
        std::string nome;
        int largura, altura;

        std::cout << "=== Novo Jogo ===" << std::endl;

        std::cout << "Digite seu nome: ";
        std::getline(std::cin, nome);
        std::getline(std::cin, nome);

        std::cout << "Digite a largura do mapa: ";
        std::cin >> largura;

        std::cout << "Digite a altura do mapa: ";
        std::cin >> altura;

        mapa = new Mapa::Mapa(largura, altura);
        bool gameover = false;
        int pontuacao = 0;
        comida.first = rand() % largura;
        comida.second = rand() % altura;
        int x = largura / 2;
        int y = altura / 2;

        while (!gameover) {
            limparTela();
            if (mapa != nullptr) {
                mapa->desenharMapa(x, y, corpo, comida, pontuacao);
            }

            char tecla = getch();

            switch (tecla) {
                case 'w':
                    y--;
                    break;
                case 's':
                    y++;
                    break;
                case 'a':
                    x--;
                    break;
                case 'd':
                    x++;
                    break;
                case 27:
                    gameover = true;
                    break;
                default:
                    break;
            }

            if (x < 0 || x >= largura || y < 0 || y >= altura || mapa->verificarColisao(corpo, x, y)) {
                gameover = true;
                break;
            }

            corpo.push_back(std::make_pair(x, y));

            if (x == comida.first && y == comida.second) {
                pontuacao++;
                comida.first = rand() % largura;
                comida.second = rand() % altura;
            } else {
                corpo.erase(corpo.begin());
            }
        }

        rankings.clear();
        gravarRanking(nome, pontuacao);
        salvarRanking();
        delete mapa;

    }

    void Jogo::gravarRanking(std::string& nome, int pontuacao) {
        Jogador jogador(nome, pontuacao);
        rankings.push_back(jogador);
    }

    void Jogo::salvarRanking() { 
        if (rankings.empty()) {
            std::cout << "Não há dados de ranking para salvar." << std::endl;
            return;
        }   
        std::ofstream arquivo("ranking.txt", std::ios_base::app);
        if (arquivo.is_open()) {
            for (const auto& ranking : rankings) {
                arquivo << "Nome: " << ranking.nome << ", Pontuação: " << ranking.pontuacao << std::endl;
            }
            arquivo.close();
            std::cout << "Dados gravados com sucesso no arquivo." << std::endl;
        } else {
            std::cout << "Erro ao abrir o arquivo." << std::endl;
        }
    }

    void Jogo::limparCobra(){
        corpo.clear();
    }

}