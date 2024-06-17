//
// Created by gabriel on 5/14/24.
//

#include "TipoMochila.h"

#include <fstream>

#include "../Aleatorio.h"
#include "../Gene/GeneMochila.h"

std::vector<Item> TipoMochila::itens = Item::lerCSVdeItens(std::ifstream("../Individuo/itens.csv"));

Cromossomo TipoMochila::gerarCromossomoAleatorio() {
        const size_t tamanho_cromossomo = itens.size();

        std::vector<bool> vetor_boleano = Aleatorio::gerarVetorBooleanoAleatorio(tamanho_cromossomo, 0.05);
        Cromossomo cromossomo;

        for (int i = 0; i < tamanho_cromossomo; ++i) {
                cromossomo.emplace_back(std::make_unique<GeneMochila>(vetor_boleano.at(i)));
        }

        return cromossomo;
}

int TipoMochila::calcularFitness(const Cromossomo &cromossomo) {
        int fitness = 0;
        float peso = 0;
        for (int i = 0; i < itens.size(); ++i) {
                GeneMochila *gene_mochila = static_cast<GeneMochila*>(cromossomo.at(i).get());
                if (gene_mochila->getValor()) {
                        fitness += itens.at(i).getUtilidade();
                        peso += itens.at(i).getPeso();
                }
        }

        if (peso >= 30) {
                fitness = fitness / (peso-29); // NOLINT(*-narrowing-conversions)
        }
        return fitness;
}






