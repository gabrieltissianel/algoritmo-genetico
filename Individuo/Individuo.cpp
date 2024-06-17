#include "Individuo.h"

std::shared_ptr<ITipoIndividuo> Individuo::tipo_individuo = nullptr;

Individuo::Individuo()
    : cromossomo(tipo_individuo->gerarCromossomoAleatorio()), fitness(tipo_individuo->calcularFitness(this->cromossomo)){
}

Individuo::Individuo(const Cromossomo &cromossomo)
    : cromossomo(cromossomo), fitness(tipo_individuo->calcularFitness(cromossomo)){
}

Cromossomo& Individuo::getCromossomo() {
    return cromossomo;
}

const Cromossomo& Individuo::getCromossomo() const {
    return cromossomo;
}

int Individuo::getFitness() const {
    return fitness;
}

bool Individuo::ehSemelhante() const {
    return semelhante;
}

void Individuo::setEhSemelhante(bool semelhante) {
    this->semelhante = semelhante;
}

void Individuo::setTipoIndividuo(const std::shared_ptr<ITipoIndividuo> &tipo_individuo) {
    Individuo::tipo_individuo = tipo_individuo;
}

std::ostream & operator<<(std::ostream &os, const Individuo &obj) {
    return os << obj.fitness;
}

bool operator<(const Individuo &lhs, const Individuo &rhs) {
    if (lhs.fitness < rhs.fitness)
        return true;

    return false;
}

bool operator<=(const Individuo &lhs, const Individuo &rhs)  {
    return !(rhs < lhs);
}

bool operator>(const Individuo &lhs, const Individuo &rhs) {
    return rhs < lhs;
}

bool operator>=(const Individuo &lhs, const Individuo &rhs) {
    return !(lhs < rhs);
}

bool operator==(const Individuo &lhs, const Individuo &rhs) {
    if (lhs.getFitness() != rhs.getFitness()) {
        return false;
    }

    size_t tamanho_cromossomo = lhs.getCromossomo().size();
    const Cromossomo cromossomo1 = lhs.getCromossomo();
    const Cromossomo cromossomo2 = rhs.getCromossomo();

    for (int i = 0; i < tamanho_cromossomo; ++i) {
        if (cromossomo1.at(i) != cromossomo2.at(i)) {
            return false;
        }
    }

    return true;
}

bool operator!=(const Individuo &lhs, const Individuo &rhs) {
    return !(lhs == rhs);
}
