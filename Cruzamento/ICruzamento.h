//
// Created by gabriel on 5/14/24.
//

#ifndef ICRUZAMENTO_H
#define ICRUZAMENTO_H
#include <vector>
#include "../Individuo/Individuo.h"

using Populacao = std::vector<std::shared_ptr<Individuo>>;

class ICruzamento {
public:
virtual std::pair<std::shared_ptr<Individuo>, std::shared_ptr<Individuo>> executar(const Individuo& pai1, const Individuo& pai2) = 0;

};

#endif //ICRUZAMENTO_H
