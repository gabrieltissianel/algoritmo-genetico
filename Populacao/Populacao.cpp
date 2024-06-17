//
// Created by gabriel on 6/6/24.
//

#include "Populacao.h"

Populacao::Populacao(int tamanho) {
    this->individuos = std::make_unique<VetorIndividuos>(tamanho);

    for (std::shared_ptr<Individuo> &individuo: individuos.get()) {
        individuo = std::make_shared<Individuo>();
    }

    this->geracao = 0;
}

Populacao::Populacao(std::unique_ptr<VetorIndividuos> individuos) {
    this->individuos = std::move(individuos);
    this->geracao = 0;
}

void Populacao::setIndividuos(std::unique_ptr<VetorIndividuos> individuos) {
    this->individuos = std::move(individuos);
    this->geracao++;
}

const VetorIndividuos &Populacao::getIndividuos() const {
    return *individuos;
}

void Populacao::marcarIndividuosRepetidos() const {
    const VetorIndividuos &vetor_individuos = *individuos;

    for (int i = 0; i < vetor_individuos.size(); ++i) {
        if (!(vetor_individuos.at(i)->ehSemelhante())) {
            for (int j = i + 1; j < vetor_individuos.size(); ++j) {
                if ( (*vetor_individuos.at(i)) == (*vetor_individuos.at(j)) ) {
                    vetor_individuos.at(j)->setEhSemelhante(true);
                }
            }
        }
    }
}


std::ostream & operator<<(std::ostream &os, const Populacao &obj) {
    os << "Geracao: " << obj.geracao;

    for ( std::shared_ptr<Individuo> &individuo: (*obj.individuos) ) {
        os << *individuo << std::endl;
    }

    return os;
}
