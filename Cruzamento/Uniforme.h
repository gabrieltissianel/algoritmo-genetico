//
// Created by gabriel on 6/13/24.
//

#ifndef UNIFORME_H
#define UNIFORME_H
#include "ICruzamento.h"


class Uniforme : public ICruzamento{
public:
    std::pair<std::shared_ptr<Individuo>, std::shared_ptr<Individuo>> executar(const Individuo& pai1, const Individuo& pai2) override;
};



#endif //UNIFORME_H
