//
// Created by gabriel on 5/14/24.
//

#ifndef GENE_H
#define GENE_H

#include <memory>

class IGene {
public:
    virtual void mutar() = 0;
    virtual std::shared_ptr<IGene> clone() const = 0;
    virtual bool equals(const IGene &rhs) const = 0;
    virtual ~IGene() = default;

    friend bool operator==(const IGene &lhs, const IGene &rhs) {
        return lhs.equals(rhs);
    }

    friend bool operator!=(const IGene &lhs, const IGene &rhs) {
        return !(lhs == rhs);
    }
};

#endif //GENE_H

