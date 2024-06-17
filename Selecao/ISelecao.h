//
// Created by gabriel on 5/21/24.
//

#ifndef ISELECAO_H
#define ISELECAO_H
#include "../Individuo/Individuo.h"

class ISelecao {
public:
    virtual std::shared_ptr<Individuo> executar(Populacao &pais) = 0;
};

#endif //ISELECAO_H
