//
// Created by gabriel on 5/14/24.
//

#ifndef GENEMOCHILA_H
#define GENEMOCHILA_H
#include "IGene.h"


class GeneMochila : public IGene {
private:
    bool valor;

public:
    explicit GeneMochila(bool valor);
    [[nodiscard]] bool getValor() const;
    void mutar() override;

    std::shared_ptr<IGene> clone() const override;
    bool equals(const IGene &rhs) const override;


};



#endif //GENEMOCHILA_H
