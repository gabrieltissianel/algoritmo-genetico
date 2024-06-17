//
// Created by gabriel on 6/16/24.
//

#ifndef TORNEIO_H
#define TORNEIO_H
#include "ISelecao.h"


class Torneio : public ISelecao{
public:
    std::shared_ptr<Individuo> executar(Populacao &pais) override;
};



#endif //TORNEIO_H
