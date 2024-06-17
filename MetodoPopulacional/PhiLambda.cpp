//
// Created by gabriel on 6/12/24.
//

#include "PhiLambda.h"

#include <algorithm>

std::unique_ptr<Populacao> PhiLambda::executar(std::unique_ptr<Populacao> &pais, std::unique_ptr<Populacao> &filhos, int tamanho_nova_geracao) {
    std::unique_ptr<Populacao> nova_populacao = std::make_unique<Populacao>(tamanho_nova_geracao);

    std::sort(filhos->begin(), filhos->end(), [](const std::shared_ptr<Individuo> &a, const std::shared_ptr<Individuo> &b) {
        return *a > *b; // Ordenação decrescente
    });

    auto iterator_pais = pais->begin(), iterator_filhos = filhos->begin(), iterator_nova_populacao = nova_populacao.get()->begin();

    while (iterator_pais != pais->end() && iterator_filhos != filhos->end() && iterator_nova_populacao != nova_populacao->end()) {
        if ((**iterator_pais) > (**iterator_filhos)){
            *iterator_nova_populacao = *iterator_pais;
            ++iterator_pais;
        } else {
            *iterator_nova_populacao = *iterator_filhos;
            ++iterator_filhos;
        }
        ++iterator_nova_populacao;
    }

    while (iterator_pais != pais->end() && iterator_nova_populacao != nova_populacao->end()) {
        *iterator_nova_populacao = *iterator_pais;
        ++iterator_pais;
        ++iterator_nova_populacao;
    }

    while (iterator_filhos != filhos->end() && iterator_nova_populacao != nova_populacao->end()) {
        *iterator_nova_populacao = *iterator_filhos;
        ++iterator_filhos;
        ++iterator_nova_populacao;
    }

    return nova_populacao;
}
