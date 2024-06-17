//
// Created by gabriel on 6/12/24.
//

#ifndef PHILAMBDA_H
#define PHILAMBDA_H
#include "IMetodoPopulacional.h"
#include "../Individuo/Individuo.h"

class PhiLambda : public IMetodoPopulacional{
public:
    std::unique_ptr<Populacao> executar(std::unique_ptr<Populacao> &pais, std::unique_ptr<Populacao> &filhos, int tamanho_nova_geracao) override;
};



#endif //PHILAMBDA_H
