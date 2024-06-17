//
// Created by gabriel on 5/13/24.
//

#include "AlgoritmoGenetico.h"

#include <algorithm>
#include <iostream>

#include "Cruzamento/Uniforme.h"
#include "Individuo/TipoMochila.h"
#include "MetodoPopulacional/PhiLambda.h"
#include "Selecao/Torneio.h"

AlgoritmoGenetico::AlgoritmoGenetico(SELECAO selecao, CRUZAMENTO cruzamento, METODOPOPULACIONAL metodo_populacional,
                                     TIPOINDIVIDUO tipo_individuo) {

    switch (selecao) {
        default:
            this->selecao = std::make_unique<Torneio>();
    }

    switch (cruzamento) {
        default:
            this->cruzamento = std::make_unique<Uniforme>();
    }

    switch (metodo_populacional) {
        default:
            this->metodo_populacional = std::make_unique<PhiLambda>();
    }

    switch (tipo_individuo) {
        default:
            Individuo::setTipoIndividuo(std::move(std::make_unique<TipoMochila>()));
    }

    this->pais = std::make_unique<Populacao>(100);
    for (auto &individuo: *pais) {
        individuo = std::make_shared<Individuo>();
    }

    this->filhos = std::make_unique<Populacao>(100);
}

void AlgoritmoGenetico::executar() {

    std::sort(pais->begin(), pais->end(), [](const std::shared_ptr<Individuo> &a, const std::shared_ptr<Individuo> &b) {
        return *a > *b; // Ordenação decrescente
    });

    for (auto &individuo: *pais) {
        std::cout << *individuo << endl;
    }

    for (int j = 0; j < 10000; ++j) {
        for (int i = 0; i < filhos->size()-1; i+=2) {
            std::shared_ptr<Individuo> pai1 = selecao->executar(*pais);
            std::shared_ptr<Individuo> pai2 = selecao->executar(*pais);

            filhos->at(i) = cruzamento->executar(*pai1, *pai2).first;
            filhos->at(i + 1) = cruzamento->executar(*pai1, *pai2).second;
        }

        pais = std::move(this->metodo_populacional->executar(pais, filhos, pais->size()));

        cout << *(pais->at(0)) << endl;

    }

    cout << "Resultado 100 gerações" << endl;
    for (auto &individuo: *pais) {
        std::cout << *individuo << endl;
    }
}
