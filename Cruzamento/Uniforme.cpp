//
// Created by gabriel on 6/13/24.
//

#include "Uniforme.h"

#include "../Aleatorio.h"
#include "../Gene/GeneMochila.h"

std::pair<std::shared_ptr<Individuo>, std::shared_ptr<Individuo>> Uniforme::executar(const Individuo &pai1,
                                                                                      const Individuo &pai2) {
    size_t tamanho_cromossomo = pai1.getCromossomo().size();

    Cromossomo cromossomo1(tamanho_cromossomo);
    Cromossomo cromossomo2(tamanho_cromossomo);

    for (int i = 0; i < tamanho_cromossomo; ++i) {
        if (Aleatorio::gerarBooleanoAleatorio(0.5)) {
            cromossomo1.at(i) = pai1.getCromossomo().at(i)->clone();
            cromossomo2.at(i) = pai2.getCromossomo().at(i)->clone();
        } else {
            cromossomo2.at(i) = pai1.getCromossomo().at(i)->clone();
            cromossomo1.at(i) = pai2.getCromossomo().at(i)->clone();
        }
    }

    return {std::make_shared<Individuo>(cromossomo1), std::make_shared<Individuo>(cromossomo2)};

}
