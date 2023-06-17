#include "Jogo.h"
#include <conio.h>
#include "mapa.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <thread>

namespace Jogo{

    void limparTela() {
        system("cls");
    }

    Jogo::Jogo(){};
    Jogo::~Jogo() {};
    Jogador::Jogador(const std::string& nome, int pontuacao) : nome(nome), pontuacao(pontuacao) {}

    void Jogo::novoJogo() {
        std::string nome;
        int largura, altura, dificuldade, velocidade;

        std::cout << "=== Novo Jogo ===" << std::endl;

        std::cout << "Digite seu nome: ";
        std::getline(std::cin, nome);
        std::getline(std::cin, nome);

        std::cout << "Digite a largura do mapa: ";
        std::cin >> largura;
        while (largura < 5) {
            std::cout << "Valor invalido! A largura deve ser maior ou igual a 5. Digite novamente: ";
            std::cin >> largura;
        }

        std::cout << "Digite a altura do mapa: ";
        std::cin >> altura;
        while (altura < 5) {
            std::cout << "Valor invalido! A altura deve ser maior ou igual a 5. Digite novamente: ";
            std::cin >> altura;
        }

        while (dificuldade != 1 && dificuldade != 2) {
            std::cout << "Selecione o nivel de dificuldade (1-Facil, 2-Dificil): ";
            std::cin >> dificuldade;

            if (dificuldade != 1 && dificuldade != 2) {
            std::cout << "Opcao invalida! Por favor, selecione 1 para Facil ou 2 para Dificil." << std::endl;
            }
        }

        Mapa::Mapa mapa(largura, altura);
        bool gameover = false;
        int pontuacao = 0;
        comida.first = 1 + rand() % (largura - 2);
        comida.second = 1 + rand() % (altura - 4);
        std::vector<Mapa::Posicao> corpo;
        corpo.push_back(Mapa::Posicao(largura / 2, altura / 2));
            
        int x = corpo[0].x;
        int y = corpo[0].y;
        char tecla = 'd';
        
        while (!gameover) {
            limparTela();
            mapa.desenharMapa(x, y, corpo, comida, pontuacao);
            
            if (_kbhit()) {
                tecla = _getch();
            }

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

            if (x < 0 || x > largura || y < 0 || y > altura || mapa.verificarColisao(corpo, x, y)) {
                gameover = true;
                break;
            }

            corpo.insert(corpo.begin(), {x, y});

            if (x == comida.first && y == comida.second) {
                pontuacao++;
                comida.first = 1 + rand() % (largura - 2);
                comida.second = 1 + rand() % (altura - 4);
            } else {
                corpo.pop_back();
            }

            if (dificuldade == 1)
                velocidade = 150;
            else 
                velocidade = 20;
            std::this_thread::sleep_for(std::chrono::milliseconds(velocidade));
        }
        std::cout << "Fim de Jogo! Sua pontuacao foi: " << pontuacao << std::endl;
        // rankings.clear();
        gravarRanking(nome, pontuacao);
        // salvarRanking();
    }

    void Jogo::gravarRanking(std::string& nome, int pontuacao) {
        Jogador jogador(nome, pontuacao);
        rankings.push_back(jogador);
    }

    void Jogo::salvarRanking() {
        if (rankings.empty()) {
            std::cout << "Nao ha dados de ranking para salvar." << std::endl;
            return;
        }

        std::vector<Jogador> rankingAtualizado;
        std::ifstream arquivoAnterior("ranking.txt");
        if (arquivoAnterior.is_open()) {
            std::string linha;
            while (std::getline(arquivoAnterior, linha)) {
                std::string nome;
                int pontuacao;
                try
                {              
                    std::size_t separador = linha.find(',');
                    if (separador != std::string::npos) {
                        nome = linha.substr(6, separador - 6);
                        pontuacao = std::stoi(linha.substr(separador + 12));
                        Jogador jogador{nome, pontuacao};
                        rankingAtualizado.push_back(jogador);
                    }
                } catch (const std::invalid_argument& e) {
                    std::cout << "Erro: Conversao invalida da pontuacao. Linha do arquivo: " << linha << std::endl;
                }
            }
            arquivoAnterior.close();
        }

        rankingAtualizado.insert(rankingAtualizado.end(), rankings.begin(), rankings.end());

        std::sort(rankingAtualizado.begin(), rankingAtualizado.end(), [](const Jogador& jogador1, const Jogador& jogador2) {
            return jogador1.pontuacao > jogador2.pontuacao;
        });

        std::ofstream arquivoAtualizado("ranking.txt", std::ios_base::trunc);
        if (arquivoAtualizado.is_open()) {
            for (const auto& ranking : rankingAtualizado) {
                arquivoAtualizado << "Nome: " << ranking.nome << ", Pontuacao: " << ranking.pontuacao << std::endl;
            }
            arquivoAtualizado.close();
            std::cout << "Dados gravados com sucesso no arquivo." << std::endl;
        } else {
            std::cout << "Erro ao abrir o arquivo." << std::endl;
        }
    }
}