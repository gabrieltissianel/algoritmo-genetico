//
// Created by gabriel on 5/13/24.
//

#ifndef METODOPOPULACIONAL_H
#define METODOPOPULACIONAL_H
#include <memory>
#include <vector>
#include "../Individuo/Individuo.h"


class IMetodoPopulacional {
public:
    virtual std::unique_ptr<Populacao> executar(std::unique_ptr<Populacao> &pais, std::unique_ptr<Populacao> &filhos, int tamanho_nova_geracao) = 0;
};

#endif //METODOPOPULACIONAL_H
