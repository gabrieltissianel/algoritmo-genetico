//
// Created by gabriel on 5/14/24.
//

#include "GeneMochila.h"

GeneMochila::GeneMochila(bool valor)
    : valor(valor){
}

bool GeneMochila::getValor() const {
    return valor;
}

void GeneMochila::mutar() {
    valor = !valor;
}

std::shared_ptr<IGene> GeneMochila::clone() const {
    return std::make_shared<GeneMochila>(*this);
}

bool GeneMochila::equals(const IGene &rhs) const {
    if (this->getValor() == (static_cast<const GeneMochila&>(rhs)).getValor()) {
        return true;
    }
    return false;
}
