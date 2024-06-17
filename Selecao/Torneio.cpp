//
// Created by gabriel on 6/16/24.
//

#include "Torneio.h"

#include <algorithm>

#include "../Aleatorio.h"

std::shared_ptr<Individuo> Torneio::executar(Populacao &pais) {
    Populacao torneio;
    for (int i = 0; i < 5; ++i) {
        int random = Aleatorio::gerarInteiroAleatorio(0, pais.size() - 1);
        torneio.push_back(pais.at(random));
    }

    auto it = max_element(torneio.begin(), torneio.end(), [](const std::shared_ptr<Individuo>& a, const std::shared_ptr<Individuo>& b) {
        return a->getFitness() < b->getFitness();
    });

    return *it;
}
