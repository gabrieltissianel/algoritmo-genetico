//
// Created by gabriel on 5/21/24.
//

#ifndef ALEATORIO_H
#define ALEATORIO_H
#include <random>


class Aleatorio {
private:
    static std::random_device rd;
    static std::mt19937 gen;

public:
    static bool gerarBooleanoAleatorio(float prob);
    static std::vector<bool> gerarVetorBooleanoAleatorio(int size, float prob);
    static int gerarInteiroAleatorio(int min, int max);
};



#endif //ALEATORIO_H
