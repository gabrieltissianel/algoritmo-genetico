//
// Created by gabriel on 6/5/24.
//

#ifndef ITIPOINDIVIDUO_H
#define ITIPOINDIVIDUO_H

class IGene;
class Individuo;

using Cromossomo = std::vector<std::shared_ptr<IGene>>;

class ITipoIndividuo {
public:
    virtual ~ITipoIndividuo() = default;

    virtual Cromossomo gerarCromossomoAleatorio() = 0;
    virtual int calcularFitness(const Cromossomo &cromossomo) = 0;
    // virtual bool equals(const Individuo &lhs, const Individuo &rhs) = 0;
};

#endif //ITIPOINDIVIDUO_H
