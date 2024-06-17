//
// Created by gabriel on 5/21/24.
//

#include "Aleatorio.h"

std::random_device Aleatorio::rd = std::random_device();
std::mt19937 Aleatorio::gen(rd());


bool Aleatorio::gerarBooleanoAleatorio(float prob) {
    std::bernoulli_distribution bd(prob);
    return bd(gen);
}

std::vector<bool> Aleatorio::gerarVetorBooleanoAleatorio(int size, float prob) {
    std::bernoulli_distribution bd(prob);
    std::vector<bool> vetor_bool(size);

    for (int i = 0; i < size; ++i) {
        vetor_bool.at(i) = bd(gen);
    }

    return vetor_bool;
}

int Aleatorio::gerarInteiroAleatorio(int min, int max) {
    std::uniform_int_distribution<> distribution(min, max);
    return distribution(gen);
}

