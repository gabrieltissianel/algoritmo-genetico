//
// Created by gabriel on 5/13/24.
//

#ifndef INDIVIDUO_H
#define INDIVIDUO_H
#include <iostream>
#include <memory>
#include <ostream>
#include <vector>

#include "ITipoIndividuo.h"
#include "../Gene/IGene.h"

using Populacao = std::vector<std::shared_ptr<Individuo>>;
using Cromossomo = std::vector<std::shared_ptr<IGene>>;

class Individuo final {
private:
    static std::shared_ptr<ITipoIndividuo> tipo_individuo;
    Cromossomo cromossomo;
    int fitness;
    bool semelhante;

public:

    Individuo();
    explicit Individuo(const Cromossomo &cromossomo);

    [[nodiscard]] Cromossomo &getCromossomo();
    [[nodiscard]] const Cromossomo &getCromossomo() const;
    [[nodiscard]] int getFitness() const;

    [[nodiscard]] bool ehSemelhante() const;
    void setEhSemelhante(bool semelhante);

    static void setTipoIndividuo(const std::shared_ptr<ITipoIndividuo> &tipo_individuo);

    friend std::ostream & operator<<(std::ostream &os, const Individuo &obj);

    friend bool operator<(const Individuo &lhs, const Individuo &rhs);
    friend bool operator<=(const Individuo &lhs, const Individuo &rhs);
    friend bool operator>(const Individuo &lhs, const Individuo &rhs);
    friend bool operator>=(const Individuo &lhs, const Individuo &rhs);

    friend bool operator==(const Individuo &lhs, const Individuo &rhs);
    friend bool operator!=(const Individuo &lhs, const Individuo &rhs);

    ~Individuo() = default;
};


#endif //INDIVIDUO_H
