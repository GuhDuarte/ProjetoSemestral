#ifndef MAPA_H
#define MAPA_H

// class Cobra;
namespace Mapa {
    class Mapa {
    public:
        Mapa(int largura, int altura);
        ~Mapa();
        // void desenhar(const Cobra& cobra);
        void desenhar();
        bool colisaoComCobra(int x, int y) const;

    private:
        int altura;
        int largura;
        char** matriz;

        void criarMatriz();
    };
}

#endif
