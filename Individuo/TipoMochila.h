//
// Created by gabriel on 5/14/24.
//

#ifndef MOCHILA_H
#define MOCHILA_H

#include "Individuo.h"
#include "Item.h"

class TipoMochila : public ITipoIndividuo{
private:
    static std::vector<Item> itens;

public:
    Cromossomo gerarCromossomoAleatorio() override;
    int calcularFitness(const Cromossomo &cromossomo) override;
};



#endif //MOCHILA_H
